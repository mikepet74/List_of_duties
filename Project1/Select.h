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
// the function checks according to which field the client is looking forand accordingly sends to the appropriate function.
//
// Parameters :
// line - a variable containing the user's query
// customerList - manager structure of customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectionQuery(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectFirstName
//----------------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the first names of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectFirstName(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectLastName
//---------------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the second names of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectLastName(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectDebt
//-----------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the debt of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectDebt(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectDate
//-----------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the date of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectDate(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectIDNumber
//---------------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the ID number of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectIDNumber(char* line, manager* customerList);

//-------------------------------------------------------------------------------------------------------------------------------------
// selectPhoneNumber
//------------------
//
// General : The function receives the user's query and a list of customers
// the function checks which operator the user entered
// then you check on the phone number of the customers who is suitable for the operator
// and sends the aforementioned customers to print.
//
// Parameters :
// line - the query the user entered
// customerList - manager structure of the customer list
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void selectPhoneNumber(char* line, manager* customerList);

#endif // !1