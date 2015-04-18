//Pascale Vacher - March 15
//OOP Assignment Semester 2

#ifndef BankAccountH
#define BankAccountH

//---------------------------------------------------------------------------
//BankAccount: class declaration
//---------------------------------------------------------------------------

//#include "Date.h"
//#include "Transaction.h"
#include "TransactionList.h"

#include <fstream>
using namespace std;


class BankAccount {
public:
    //constructors & destructor
	BankAccount();
    BankAccount( const string& typ, const string& acctNum, const string& sCode,
                          const Date& cD, double b,
                          const TransactionList& trList);
    virtual ~BankAccount();

	//getter (assessor) functions
	const string getAccountType() const;
    const string getAccountNumber() const;
    const string getSortCode() const;
    const Date getCreationDate() const;
	double getBalance() const;
    const TransactionList getTransactions() const;
    bool	isEmptyTransactionList() const;


	//functions to put data into and get data from streams
	virtual	ostream& putDataInStream( ostream& os) const;
	ostream& putAccountDetailsInStream(ostream& os) const;
	virtual istream& getDataFromStream(istream& is);
	istream& getAccountDataFromStream(istream& is);

	//other operations
	virtual const string prepareFormattedStatement() const;

    virtual void recordDeposit( double amount);

	virtual double borrowable() const;
	virtual bool canWithdraw( double amount) const;
    void recordWithdrawal( double amount);

	void produceAllDepositTransactions(string& str, double& total) const;
	void showAllDepositsOnScreen(bool);
	void getTotalTransactions() const;

	virtual void readInBankAccountFromFile( const string& fileName);
	void storeBankAccountInFile( const string& fileName) const;

	const string produceNMostRecentTransactions(int numTransactions, double& total) const;
	void produceTransactionsForAmount(double amount, string& str, int& n) const;
	void produceTransactionsForDate(const Date& d, string& str, int& n) const;
	
	void produceTransactionsUpToDate(const Date& d, string& str, int& n) const;
	void recordDeletionOfTransaction(const Date& d);

	virtual bool canTransferOut(double transferAmount) const;
	virtual bool canTransferIn(double transferAmount) const;
	void recordTransferOut(double transferAmount, string tAN, string tSC);
	void recordTransferIn(double transferAmount, string aAN, string aSC);


	double maxWithdrawalAllowed() const;
	
protected:
	string accountType_;
	string accountNumber_;
	string sortCode_;
	Date   creationDate_;
	double balance_;
	TransactionList transactions_;

	
private:
    //data items
    
 
	//support functions
	void updateBalance( double amount);
	const string prepareFormattedAccountDetails() const;
	const string prepareFormattedTransactionList() const;
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream&, const BankAccount&);	//output operator
istream& operator>>( istream&, BankAccount&);	    //input operator

#endif
