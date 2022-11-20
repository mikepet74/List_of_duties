#include "General.h"

int findSubStr(char* str, char* subStr)
{
	int i, j, lenStr = strlen(str), lenSubStr = strlen(subStr);
	for (i = 0;i < lenStr;i++)
	{
		for (j = 0;j < lenSubStr;j++)
		{
			if (str[i + j] != subStr[j]) {
				j = -1;
				break;
			}
		}
		if (j != -1)
		{
			return i + j - 1;
		}
	}
	return NO_SUB_STR_fOUND;
}

char* toLowerStr(char* str)
{
	int i, lenStr = strlen(str);
	for (i = 0;i < lenStr;i++)
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
	int i, lenStr = strlen(str);
	for (i = 0;i < lenStr;i++)
		if (islower(str[i]) == 0 && (str[i] != ' '))
			return 0;
	return 1;
}

int checkInt(char* str)
{
	int i, lenStr = strlen(str);
	for (i = 0;i < lenStr;i++)
	{
		if (isdigit(str[i]) == 0)
		{
			return 0;
		}
	}
	return 1;
}

void printError(client* custmer)
{
	switch (custmer->error[0])
	{
	case 1:
		printf(" Error in first name <-->   ");
		break;
	case 2:
		printf(" Error in second name <-->  ");
		break;
	case 3:
		printf(" Error in ID number <-->    ");
		break;
	case 4:
		printf(" Error in phone number <--> ");
		break;
	case 5:
		printf(" Error in debt <--> \t");
		break;
	case 6:
		printf(" Error in date <--> \t");
		break;
	case 7:
		printf(" ID and name don't match <--> ");
	default:
		break;
	}
}

char* loweringSpace(char* str)
{
	int spaceCounter = 0, i;
	while (*str == ' ')
	{
		spaceCounter++;
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
	for (i = 0;i < strlen(debt);i++)
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
	printf("The system had an error receiving the data, please try again: ");
}

void putErrorInTheStruct(client* custmer, int errorLocation)
{
	custmer->error[0] = errorLocation;
	custmer->error[errorLocation] = 1;
}

void printTitleTable()
{
	printf("\n\n\t|====================|================|=================|=================|============|============|");
	printf("\n\t|    |  first name   |   second name  |    ID number    |   phone number  |     debt   |    date    |\n");
	printf("\t|====================|================|=================|=================|============|============|\n");

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