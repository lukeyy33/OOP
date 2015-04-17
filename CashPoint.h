//Pascale Vacher - March 15
//OOP Assignment Semester 2

#ifndef CashPointH
#define CashPointH 


//---------------------------------------------------------------------------
//CashPoint: class declaration
//---------------------------------------------------------------------------

#include "CashCard.h"
#include "BankAccount.h"
#include "UserInterface.h"
#include "ListT.h"

#include <fstream>
#include <string>
using namespace std;

class CashPoint {
public:
	//constructors & destructor
	CashPoint();	//default constructor
	~CashPoint();	//destructor
    void activateCashPoint();
private:
	//data items
    BankAccount* p_theActiveAccount_;
    CashCard* p_theCashCard_;
    const UserInterface theUI_;

	//support functions
	void performCardCommand( int);
    void performAccountProcessingCommand( int);
    int  validateCard( const string&) const;
	int  validateAccount( const string&) const;
	void processOneCustomerRequests();
	void processOneAccountRequests();

    void performSubMenuCommand( int);
    //commands
    //option 1
    void m1_produceBalance() const;
    //option 2
    void m2_withdrawFromBankAccount();
    //option 3
    void m3_depositToBankAccount();
    //option 4
    void m4_produceStatement() const;
	//option 5
	void m5_showAllDepositsTransactions() const;
	//option 6
	void m6_showMiniStatement() const;
	//option 7
	void m7_searchForTransactions() const;
	//option 7a
	void m7a_showTransactionsForAmount() const;
	//option 7b
	void m7b_showTransactionsForTitle() const;	
	//option 7c
	void m7c_showTransactionsForDate() const;
	//option 8
	void m8_clearAllTransationsUpToDate() const;
	//option 9
	void m9_showFundsAvailableOnAllAccounts();
	//option 10
	void m10_transferCashToAnotherAccount();

    //support file handling functions & creation of dynamic objects
    bool canOpenFile( const string&) const;
	int checkAccountType( const string&) const;
	void searchTransactions() const;
	bool linkedCard( string cashCardFileName) const;
	

	BankAccount* activateBankAccount( const string&);
	BankAccount* releaseBankAccount( BankAccount*, string);
	

    void activateCashCard( const string&);
	void releaseCashCard();
	void attemptTransfer(BankAccount* p_BA);
	void recordTransfer(double transferAmount, BankAccount* p_Transfer);
};

#endif
