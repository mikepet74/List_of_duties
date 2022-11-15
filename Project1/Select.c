#include "Select.h"

void selectionQuery(char* line, manager* customerList)
{
	char* first = "first name", * second = "second name", * debt = "debt", * id = "id", * phone = "phone", * date = "date";
	int check;
	if ((check = findSubStr(line, first)) != NO_SUB_STR_fOUND)
	{
		selectFirstName(line, customerList);
	}
	else if ((check = findSubStr(line, second)) != NO_SUB_STR_fOUND)
	{
		selectLastName(line, customerList);
	}
	else if ((check = findSubStr(line, debt)) != NO_SUB_STR_fOUND)
	{
		selectDebt(line, customerList);
	}
	else if ((check = findSubStr(line, id)) != NO_SUB_STR_fOUND)
	{
		selectIDNumber(line, customerList);
	}
	else if ((check = findSubStr(line, phone)) != NO_SUB_STR_fOUND)
	{
		selectPhoneNumber(line, customerList);
	}
	else if ((check = findSubStr(line, date)) != NO_SUB_STR_fOUND)
	{
		selectDate(line, customerList);
	}
	else
	{
		printf("A valid field was not entered for a select query\n\n");
	}
}

void selectFirstName(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0;
	char* token;
	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//different first name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->firstName, token)!=0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose first name is not %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//Same first name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->firstName, token)==0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose first name is %s were printed.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//A large first name value
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->firstName, token) > 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose first name value is greater than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A small first name value
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->firstName, token) < 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose first name value is less than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}

void selectDebt(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0;
	float debt = 0;
	char* token;
	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//different debt
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		debt = (float)atof(token);
		printTitleTable();
		while (customer)
		{
			if (customer->debt != debt)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose debt is different from %.2f were printed.\n", customerNumber, debt);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//same debt
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		debt = (float)atof(token);
		printTitleTable();
		while (customer)
		{
			if (customer->debt == debt)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose debt is equal to %.2f.\n", customerNumber, debt);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A bigger debt
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		debt = (float)atof(token);
		printTitleTable();
		while (customer)
		{
			if (customer->debt > debt)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose debt is less than %.2f were printed.\n", customerNumber, debt);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//Less debt
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		debt = (float)atof(token);
		printTitleTable();
		while (customer)
		{
			if (customer->debt < debt)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose debt is greater than %.2f were printed.\n", customerNumber, debt);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}

void selectDate(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0, days = 0, years, months;
	char* token;

	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//different date
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		token = strtok(token, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		days = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		months = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		years = atoi(token);
		printTitleTable();
		while (customer)
		{
			if (customer->dateOfOperation.year != years || customer->dateOfOperation.month != months || customer->dateOfOperation.day != days)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose date is different from %02d/%02d/%04d were printed.\n", customerNumber, days, months, years);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//same date
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		token = strtok(token, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		days = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		months = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		years = atoi(token);
		printTitleTable();
		while (customer)
		{
			if (customer->dateOfOperation.year == years && customer->dateOfOperation.month == months && customer->dateOfOperation.day == days)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose date is equal to %02d/%02d/%04d.\n", customerNumber, days, months, years);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A bigger date
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		token = strtok(token, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		days = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		months = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		years = atoi(token);
		printTitleTable();
		while (customer)
		{
			if ((customer->dateOfOperation.year < years || (customer->dateOfOperation.year == years && customer->dateOfOperation.month < months) || (customer->dateOfOperation.year == years && customer->dateOfOperation.month == months && customer->dateOfOperation.day < days)))
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose date is less than %02d/%02d/%04d were printed.\n", customerNumber, days, months, years);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//Less date
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		token = strtok(token, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		days = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		months = atoi(token);

		token = strtok(NULL, "/");
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The date should contain only digits.\n\n");
			return;
		}
		years = atoi(token);
		printTitleTable();
		while (customer)
		{
			if (customer->dateOfOperation.year > years || (customer->dateOfOperation.year == years && customer->dateOfOperation.month > months) || (customer->dateOfOperation.year == years && customer->dateOfOperation.month == months && customer->dateOfOperation.day > days))
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose date is greater than %02d/%02d/%04d were printed.\n", customerNumber, days, months, years);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}

void selectIDNumber(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0, customerError = 0;
	char* token;
	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//Different ID
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The ID number should contain only digits.\n\n");
			return;
		}

		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->IDNumber, token)!=0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose ID number is not %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//Same ID
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The ID number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->IDNumber, token)==0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose ID number is %s were printed.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//A larger ID number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The ID number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->IDNumber, token) > 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose ID number value is greater than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A smaller ID number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The ID number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->IDNumber, token) < 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose ID number value is less than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}

void selectPhoneNumber(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0;
	char* token;
	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//Different phone number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The phone number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->phoneNumber, token)!=0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose phone number is not %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//Same phone number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The phone number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->phoneNumber, token)==0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose phone number is %s were printed.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//A smaller phone number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The phone number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->phoneNumber, token) > 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose phone number value is greater than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A larger phone number
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkInt(token))
		{
			printf("The phone number should contain only digits.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->phoneNumber, token) < 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose phone number value is less than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}

void selectLastName(char* line, manager* customerList)
{
	client* customer = customerList->head;
	int parameterLocation, customerNumber = 0;
	char* token = { "_" };
	if ((parameterLocation = findSubStr(line, "!=")) != NO_SUB_STR_fOUND)//different second name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->lastName, token)!=0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose second name is not %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "=")) != NO_SUB_STR_fOUND)//Same second name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->lastName, token)==0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers whose second name is %s were printed.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, ">")) != NO_SUB_STR_fOUND)//A smaller second name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->lastName, token) > 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose second name value is greater than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else if ((parameterLocation = findSubStr(line, "<")) != NO_SUB_STR_fOUND)//A larger second name
	{
		token = line + parameterLocation + 1;
		token = loweringSpace(token);
		if (*token == '\0')
		{
			printf("No parameter was entered for comparison\n\n");
			return;
		}
		if (!checkStr(token))
		{
			printf("The name should contain only letters.\n\n");
			return;
		}
		printTitleTable();
		while (customer)
		{
			if (strcmp(customer->lastName, token) < 0)
			{
				if (customerNumber > 0)
				{
					printf("\t|--------------------|----------------|-----------------|-----------------|------------|------------|\n");
				}
				customerNumber++;
				print(customer, customerNumber);
			}
			customer = customer->next;
		}
		printf("\t|====================|================|=================|=================|============|============|\n");
		printf("\nA total of %d customers were printed whose second name value is less than %s.\n", customerNumber, token);
		printf("********************************************************************\n\n");
	}
	else
	{
		printf("A valid operator was not entered, please try again\n\n");
	}
}