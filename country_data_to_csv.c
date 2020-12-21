#include "shared_helper.h"

#define PATH "./countries/"

int main(int argc, char* argv[]) 
{
	char* country = argv[2];
    char newFileName[100] = PATH;
	FILE* csvFptr;
    int countryIndex;
    DataByDate* node;

    loadDB();    
    countryIndex = getCounteryIndex(country);

    if (countryIndex != -1) 
    {
        strcat(newFileName, country);
        strcat(newFileName,".csv");

        csvFptr = fopen(newFileName,"a+");
        fprintf(csvFptr,"%s,%s,%s,%s,%s\n","Date","Confirmed","Deaths","Recovered","Active");

        node = arr_country[countryIndex].HeadDates;

        while (node) 
        {
            fprintf(csvFptr,"%s,%s,%s,%s,%s\n",node->Date,node->Confirmed,node->Deaths,node->Recovered,node->Active);
            node = node->next;
        }

        fclose(csvFptr);
    }   
	
    freeDB(); 
    return 0;
}