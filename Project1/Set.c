#include "Set.h"

void setQuery(char* line, manager* customerList, FILE* filePointer)
{
	int existingCustomerNumber, i;
	client* newClient = setNewCustomer(line);
	if (newClient == NULL)
	{
		return;
	}
	existingCustomerNumber = checkingClientExists(*newClient, customerList);
	addToFile(newClient, filePointer);
	if (existingCustomerNumber == CUSTOMER_NUMBER_NOT_EXIST)
	{
		addNewCustomer(customerList, newClient);
		puts("The customer has been successfully added to the customer list\n");
	}
	else
	{
		client* clientTemp = customerList->head;
		for (i = 0;i < existingCustomerNumber;i++)
		{
			clientTemp = clientTemp->next;
		}
		if ((strcmp(clientTemp->firstName, newClient->firstName)!=0) || (strcmp(clientTemp->lastName, newClient->lastName)!=0))
		{
			freeStruct(newClient);
			puts("Adding the person was not successful, the id already exists with other data\n");
			return;
		}
		else
		{
			clientMerger(customerList, newClient, existingCustomerNumber);
			puts("The debt was successfully merged with an existing customer\n");
		}
	}
}

client* setNewCustomer(char* line)
{
	int date, i, iDebt;
	float fDebt;
	char* saveToFree;
	client* customer = (client*)malloc(sizeof(client));
	if (customer == NULL)
	{
		puts("The system failed to allocate memory for the structure\n");
		return customer;
	}
	for (i = 0;i < 7;i++)
	{
		customer->error[i] = 0;
	}
	//Dividing the row into fields
	char* token, * tempLine;
	//first name
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("first name", tempLine, 1);
	customer->firstName = _strdup(token);
	if (customer->firstName == NULL)
	{
		free(saveToFree);
		free(customer);
		return NULL;
	}
	free(saveToFree);
	//second name
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("second name", tempLine, 1);
	if (token == NULL)
	{
		free(customer->firstName);
		free(customer);
		free(saveToFree);
		return NULL;
	}
	customer->lastName = _strdup(token);
	if (customer->lastName == NULL)
	{
		free(customer->firstName);
		free(customer);
		free(saveToFree);
		return NULL;
	}
	free(saveToFree);
	//ID number
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("id", tempLine, 9);
	if (token == NULL)
	{
		free(saveToFree);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	customer->IDNumber = _strdup(token);
	if (customer->IDNumber == NULL)
	{
		free(saveToFree);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	free(saveToFree);
	//phone number
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer->lastName);
		free(customer->firstName);
		free(customer->IDNumber);
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("phone", tempLine, 10);
	if (token == NULL)
	{
		free(saveToFree);
		free(customer->lastName);
		free(customer->firstName);
		free(customer->IDNumber);
		free(customer);
		return NULL;
	}
	customer->phoneNumber = _strdup(token);
	if (customer->phoneNumber == NULL)
	{
		free(saveToFree);
		free(customer->lastName);
		free(customer->firstName);
		free(customer->IDNumber);
		free(customer);
		return NULL;
	}
	free(saveToFree);
	//date
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("date", tempLine, 4);
	if (token == NULL)
	{
		free(customer->phoneNumber);
		free(saveToFree);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	token = strtok(token, "/");
	//days
	date = atoi(token);
	if (date < 1 || date>31)
	{
		puts("The customer was not added to the list because the number of days must be greater than 0 and less than 32\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	customer->dateOfOperation.day = date;
	//months
	token = strtok(NULL, "/");
	if (token)
	{
		date = atoi(token);
	}
	else
	{
		puts("The customer was not added to the list because The months must contain only digits\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	if (date < 1 || date>12)
	{
		puts("The customer was not added to the list because the number of month must be greater than 0 and less than 13\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	customer->dateOfOperation.month = date;
	//years
	token = strtok(NULL, ",");
	token = strtok(token, " ");
	if (token)
	{
		date = atoi(token);
	}
	else
	{
		puts("The customer was not added to the list because The months must contain only digits\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	if (date < 0)
	{
		puts("The customer was not added to the list because the number of month must be greater than 0\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	customer->dateOfOperation.year = date;
	free(saveToFree);
	//debt
	saveToFree = tempLine = _strdup(line);
	if (tempLine == NULL)
	{
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	token = divisionIntoFields("debt", tempLine, 4);
	if (token == NULL)
	{
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	if (!atof(token) && strcmp(token, "0")!=0)
	{
		puts("The customer was not added to the customer list because the debt format is incorrect\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	if (!checkDebt(token))
	{
		puts("The debt format is incorrect\n");
		free(saveToFree);
		free(customer->phoneNumber);
		free(customer->IDNumber);
		free(customer->lastName);
		free(customer->firstName);
		free(customer);
		return NULL;
	}
	fDebt = (float)atof(token) * 100;
	iDebt = (int)fDebt;
	customer->debt = (float)iDebt / 100;
	//next
	customer->next = NULL;
	free(saveToFree);
	return customer;
}

void addToFile(client* custmor, FILE* filePointer)
{
	fprintf(filePointer, "%s,", custmor->firstName);
	fprintf(filePointer, "%s,", custmor->lastName);
	fprintf(filePointer, "%s,", custmor->IDNumber);
	fprintf(filePointer, "%s,", custmor->phoneNumber);
	fprintf(filePointer, "%.2f,", custmor->debt);
	fprintf(filePointer, "%02d/%02d/%04d\n", custmor->dateOfOperation.day, custmor->dateOfOperation.month, custmor->dateOfOperation.year);
}

int checkingClientExists(client clientTemp, manager* listOfClient)
{
	int customerNumber = -1;//The index that the client exists
	client* temp = listOfClient->head;

	while (temp)
	{
		customerNumber++;
		if (((strcmp(clientTemp.IDNumber, temp->IDNumber)!=0) || (temp->error[7] == 1)))
		{
			temp = temp->next;
		}
		else if (temp->error[0] == 0)
		{
			return customerNumber;
		}
		else
		{
			temp = temp->next;
		}
	}
	return CUSTOMER_NUMBER_NOT_EXIST;
}

void addNewCustomer(manager* customerList, client* clientAdd)
{
	client* tempClient = customerList->head;

	if (!tempClient)//Checking if the list is empty
	{
		customerList->head = clientAdd;
		customerList->amountCustomers++;
		return;
	}
	if (clientAdd->debt > tempClient->debt)//Checking if the debt is the smallest
	{
		clientAdd->next = tempClient;
		customerList->head = clientAdd;
		customerList->amountCustomers++;
		return;
	}
	while (tempClient)
	{
		if (!tempClient->next)//We have reached the end of the list
		{
			tempClient->next = clientAdd;
			customerList->amountCustomers++;
			return;
		}
		if (clientAdd->debt > tempClient->next->debt)//Checking if his debt is greater than the next debt
		{
			clientAdd->next = tempClient->next;
			tempClient->next = clientAdd;
			customerList->amountCustomers++;
			return;
		}
		tempClient = tempClient->next;
	}
}

void clientMerger(manager* customerList, client* clientAdd, int index)
{
	int i;
	client* existingCustomer = customerList->head;
	for (i = 0; i < index; i++)
	{
		existingCustomer = existingCustomer->next;
	}
	existingCustomer->debt += clientAdd->debt;
	if (clientAdd->error[5] == 0 && (clientAdd->dateOfOperation.year > existingCustomer->dateOfOperation.year || clientAdd->dateOfOperation.month > existingCustomer->dateOfOperation.month || clientAdd->dateOfOperation.day > existingCustomer->dateOfOperation.day || existingCustomer->error[5] != 0))//Checking what the last date is
	{
		existingCustomer->dateOfOperation = clientAdd->dateOfOperation;
		//Checking if he has changed data or if there is an error in one of the customer's fields:
		if (strcmp(existingCustomer->phoneNumber, clientAdd->phoneNumber)!=0 && clientAdd->error[4] == 0)
		{
			free(existingCustomer->phoneNumber);
			existingCustomer->phoneNumber = _strdup(clientAdd->phoneNumber);
			if (existingCustomer->phoneNumber == NULL)
			{
				return;
			}
			existingCustomer->error[4] = 0;
		}
	}
	//Checking for an error at the client
	else if (existingCustomer->error[0] != 0)
	{
		if (existingCustomer->error[4] != 0 && clientAdd->error[4] == 0)
		{
			free(existingCustomer->phoneNumber);
			existingCustomer->phoneNumber = _strdup(clientAdd->phoneNumber);
			if (existingCustomer->phoneNumber == NULL)
			{
				return;
			}
			existingCustomer->error[4] = 0;
		}
		if (existingCustomer->error[6] != 0 && clientAdd->error[6] == 0)
			existingCustomer->error[6] = 0;
	}
	for (i = 1;i < 8;i++)
	{
		if (existingCustomer->error[i] != 0)
		{
			break;
		}
	}
	if (i == 8)
	{
		existingCustomer->error[0] = 0;
	}
	else
	{
		existingCustomer->error[0] = i - 1;
	}
	freeStruct(clientAdd);//Freeing the unnecessary structure

	sortList(customerList, index);//Sending the list for re-sorting
}

void sortList(manager* customerList, int sortingIndex)
{
	int i;
	client* clientSorting;
	client* prev = customerList->head;
	for (i = 0;i < sortingIndex - 1;i++)
	{
		prev = prev->next;
	}
	if (prev->next != NULL) {
		clientSorting = prev->next;
		prev->next = clientSorting->next;
		clientSorting->next = NULL;
		addNewCustomer(customerList, clientSorting);
	}
}

char* divisionIntoFields(char* nameOfField, char* line, int flag)
{
	char* token;
	if (strstr(line, nameOfField) == NULL)
	{

		printf("The customer was not added to the list because \"%s\" field was not entered\n\n", nameOfField);
		return NULL;
	}
	else
	{
		line = strstr(line, nameOfField);
		line += strlen(nameOfField);
		line = strstr(line, "=");
		line++;
		token = strtok(line, ",");
		if (!token)
		{
			printf("No information was entered into the field %s\n\n", nameOfField);
			return NULL;
		}
		removesSpaceFromEnd(token);
	}
	if (flag == 1)
	{
		if (!checkStr(token))
		{
			printf("The customer was not added to the list because the %s field should only contain letters\n\n", nameOfField);
			return NULL;
		}
	}
	else if (flag > 5)
	{
		if (!checkInt(token))
		{
			printf("The customer was not added to the list because the %s field should only contain numbers\n\n", nameOfField);
			return NULL;
		}
		else if (strlen(token) != flag)
		{
			printf("The customer was not added to the list because the %s field should only contain %d digits\n\n", nameOfField, flag);
			return NULL;
		}
	}
	return token;
}