#include "Select.h"

int compareFirstName(client* customer, void* query)
{
	return strcmp(customer->firstName, (char*)query);
}
int compareLastName(client* customer, void* query)
{
	return strcmp(customer->lastName, (char*)query);
}
int compareDebt(client* customer, void* query)
{
	return customer->debt - *(float*)query;
}
int compareIDNumber(client* customer, void* query)
{
	return strcmp(customer->IDNumber, (char*)query);
}
int comparePhoneNumber(client* customer, void* query)
{
	return strcmp(customer->phoneNumber, (char*)query);
}
int comperDate(client* customer, void* query)
{
	float day, month, year;
	day = atof(strtok((char*)query, "/"));
	month = atof(strtok(NULL, "/"));
	year = atof(strtok(NULL, "/"));
	if (customer->dateOfOperation.year - year)
	{
		return customer->dateOfOperation.year - year;
	}
	if (customer->dateOfOperation.month - month)
	{
		return customer->dateOfOperation.month - month;
	}
	return customer->dateOfOperation.day - day;
}



int big(int (*compare)(client*, void*), char* query, client* customer)
{
	return compare(customer, (void*)query) > 0;
}
int small(int (*compare)(client*, void*), char* query, client* customer)
{
	return compare(customer, (void*)query) < 0;
}
int different(int (*compare)(client*, void*), char* query, client* customer)
{
	return compare(customer, (void*)query) != 0;
}
int equal(int (*compare)(client*, void*), char* query, client* customer)
{
	return compare(customer, (void*)query) == 0;
}


int printSelect(int (*compare)(client*, void*), char* query, int parameter, manager* customerList)
{
	int (*param[])(void*, char*, client*) = { big ,small ,different ,equal };
	int flagBadCustomers = 0;
	client* customer = customerList->head;
	fputs("\n\t\t\t\t\tnormal customers:", stdout);
	printTitleTable();
	int counterNormal = 0, incorrectCounter=0;
	while (customer)
	{
		if (param[parameter](compare, query, customer)) 
		{
			if (customer->error[0] == 0) 
			{
				if (counterNormal > 0)
				{
					puts("\t|--------------------|----------------|-----------------|-----------------|------------|------------|");
				}
				counterNormal++;
				print(customer, counterNormal);
			}
			else
			{
				flagBadCustomers = 1;
			}
		}
		customer = customer->next;
	}
	puts("\t|====================|================|=================|=================|============|============|");

	if (flagBadCustomers == 1)
	{
		customer = customerList->head;
		fputs("\n\t\t\t\t\twrong customers:", stdout);
		printTitleTable();
		while (customer)
		{
			if (param[parameter](compare, query, customer) && customer->error[0] != 0)
			{
				if (incorrectCounter > 0)
				{
					puts("\t|--------------------|----------------|-----------------|-----------------|------------|------------|");
				}
				incorrectCounter++;
				print(customer, incorrectCounter);
			}
			customer = customer->next;
		}
		puts("\t|====================|================|=================|=================|============|============|");
	}

	return counterNormal+ incorrectCounter;
}

void selectionQuery(char* line, manager* customerList)
{
	int (*ComparePtrArr[])(client*, void*) = { compareFirstName ,compareLastName ,compareDebt ,compareIDNumber ,comparePhoneNumber };
	char* query = NULL;
	int check, i, j;
	char* field[] = { "first name", "second name", "debt", "id", "phone", "date" };
	char* parameter[] = { ">", "<", "!=", "=" };
	char* param;

	for (j = 0;j < 6;j++)
	{
		query = strstr(line, field[j]);
		if (query != NULL)
		{
			break;
		}
	}
	if (query == NULL) 
	{
		puts("A valid field was not entered for a select query\n");
		return;
	}

	for (i = 0;i < 4;i++)
	{
		param = strstr(query, parameter[i]);
		if (param != NULL)
		{
			break;
		}
	}
	if (param == NULL)
	{
		puts("A valid parameter was not entered for a select query\n");
		return;
	}

	param += strlen(parameter[i]);
	param = loweringSpace(param);
	removesSpaceFromEnd(param);

	int numberPrints = printSelect(ComparePtrArr[j], param, i, customerList);

	printf("\nA total of %d customers were printed whose %s is %s %s.\n", numberPrints, field[j], parameter[i], param);
	puts("********************************************************************\n");
}