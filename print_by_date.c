#include "shared_helper.h"

#define DATE_VAR "--date"

int main(int argc, char* argv[]) 
{
	char *date, *key;
	DataByDate* node;

	if (strcmp(argv[1],DATE_VAR)==0) 
	{
		date=argv[2];
		key=argv[4];
	}
	else
	{
		date=argv[4];
		key=argv[2];
	}

	loadDB();

	for (int i = 0; i < locInArr; i++)
	{
		node = getNodeByDate(date, arr_country[i].HeadDates);

		if (node)
			printf("%s: %s\n", arr_country[i].country_name, getValueByKey(key,node));
	}	

	freeDB();
	return 0;
}