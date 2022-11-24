#pragma once
#ifndef firstTimeGeneral
#define firstTimeGeneral

// -------------------------------------------------------------------------------------//
// Include and definition package section:
// -------------------------------------------------------------------------------------//
#define _CRT_SECURE_NO_WARNINGS
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CHUNK 10
#define NO_SUB_STR_fOUND -1
/*The _strdup function appears in the program, in Linux the function must be written without an underscore, thus strdup*/

// -------------------------------------------------------------------------------------//
// Types declaration:
// -------------------------------------------------------------------------------------//
typedef struct {//Date structure
	unsigned int day : 5;
	unsigned int month : 4;
	unsigned int year : 12;
}date;

typedef struct client {//client structure
	struct client* next;
	char* firstName;
	char* lastName;
	char* IDNumber;
	char* phoneNumber;
	date dateOfOperation;
	float debt;
	char error[8];
}client;

typedef struct manager {//manager structure
	client* head;
	unsigned int amountCustomers;
}manager;


// -------------------------------------------------------------------------------------//
// Functions declaration section:
// -------------------------------------------------------------------------------------//

//-------------------------------------------------------------------------------------------------------------------------------------
// printErrorMessage
//------------------
//
// General : The function prints an error message because of a space allocation problem.
//
// Parameters :
// None
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void printErrorMessage();

//-------------------------------------------------------------------------------------------------------------------------------------
// toLowerStr
//-----------
//
// General : The function accepts a string and iterates over it
// and all uppercase letters become lowercase.
//
// Parameters :
// str - a variable that contains the string
//
// Return Value : The function returns the new string
//
//-------------------------------------------------------------------------------------------------------------------------------------
char* toLowerStr(char* str);

//-------------------------------------------------------------------------------------------------------------------------------------
// checkStr
//---------
//
// General : The function checks if all characters are letters.
//
// Parameters :
// str - a variable that contains the string
//
// Return Value : The function returns 1 if the string is valid otherwise 0
//
//-------------------------------------------------------------------------------------------------------------------------------------
int checkStr(char* str);

//-------------------------------------------------------------------------------------------------------------------------------------
// checkInt
//---------
//
// General : The function checks if all characters are numbers.
//
// Parameters :
// str - a variable that contains the string
//
// Return Value : The function returns 1 if the string is valid otherwise 0
//
//-------------------------------------------------------------------------------------------------------------------------------------
int checkInt(char* str);

//-------------------------------------------------------------------------------------------------------------------------------------
// printError
//-----------
//
// General : The function receives a client structure and prints which line has an error.
//
// Parameters :
// custmer - client structure with the error
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void printError(client* custmer);

//-------------------------------------------------------------------------------------------------------------------------------------
// loweringSpace
//--------------
//
// General : The function accepts a string
// the function goes through the charactersand removes the space from the beginning of the string.
//
// Parameters :
// str - The string that needs to be de-spaced
//
// Return Value : The function returns the string without the spaces
//
//-------------------------------------------------------------------------------------------------------------------------------------
char* loweringSpace(char* str);

//-------------------------------------------------------------------------------------------------------------------------------------
// removesSpaceFromEnd
//--------------------
//
// General : The function accepts a string
// the function goes through the charactersand removes the space from the end of string.
//
// Parameters :
// str - The string that needs to be de-spaced
//
// Return Value : The function returns the string without the spaces
//
//-------------------------------------------------------------------------------------------------------------------------------------
void removesSpaceFromEnd(char* str);

//-------------------------------------------------------------------------------------------------------------------------------------
// putErrorInTheStruct
//--------------------
//
// General : The function receives a client structure and the location of an error
// the function puts the error in the array of the client's errors.
//
// Parameters :
// custmer - a client structure where the error should be put
// errorLocation - the index where the error should be put
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void putErrorInTheStruct(client* custmer, int errorLocation);

//-------------------------------------------------------------------------------------------------------------------------------------
// printTitleTable
//----------------
//
// General : The function prints a header for the table before customers are printed.
//
// Parameters :
// None
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void printTitleTable();

//-------------------------------------------------------------------------------------------------------------------------------------
// print
//------
//
// General : The function accepts a customer structure and a customer number and prints it to stdin.
//
// Parameters :
// customer - client structure
// customerNumber - customer number
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void print(client* customer, int customerNumber);

//-------------------------------------------------------------------------------------------------------------------------------------
// freeStruct
//-----------
//
// General : The function accepts a client structure
// she releases his fields
// then releases the structure itself.
//
// Parameters :
// custmer - A client structure that must be freed
//
// Return Value : None
//
//-------------------------------------------------------------------------------------------------------------------------------------
void freeStruct(client* custmer);

int checkDebt(char* debt);

#endif // !1