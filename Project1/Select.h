#pragma once
#ifndef firstTimeSelect
#define firstTimeSelect

#include "General.h"

// -------------------------------------------------------------------------------------//
// Functions declaration section:
// -------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------------------
// selectionQuery
//---------------
//
// General : Print query function
// the function accepts the query
// and a list of customers whose names she searches for according to the query
// the function checks according to which field the client is looking for and accordingly sends to the appropriate function.
//
// Parameters :
// line - a variable containing the user's query
// customerList - manager structure of customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectionQuery(char* line, manager* customerList);


int compareFirstName(client* customer, void* query);
int compareLastName(client* customer, void* query);
int compareDebt(client* customer, void* query);
int compareIDNumber(client* customer, void* query);
int comparePhoneNumber(client* customer, void* query);
int big(int (*compare)(client*, void*), char* query, client* customer);
int small(int (*compare)(client*, void*), char* query, client* customer);
int different(int (*compare)(client*, void*), char* query, client* customer);
int equal(int (*compare)(client*, void*), char* query, client* customer);
int printSelect(int (*compare)(client*, void*), char* query, int parameter, manager* customerList);



#endif // !1