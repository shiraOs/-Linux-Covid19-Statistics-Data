#include "shared_helper.h"

void loadDB()
{
    char Active[50], Deaths[50], Date[200], Confirm[50], Recovered[50];	
	char* countryName, *key;
	DIR *d;
	FILE *fptr;
	struct dirent *dir;
	char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int counter;
    DataByDate* newNode;	

	d = opendir("./countries");
	if (d)
    {
	    while ((dir = readdir(d)) != NULL) 
        {
		    char desDir[200] = "./countries/";
		    strcat(desDir,dir->d_name);
		    countryName = strtok(dir->d_name, "."); 
		    fptr = fopen(desDir,"r");
            counter = 0;
        
		    if (fptr && countryName) 
            {
                strcpy(arr_country[locInArr].country_name, countryName);
                arr_country[locInArr].maxActive = 0;
                arr_country[locInArr].maxConfirmed = 0;
                arr_country[locInArr].maxDeaths = 0;
                arr_country[locInArr].maxRecovered = 0;
                arr_country[locInArr].listSize = 0;
                arr_country[locInArr].HeadDates = NULL;
                arr_country[locInArr].TailDates = NULL;

			    while ((read = getline(&line, &len, fptr)) != -1)
                {
                    key = strtok(line, ":");

                    if(strcmp(key,"Active") == 0)
                    {                        
                        strcpy(Active, strtok(NULL, "\n"));
                        updateMax(Active,&(arr_country[locInArr].maxActive));
                    }
                    else if(strcmp(key,"Recovered") == 0)
                    {                        
                        strcpy(Recovered, strtok(NULL, "\n"));
                        updateMax(Recovered,&(arr_country[locInArr].maxRecovered));
                    }
                    else if(strcmp(key,"Deaths") == 0)
                    {
                        strcpy(Deaths, strtok(NULL, "\n")); 
                        updateMax(Deaths,&(arr_country[locInArr].maxDeaths));
                    }
                    else if(strcmp(key,"Confirmed") == 0)
                    {
                        strcpy(Confirm, strtok(NULL, "\n"));  
                        updateMax(Confirm,&(arr_country[locInArr].maxConfirmed));  
                    }
                    else if(strcmp(key,"Date") == 0)
                    { 
                        strcpy(Date, strtok(NULL, "\n")); 
                        newNode = (DataByDate*)malloc(sizeof(DataByDate));  
                        newNode->next = NULL;                        
                        strcpy(newNode->Active, Active);
                        strcpy(newNode->Date, Date); 
                        strcpy(newNode->Recovered, Recovered); 
                        strcpy(newNode->Deaths, Deaths); 
                        strcpy(newNode->Confirmed, Confirm);
                        AddToEndOfList(newNode);   
                        counter++;      
                    }         
                }
    		}

            arr_country[locInArr].listSize = counter;
			locInArr++;
			fclose(fptr);
		}
	}
}

int getCounteryIndex(char* countryName)
{
    for (int i=0; i<locInArr;i++) 
        if (strcmp(countryName,arr_country[i].country_name) == 0)
            return i;
    return -1;            
}


char* getValueByKey(char* key, DataByDate* node)
{
    if(strcmp(key,"Active") == 0)
    {                        
        return node->Active;
    }
    else if(strcmp(key,"Recovered") == 0)
    {                        
        return node->Recovered;
    }
    else if(strcmp(key,"Deaths") == 0)
    {
        return node->Deaths;       
    }
    else if(strcmp(key,"Confirmed") == 0)
    {
        return node->Confirmed;  
    }
    return NULL;
}

DataByDate* getNodeByDate(char* Date, DataByDate* ListHead)
{
    DataByDate *cur;
    cur = ListHead;

    while (cur)
    {
        if (strstr(cur->Date, Date)) 
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

void freeDB() 
{
    DataByDate *temp,*cur;

    for (int i = 0; i < locInArr; i++) 
    {
        cur = arr_country[i].HeadDates;

        while (cur) 
        {
            temp = cur->next;
            free(cur);
            cur = temp;
        }
    }    
}

DataByDate* getCountryInfo(char* countryName) 
{
    for (int i=0; i<locInArr;i++)
    {
        if (strcmp(countryName,arr_country[i].country_name) == 0)
            return arr_country[i].HeadDates;        
    }
    return NULL;
}

void AddToEndOfList(DataByDate* cellToAdd)
{
    if (arr_country[locInArr].HeadDates == NULL)
    {        
        arr_country[locInArr].HeadDates = cellToAdd;
        arr_country[locInArr].TailDates = cellToAdd;
    }
    else 
    {
	    arr_country[locInArr].TailDates->next = cellToAdd;
	    arr_country[locInArr].TailDates = cellToAdd;
    }
}

void updateMax(char* line,int* maxToUpdate) 
{
    int value;  
    value = atoi(line);

    if (*maxToUpdate < value)
    {
        *maxToUpdate = value;
    }
}

int getMaxKeyByCountry(char* key,char* countryName) 
{
    int i;

    for (i = 0; i < locInArr; i++) 
        if (strcmp(countryName,arr_country[i].country_name) == 0)
            break;        
    

    if (i == locInArr)
        return 0;

    if(strcmp(key,"Active") == 0)
    {                        
       return arr_country[i].maxActive;
    }
    else if(strcmp(key,"Recovered") == 0)
    {                        
        return  arr_country[i].maxRecovered;
    }
    else if(strcmp(key,"Deaths") == 0)
    {
        return  arr_country[i].maxDeaths;   
    }
    else if(strcmp(key,"Confirmed") == 0)
    {
        return  arr_country[i].maxConfirmed;
    }

    return 0;
    
}