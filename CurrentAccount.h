#ifndef CurrentAccountH
#define CurrentAccountH
//---------------------------------------------------------------------------
//CurrentAccount: class declaration
//SHOULD BE CONCRETE
//---------------------------------------------------------------------------
#include "BankAccount.h"

class CurrentAccount: public BankAccount {

public:
    CurrentAccount();
    CurrentAccount(const string& typ, const string& acctNum, const string& sCode ,const Date& cD, double b,const TransactionList& trList, const double oL);
	
	virtual ~CurrentAccount();


	virtual ostream& putDataInStream( ostream& os) const;
	virtual istream& getDataFromStream( istream& is);

    
	virtual double borrowable() const;
	double getOverDraftLimit() const;

	//virtual void readInBankAccountFromFile( const string& fileName);

	//virtual bool canTransferOut(double transferAmount) const;
	//virtual bool canTransferIn(double transferAmount) const;

	virtual const string prepareFormattedStatement() const;

private:
    
	double overdraftLimit_;
};
#endif