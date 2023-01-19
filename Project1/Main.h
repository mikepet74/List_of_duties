#pragma once
#ifndef firstTimeMain
#define firstTimeMain

#include "Set.h"

// -------------------------------------------------------------------------------------//
// Functions declaration section:
// -------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------------------
// openFile
//---------
//
// General : The function opens a file
// It receives a file type pointer, a string of the file name and and the flag to check if we have done dynamic memory allocation (in case the file is not found, and we requested a new name for the file)
// The function opens the block and returns the pointer to the file.
//
// Parameters :
// filePointer - FILE type pointer
// nameOfFile - A string containing the file name
// CheckingAllocatedDynamicMemory - A variable to test if we have made a dynamic assignment in the function
//
// Return Value : Pointer to the file we opened
//
//-------------------------------------------------------------------------------------------------------------------------------------
FILE* openFile(FILE* filePointer, char* nameOfFile);

//-------------------------------------------------------------------------------------------------------------------------------------
// creatingClient
//---------------
//
// General : The function gets a line from the file
// and divides the row into fields of a customer structure
// checking the correctness of the fields
// returns the customer.
//
// Parameters :
// line - a string of a line from the file
//
// Return Value : client structure
//
//-------------------------------------------------------------------------------------------------------------------------------------
client* creatingClient(char* line);

//-------------------------------------------------------------------------------------------------------------------------------------
// readingFile
//------------
//
// General : A function that reads from the file in a loop line by line
// sends to another function each row that returns a client structure
// the function checks if the client exists and then sends it to merge
// otherwise, the phone operation adds him to the customer list.
//
// Parameters :
// filePointer - a pointer to a file
// customerList - the manager structure of a customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void readingFile(FILE* filePointer, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// printList
//----------
//
// General : The function receives a customer list manager structure
// and prints all the customers.
//
// Parameters :
// customerList - manager structure of a linked list of customers
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void printList(manager customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// freeListStructs
//----------------
//
// General : The function accepts a customer list manager structure
// goes through the customers in a loop and sends them one by one to release.
//
// Parameters :
// customerList - A manager structure of a customer list that must be released
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void freeListStructs(manager customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// queries
//--------
//
// General : The function receives a line of the query that the user entered
// customer list to search for customers or add customers
// and points to the file to add new lines
// the function checks which query the user requested and sends to the appropriate function.
//
// Parameters :
// query - a variable containing the user's query
// customerList - manager structure of customer list
// filePointer - pointer to file to add new lines
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void queries(char* query, manager* customerList, FILE* filePointer);

//-------------------------------------------------------------------------------------------------------------------------------------
// readLine
//---------
//
// General : The function receives a pointer to the place from which a line should be taken (stdin/file)
// the function captures in segments until the line falls
// and allocates exactly how much space the string consumes.
//
// Parameters :
// read - pointer to where the line should be taken from
//
// Return Value : the received string
//
//-------------------------------------------------------------------------------------------------------------------------------------
char* readLine(FILE* read);

#endif // !1