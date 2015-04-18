#ifndef SavingsAccountH
#define SavingsAccountH
//---------------------------------------------------------------------------
//SavingsAccount: class declaration
//SHOULD BE ABSTRACT
//---------------------------------------------------------------------------
#include "BankAccount.h"

class SavingsAccount: public BankAccount {

public:
    SavingsAccount();
    SavingsAccount(const string& typ, const string& acctNum, const string& sCode ,const Date& cD, double b,const TransactionList& trList, const double minB);
	
	virtual ~SavingsAccount();
	
	double getMinimumBalance();

	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

	virtual double borrowable() const = 0;

	virtual const string prepareFormattedStatement() const;

	//virtual bool canTransferOut(double transferAmount) const;
	virtual bool canTransferIn(double transferAmount) const = 0;
protected:
    
	double minimumBalance_;
	


};

#endif