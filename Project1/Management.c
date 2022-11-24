#include "Management.h"

FILE* openFile(FILE* filePointer, char* nameOfFile)
{
	int CheckingAllocatedDynamicMemory = 0;
	FILE* read = stdin;
	do
	{
		if ((filePointer = fopen(nameOfFile, "r+t")) == NULL)//Checking if the opening failed
		{
			if (CheckingAllocatedDynamicMemory)
			{
				free(nameOfFile);
			}

			puts("The file for reading is not opened");
			fputs("Enter a file name to read: ", stdout);

			while ((nameOfFile = readLine(read)) == NULL)//A loop to receive another file name
			{
				printErrorMessage();
			}

			CheckingAllocatedDynamicMemory = 1;
		}
	} while (filePointer == NULL);

	if (CheckingAllocatedDynamicMemory)
	{
		free(nameOfFile);
	}

	return filePointer;//returning the pointer
}

void readingFile(FILE* filePointer, manager* customerList)
{
	char* lineFromFile = NULL;
	char endOfFileCheck;
	int customerIndexExists, lineNumber = 0, i;

	while ((endOfFileCheck = getc(filePointer)) != EOF)//A loop that ran until the end of the file
	{
		fseek(filePointer, -1, SEEK_CUR);

		lineNumber++;

		if ((lineFromFile = readLine(filePointer)) == NULL)
		{
			printf("The system failed to read line %d from the file", lineNumber);
			continue;
		}

		client* tempCustomer = creatingClient(lineFromFile);//Dividing the row into structure fields

		if (tempCustomer == NULL)
		{
			continue;
		}

		//Checking if he is an existing customer, if so add a new customer otherwise merge customers
		customerIndexExists = checkingClientExists(*tempCustomer, customerList);
		if (customerIndexExists == CUSTOMER_NUMBER_NOT_EXIST)
		{
			addNewCustomer(customerList, tempCustomer);
		}
		else
		{
			client* clientTemp = customerList->head;
			for (i = 0;i < customerIndexExists;i++)
			{
				clientTemp = clientTemp->next;
			}
			if ((strcmp(clientTemp->firstName, tempCustomer->firstName)!=0) || (strcmp(clientTemp->lastName, tempCustomer->lastName)!=0))
			{
				addNewCustomer(customerList, tempCustomer);
				putErrorInTheStruct(tempCustomer, 7);
			}
			else
			{
				clientMerger(customerList, tempCustomer, customerIndexExists);
			}
		}

		free(lineFromFile);
	}
}

client* creatingClient(char* line)
{
	int date, i, iDebt;
	float fDebt;
	client* temporaryClientStructure = (client*)malloc(sizeof(client));

	if (temporaryClientStructure == NULL)
	{
		fputs("The system failed to allocate memory for the client", stdout);
	}
	else
	{
		for (i = 0;i < 8;i++)//Reset the error array
		{
			temporaryClientStructure->error[i] = 0;
		}

		temporaryClientStructure->debt = 0;

		char* token;
		//first name:
		token = strtok(line, ",");
		if (!checkStr(token))//Checking that the name contains only letters
		{
			putErrorInTheStruct(temporaryClientStructure, 1);
		}

		temporaryClientStructure->firstName = _strdup(token);
		if (temporaryClientStructure->firstName == NULL)
		{
			free(temporaryClientStructure);
			return NULL;
		}

		//second name:
		token = strtok(NULL, ",");
		if (!checkStr(token))//Checking that the name contains only letters
		{
			putErrorInTheStruct(temporaryClientStructure, 2);
		}

		temporaryClientStructure->lastName = _strdup(token);
		if (temporaryClientStructure->lastName == NULL)
		{
			free(temporaryClientStructure->firstName);
			free(temporaryClientStructure);
			return NULL;
		}

		//ID munber:
		token = strtok(NULL, ",");
		if (!checkInt(token) || strlen(token) != 9)//Checking that the Id contains only digits and is the correct size
		{
			putErrorInTheStruct(temporaryClientStructure, 3);
		}

		temporaryClientStructure->IDNumber = _strdup(token);
		if (temporaryClientStructure->IDNumber == NULL)
		{
			free(temporaryClientStructure->firstName);
			free(temporaryClientStructure->lastName);
			free(temporaryClientStructure);
			return NULL;
		}

		//phone number:
		token = strtok(NULL, ",");
		if (!checkInt(token) || strlen(token) != 10)//Checking that the phone contains only digitsand is the correct size
		{
			putErrorInTheStruct(temporaryClientStructure, 4);
		}

		temporaryClientStructure->phoneNumber = _strdup(token);
		if (temporaryClientStructure->phoneNumber == NULL)
		{
			free(temporaryClientStructure->firstName);
			free(temporaryClientStructure->lastName);
			free(temporaryClientStructure->IDNumber);
			free(temporaryClientStructure);
			return NULL;
		}

		//debt:
		token = strtok(NULL, ",");
		if (!atof(token) && strcmp(token, "0")!=0 || !checkDebt(token))
		{
			putErrorInTheStruct(temporaryClientStructure, 5);
		}
		else
		{
			fDebt = (float)atof(token) * 100;
			iDebt = (int)fDebt;
			temporaryClientStructure->debt = (float)iDebt / 100;
		}

		//date:
			//day - 
		token = strtok(NULL, "/");
		if (token == NULL)
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
			temporaryClientStructure->dateOfOperation.day = 0;
			temporaryClientStructure->next = NULL;
			return temporaryClientStructure;
		}
		date = atoi(token);
		if (date < 1 || date>31)//Checking that the dates are correct
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
		}
		temporaryClientStructure->dateOfOperation.day = date;

		//month - 
		token = strtok(NULL, "/");
		if (token == NULL)
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
			temporaryClientStructure->dateOfOperation.month = 0;
			temporaryClientStructure->next = NULL;
			return temporaryClientStructure;
		}
		date = atoi(token);
		if (date < 1 || date>12)//Checking that the dates are correct
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
		}
		temporaryClientStructure->dateOfOperation.month = date;

		//years - 
		token = strtok(NULL, "/");
		if (token == NULL)
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
			temporaryClientStructure->dateOfOperation.year = 0;
			temporaryClientStructure->next = NULL;
			return temporaryClientStructure;
		}
		date = atoi(token);
		if (temporaryClientStructure->dateOfOperation.year < 1000)//Checking that the dates are correct
		{
			putErrorInTheStruct(temporaryClientStructure, 6);
		}
		temporaryClientStructure->dateOfOperation.year = date;

		//next:
		temporaryClientStructure->next = NULL;
	}

	return temporaryClientStructure;
}

