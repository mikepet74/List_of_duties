#include "Main.h"
 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FILE* fp=NULL;
	char* query=NULL, *nameOfFile = { "stores.csv" };
	manager customerList = { NULL, 0};

	fp=openFile(fp, nameOfFile);

	readingFile(fp, &customerList);
	printList(customerList);

	//Printing instructions:
	printf("\t\t\tOPERATING INSRUCTIONS:\n\t\t\t---------------------\n");
	printf("\t1. To print all customers, enter \"print\".\n");
	printf("\t2. To enter a new customer:\n\t\tenter \"set\"\n\tand then the field names\n\t\t(first name, second name, id, phone, debt and date)\n\t\tand then the content\n\t\texample: set first name=plony, second name=almony, id=123456789, phone=0540000000, debt=-23, date=1/1/2000\n");
	printf("\t3. To print according to a certain parameter,\n\t\tenter \"select\",\n\t\tand then enter the field name:\n\t\t(first name, second name, id, phone, debt, date),\n\t\tthen operator ( > , < , != , =),\n\t\tthen the  obj\n\t\texample: select first name != mike, or select debt < -30.\n");
	printf("\t4. To end the program, enter \"quit\".\n\n");

	//A loop that requests a query until the user enters "quit"
	do
	{
		free(query);
		printf("---> ");
		while ((query = readLine(stdin)) == NULL)//Receiving a query from the user
		{
			printf("The system was unable to allocate space for the request, please request again\n");
			printf("---> ");
		}
		queries(query, &customerList, fp);
	} while (strstr(query, "quit") == NULL);

	//Closing a file and freeing memory
	fclose(fp);
	freeListStructs(customerList);
	free(query);

	printf("See you :)\n\n");

	return 0;
}