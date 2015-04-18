#ifndef ChildAccountH
#define ChildAccountH
//---------------------------------------------------------------------------
//ChildAccount: class declaration
//SHOULD BE CONCRETE
//---------------------------------------------------------------------------
#include "SavingsAccount.h"

class ChildAccount: public SavingsAccount {

public:

	ChildAccount();
    ChildAccount(const string& typ, const string& acctNum, const string& sCode, 
		const Date& cD, double b,const TransactionList& trList, const double minB,
		double maxPaidIn, double minPaidIn);
	
	virtual ~ChildAccount();
    
	double getMaximumPaidIn();
	double getMinimumPaidIn();

	virtual double borrowable() const;

	virtual void recordDeposit( double amount);

	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

	virtual const string prepareFormattedStatement() const;

	virtual bool canTransferIn(double transferAmount) const;
	
private:
    
	// private data members

	double maximumPaidIn_;
	double minimumPaidIn_;
};

#endif