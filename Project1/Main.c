#include "Management.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FILE* fp = NULL;
	char* query = NULL, * nameOfFile = { "stores.csv" };
	manager customerList = { NULL, 0 };

	fp = openFile(fp, nameOfFile);

	readingFile(fp, &customerList);
	printList(customerList);

	//Printing instructions:
	puts("\t\t\tOPERATING INSTRUCTIONS:\n\t\t\t---------------------");
	puts("\t1. To print all customers, enter \"print\".");
	puts("\t2. To enter a new customer:\n\t\tenter \"set\"\n\tand then the field names\n\t\t(first name, second name, id, phone, debt and date)");
	puts("\t\tand then the content\n\t\texample: set first name = plony, second name = almony, id = 123456789, phone = 0540000000, debt = -23, date = 1 / 1 / 2000");
	puts("\t3. To print according to a certain parameter,\n\t\tenter \"select\",\n\t\tand then enter the field name:\n\t\t(first name, second name, id, phone, debt, date),");
	puts("\t\tthen operator ( >, <, != , =), \n\t\tthen the  obj\n\t\texample: select first name != mike, or select debt < -30.");
	puts("\t4. To end the program, enter \"quit\".\n");

	//A loop that requests a query until the user enters "quit"
	do
	{
		free(query);
		fputs("---> ", stdout);
		while ((query = readLine(stdin)) == NULL)//Receiving a query from the user
		{
			puts("The system was unable to allocate space for the request, please request again");
			fputs("---> ", stdout);
		}
		queries(query, &customerList, fp);
	} while (strstr(query, "quit") == NULL);

	//Closing a file and freeing memory
	fclose(fp);
	freeListStructs(customerList);
	free(query);

	puts("See you :)\n");

	return 0;
}