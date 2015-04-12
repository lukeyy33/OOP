//Pascale Vacher - March 15
//OOP Assignment Semester 2

#ifndef ConstantsH
#define ConstantsH

#include <string>
using namespace std;

//menu command
const int QUIT_COMMAND( 0);

//account type
const int BANKACCOUNT_TYPE( 0); 

//card state
const int VALID_CARD( 0);
const int UNKNOWN_CARD( 1);
const int EMPTY_CARD( 2);

//account state
const int VALID_ACCOUNT( 0);
const int UNKNOWN_ACCOUNT( 1);
const int UNACCESSIBLE_ACCOUNT( 2);

//ressource path
const string FILEPATH( "data\\");

#endif