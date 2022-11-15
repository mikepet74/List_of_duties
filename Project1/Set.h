#pragma once
#ifndef firstTimeSet
#define firstTimeSet

#include "Select.h"

#define CUSTOMER_NUMBER_NOT_EXIST -1

// -------------------------------------------------------------------------------------//
// Functions declaration section:
// -------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------------------
// setQuery
//---------
//
// General : The function sends the query string to a function that returns a client structure
// and she put them in a customer list
// and adds the line to the file.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
// filePointer - pointer to the file to add the new line there
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void setQuery(char* line, manager* customerList, FILE* filePointer);

//-------------------------------------------------------------------------------------------------------------------------------------
// setNewCustomer
//---------------
//
// General : The function accepts a query string
// divides them into fields in a client structure
// checking the correctness of the fields
// and returns a client structure.
//
// Parameters :
// line - the query the user entered
//
// Return Value : A client structure consisting of the query
//
//-------------------------------------------------------------------------------------------------------------------------------------
client* setNewCustomer(char* line);


//-------------------------------------------------------------------------------------------------------------------------------------
// checkingClientExists
//---------------------
//
// General : The function receives a customer and checks if he already exists in the customer list
// if the customer does not exist, it returns - 1
// if the customer does exist, it returns his index in the customer list.
//
// Parameters :
// clientTemp - a customer structure to look for
// listOfClient - an administrative structure of a customer list where we search for the customer
//
// Return Value : the function returns the customer's position in the customer list
//
//-------------------------------------------------------------------------------------------------------------------------------------
int checkingClientExists(client clientTemp, manager* listOfClient);

//-------------------------------------------------------------------------------------------------------------------------------------
// addToFile
//----------
//
// General : The function accepts a client and a pointer to a file
// and prints the client as a new line to the file.
//
// Parameters :
// custmor - a client structure that needs to be added to the file
// filePointer - a pointer to a file for printing
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void addToFile(client* custmor, FILE* filePointer);

//-------------------------------------------------------------------------------------------------------------------------------------
// addNewCustomer
//---------------
//
// General : The function receives a list of customers and a customer
//and she adds the customer to the customer list.
//
// Parameters :
// customerList - manager structure of customer list
// clientAdd - a customer structure that must be added to the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void addNewCustomer(manager* customerList, client* clientAdd);

//-------------------------------------------------------------------------------------------------------------------------------------
// clientMerger
//-------------
//
// General : The function incorporates a client structure if it already exists in the system
// the function receives the customer listand the customer that needs to be combinedand the index of the existing customer in the customer list
// the function keeps the later date between them.
//
// Parameters :
// customerList - manager structure of customer list
// clientAdd - a client structure that needs to be added to an existing client
// sortingIndex - The index of the existing customer in the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void clientMerger(manager* customerList, client* clientAdd, int index);

//-------------------------------------------------------------------------------------------------------------------------------------
// sortList
//---------
//
// General : The function receives a certain index from the customer list that needs to be sorted after the merger
// the function goes through the customer listand moves the customer to his new location.
//
// Parameters :
// customerList - manager structure of customer list
// sortingIndex - the location of the customer to be sorted
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void sortList(manager* customerList, int sortingIndex);

//-------------------------------------------------------------------------------------------------------------------------------------
// divisionIntoFields
//-------------------
//
// General : The function receives the name of the field, the query line and a flag that indicates the type of the field
// the function goes through the row taking what corresponds to the field name
// checking its integrity
// and returns the field.
//
// Parameters :
// nameOfField - the field we are looking for
// line - query line
// flag - a flag that indicates the type of field and the length of the field
//
// Return Value : The string that should go into the field
//
//-------------------------------------------------------------------------------------------------------------------------------------
char* divisionIntoFields(char* nameOfField, char* line, int flag);

#endif // !1