void printList(manager customerList)
{
	client* customer = customerList.head;
	int normalCustomers = 0, customerError = 0;

	printTitleTable();

	while (customer != NULL)//A loop that prints the valid customers.
	{
		if (customer->error[0] == 0)
		{
			if (normalCustomers > 0)
			{
				puts("\t|--------------------|----------------|-----------------|-----------------|------------|------------|");
			}
			normalCustomers++;
			print(customer, normalCustomers);
		}
		customer = customer->next;
	}

	puts("\t|====================|================|=================|=================|============|============|");

	if (normalCustomers == customerList.amountCustomers)
	{
		printf("   A total of %d customers\n\n", normalCustomers);//Print the number of customers
	}

	else
	{
		puts("\nCustomers with incorrect fields:");
		customer = customerList.head;
		while (customer != NULL)//A loop that prints out the invalid customers.
		{
			if (customer->error[0] != 0)
			{
				customerError++;
				printError(customer);
				print(customer, customerError);
			}
			customer = customer->next;
		}

		printf("\n  Normal customers: %d, abnormal customers: %d, total customers: %d.\n\n", normalCustomers, customerError, normalCustomers + customerError);
		puts("********************************************************************\n");
	}
}

void freeListStructs(manager customerList)
{
	client* customer;
	while (customerList.head)
	{
		customer = customerList.head;
		customerList.head = customer->next;
		freeStruct(customer);
	}
}

void queries(char* query, manager* customerList, FILE* filePointer)
{
	char* token;
	token = strtok(query, " ");
	if (token != NULL)
	{
		if (strcmp(token, "select")==0)
		{
			selectionQuery(token + 7, customerList);
		}
		else if (strcmp(token, "set")==0)
		{
			setQuery(token + 4, customerList, filePointer);
		}
		else if (strcmp(token, "print")==0)
		{
			printList(*customerList);
		}
		else if (strcmp(token, "quit")!=0)
		{
			puts("The query failed, a valid keyword was not entered, please try again\n");
		}
	}
	else
	{
		puts("The query failed, a valid keyword was not entered, please try again\n");
	}
}

char* readLine(FILE* read)
{
	char* input = NULL, * tempInput;
	char tempbuf[CHUNK] = { '\0' };
	int inputLength = 0, tempLength = 0;

	do
	{
		fgets(tempbuf, CHUNK, read);//Size ten absorption
		tempLength = (int)strlen(tempbuf);//Checking how much was absorbed

		if ((tempInput = (char*)realloc(input, inputLength + tempLength + 1)) == NULL)//Increasing the main string by the received beat
		{
			return input;
		}
		input = tempInput;

		strcpy(input + inputLength, tempbuf);//String concatenation
		inputLength += tempLength;//A summary of everything that has been absorbed so far

	} while (tempLength == CHUNK - 1 && tempbuf[CHUNK - 2] != '\n');

	if (input[strlen(input) - 1] == '\n')
	{
		input[strlen(input) - 1] = '\0';
	}
	else
	{
		input[strlen(input)] = '\0';
	}

	input = toLowerStr(input);//Converting all uppercase letters to lowercase

	return input;
}