#ifndef ISAAccountH
#define ISAAccountH

#include "SavingsAccount.h"
//---------------------------------------------------------------------------
//ISAAccount: class declaration
//SHOULD BE CONCRETE
//---------------------------------------------------------------------------
class ISAAccount: public SavingsAccount {

public:
	

	ISAAccount();
    ISAAccount(const string& typ, const string& acctNum, const string& sCode ,const Date& cD, double b,const TransactionList& trList, const double minB, const double intRate, double maxYearly, double currentYearly, Date endDepositPeriod);
	
	virtual ~ISAAccount();

	double getMaximumYearlyDeposit();
	double getCurrentYearlyDeposit();
	Date getEndDepositPeriod();
	virtual void recordDeposit( double amount);

	virtual double borrowable() const;

	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

	virtual const string prepareFormattedStatement() const;

	virtual bool canTransferIn(double transferAmount) const;

	
private:

	void updateCurrentYEarlyDeposit(double a);

	// private data members

	double maximumYearlyDeposit_;
	double currentYearlyDeposit_;
	Date endDepositPeriod_;
};

#endif