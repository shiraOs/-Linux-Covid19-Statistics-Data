#include "shared_helper.h"

#define COUNTRY_VAR "--country"

int main(int argc, char* argv[]) 
{
	char* country, *key, *numberKey;
    DataByDate* node;
    int countryIndex, number, maxKey;
    float j, space;

	if (strcmp(argv[1], COUNTRY_VAR) == 0)
	{
		country = argv[2];
		key = argv[4];
	}
	else
	{
		country = argv[4];
		key = argv[2];
	}

    loadDB();
    countryIndex = getCounteryIndex(country);

    if (countryIndex != -1) 
    {
        node = arr_country[countryIndex].HeadDates;
        maxKey = getMaxKeyByCountry(key, country);        

        while (node)
        {
           numberKey = getValueByKey(key, node);
           number = atoi(numberKey);
           space = (float)((float)number/(float)maxKey)*80.;

           for (j = 0; j < space; j++)
           {
              printf(" ");
           }

           printf("%d\n", number);
           node = node->next;
        }
    }

    freeDB();
    return 0;
}