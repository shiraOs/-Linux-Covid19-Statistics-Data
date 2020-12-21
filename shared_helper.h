#define  _GNU_SOURCE

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>

typedef struct DataByDate
{
    char Date[50];
    char Confirmed[50];
    char Deaths[50];
    char Recovered[50];
    char Active[50];

    struct DataByDate* next;
    
}DataByDate;

typedef struct Country
{
    char country_name[100];
    DataByDate* HeadDates;
    DataByDate* TailDates;
    int maxDeaths;
    int maxActive;
    int maxRecovered;
    int maxConfirmed;  
    int listSize; 
}Country;

Country arr_country[250];
int locInArr = 0;

void loadDB();
void freeDB();
void updateMax(char* line,int* maxToUpdate);
void AddToEndOfList(DataByDate* cellToAdd);

DataByDate* getCountryInfo (char* countryName);
DataByDate* getNodeByDate (char* Date, DataByDate* ListHead);
char* getValueByKey (char* key, DataByDate* node);
int getCounteryIndex (char* countryName);
int getMaxKeyByCountry(char* key, char* countryName);