//Pascale Vacher - March 15
//OOP Assignment Semester 2

#ifndef TransactionListH
#define TransactionListH

//---------------------------------------------------------------------------
//TransactionList: class declaration
//---------------------------------------------------------------------------

#include "ListT.h"
#include "Transaction.h"

#include <cassert> 	// for assert()
#include <sstream>

class TransactionList {
public:
	void   addNewTransaction( const Transaction&);
    const Transaction newestTransaction() const;
    const  TransactionList olderTransactions() const;
    void   deleteFirstTransaction();
    void   deleteGivenTransaction( const Transaction&);
	int    size() const;

	TransactionList getAllDepositTransactions() const;
	double getTotalTransactions() const;
	const string toFormattedString() const;			//return transactionlist as a (formatted) string
	ostream& putDataInStream( ostream& os) const;	//send TransactionList info into an output stream
	istream& getDataFromStream( istream& is);		//receive TransactionList info from an input stream

	const TransactionList getMostRecentTransactions(int numTransactions) const;
	TransactionList getTransactionsForAmount(double amount) const;
	TransactionList getTransactionsUpToDate(const Date& d) const;
	void deleteTransactionsUpToDate(const Date& d);

private:
    List<Transaction> listOfTransactions_;	//list of transactions
};

//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream&, const TransactionList&);	//insertion operator
istream& operator>>( istream& is, TransactionList& trl); //extraction operator

#endif

