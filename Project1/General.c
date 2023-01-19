#include "General.h"

char* toLowerStr(char* str)
{
	int i;
	for (i = 0;str[i]!='\0';i++)
	{
		if (isupper(str[i]))
		{
			str[i] = tolower(str[i]);
		}
	}
	return str;
}

int checkStr(char* str)
{
	int i;
	for (i = 0;str[i]!='\0';i++)
		if (islower(str[i]) == 0 && (str[i] != ' '))
			return 0;
	return 1;
}

int checkInt(char* str)
{
	int i;
	for (i = 0;str[i]!='\0';i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return 0;
		}
	}
	return 1;
}

void printError(client* customer)
{
	switch (customer->error[0])
	{
	case 1:
		fputs(" Error in first name <-->   ", stdout);
		break;
	case 2:
		fputs(" Error in second name <-->  ", stdout);
		break;
	case 3:
		fputs(" Error in ID number <-->    ", stdout);
		break;
	case 4:
		fputs(" Error in phone number <--> ", stdout);
		break;
	case 5:
		fputs(" Error in debt <--> \t", stdout);
		break;
	case 6:
		fputs(" Error in date <--> \t", stdout);
		break;
	case 7:
		fputs(" ID and name don't match <--> ", stdout);
	default:
		break;
	}
}

char* loweringSpace(char* str)
{
	int spaceCounter = 0, i=0;
	while (str[i] == ' ')
	{
		spaceCounter++;
		i++;
	}

	for (i = 0;str[i+spaceCounter]!='\0';i++)
	{
		str[i] = str[i + spaceCounter];
	}
	str[i] = 0;
	return str;
}

int checkDebt(char* debt)
{
	int i;
	for (i = 0;debt[i]!='\0';i++)
		if (!((debt[i] > 47 && debt[i] < 58) || (debt[i] == '-') || (debt[i] == '.')))
			return 0;
	return 1;
}

void removesSpaceFromEnd(char* str)
{
	int i;
	for (i = strlen(str);i > 0 && str[i - 1] == ' ';i--)
	{
		str[i - 1] = '\0';
	}
} 

void printErrorMessage()
{
	fputs("The system had an error receiving the data, please try again: ", stdout);
}

void putErrorInTheStruct(client* customer, int errorLocation)
{
	customer->error[0] = errorLocation;
	customer->error[errorLocation] = 1;
}

void printTitleTable()
{
	puts("\n\n\t|====================|================|=================|=================|============|============|");
	puts("\t|    |  first name   |   second name  |    ID number    |   phone number  |     debt   |    date    |");
	puts("\t|====================|================|=================|=================|============|============|");

}

void print(client* customer, int customerNumber)
{
	printf("\t|%3d.| ", customerNumber);
	printf("%-14s| ", customer->firstName);
	printf("%-14s |", customer->lastName);
	printf("%13s    | ", customer->IDNumber);
	printf("%13s   | ", customer->phoneNumber);
	printf("%9.2f  | ", customer->debt);
	printf("%02d/%02d/%04d |\n", customer->dateOfOperation.day, customer->dateOfOperation.month, customer->dateOfOperation.year);
}

void freeStruct(client* custmer)
{
	free(custmer->firstName);
	free(custmer->lastName);
	free(custmer->IDNumber);
	free(custmer->phoneNumber);
	free(custmer);
}