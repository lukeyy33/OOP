//Pascale Vacher - March 15
//OOP Assignment Semester 2

#include "TransactionList.h"


//---------------------------------------------------------------------------
//TransactionList: class implementation
//---------------------------------------------------------------------------

//____public member functions

//____constructors & destructors

//____other public member functions

void TransactionList::addNewTransaction( const Transaction& tr) {
    listOfTransactions_.addInFront( tr);
}
const Transaction TransactionList::newestTransaction() const {
    return (listOfTransactions_.first());
}
const TransactionList TransactionList::olderTransactions() const {
	TransactionList trlist( *this);
    trlist.deleteFirstTransaction();
    return trlist;
}
void TransactionList::deleteFirstTransaction() {
    listOfTransactions_.deleteFirst();
}
void TransactionList::deleteGivenTransaction( const Transaction& tr) {
    listOfTransactions_.deleteOne( tr);
}
int TransactionList::size() const {
    return (listOfTransactions_.length());
}
TransactionList TransactionList::getAllDepositTransactions() const {
	TransactionList ret, copy(*this);
	while (copy.size() != 0)
	{
		if (copy.newestTransaction().getAmount() > 0)
			ret.addNewTransaction(copy.newestTransaction() );
		copy.deleteFirstTransaction();
	}
	return ret;
}
double TransactionList::getTotalTransactions() const {
	TransactionList ret, copy(*this);
	double sum(0.0);

	while (copy.size() != 0)
	{
		sum += copy.newestTransaction().getAmount();
		copy.deleteFirstTransaction();
	}
	return sum;
}
TransactionList TransactionList::getTransactionsForAmount(double amount) const {
	if (size() == 0)
		return *this;
	else
	{
		TransactionList ret, copy(*this);
		while (copy.size() != 0) {
			if (copy.newestTransaction().getAmount() == amount)
			{
				ret.addNewTransaction(newestTransaction());
				cout << "\n trans ok: " << newestTransaction().toFormattedString();
			}
			copy.deleteFirstTransaction();
		}
		return ret;
	}
}
TransactionList TransactionList::getTransactionsForTitle(string title) const {
	if (size() == 0)
		return *this;
	else
	{
		TransactionList ret, copy(*this);
		while (copy.size() != 0) {
			if (copy.newestTransaction().getTitle() == title)
			{
				ret.addNewTransaction(newestTransaction());
				cout << "\n trans ok: " << newestTransaction().toFormattedString();
			}
			copy.deleteFirstTransaction();
		}
		return ret;
	}
}

TransactionList TransactionList::getTransactionsForDate(const Date& d) const {

	if (size() == 0)
		return *this;
	else
	{
		TransactionList trlUpTo(olderTransactions().getTransactionsUpToDate(d));


		if (newestTransaction().getDate() == d)
		{
			trlUpTo.addNewTransaction(newestTransaction());
		}

		return trlUpTo;
	}
}

TransactionList TransactionList::getTransactionsUpToDate(const Date& d) const {

	if (size() == 0) 
		return *this;
	else
	{
		TransactionList trlUpTo(olderTransactions().getTransactionsUpToDate(d));
		
			
		if (newestTransaction().getDate() < d || newestTransaction().getDate() == d)
			{
				trlUpTo.addNewTransaction(newestTransaction());
			}
					
		return trlUpTo;
	}
}
void TransactionList::deleteTransactionsUpToDate(const Date& d) 
{
	//call function to get list of transactions to delete
	TransactionList deleteList = getTransactionsUpToDate(d);
	TransactionList temp(*this);
	while (!(deleteList.size() == 0))
	{
		Transaction temp = (deleteList.newestTransaction());
		this->deleteGivenTransaction(temp);//delete transaction
		deleteList.deleteFirstTransaction();//remove transaction from temp list
	}
}

const string TransactionList::toFormattedString() const {
//return transaction list as a (formatted) string
	ostringstream os_transactionlist;
    TransactionList tempTrList( *this);
	while ( ! ( tempTrList.size() == 0))
    {
		os_transactionlist << tempTrList.newestTransaction().toFormattedString() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return ( os_transactionlist.str());
}

const TransactionList TransactionList::getMostRecentTransactions(int numTransactions) const
{
	TransactionList tempTrList(*this);
	TransactionList trl;
	//ostringstream os_transactionlist;
	if (tempTrList.size() < numTransactions)
		numTransactions = tempTrList.size();
	for (int i = 0; i < numTransactions; i++)
	{
		trl.addNewTransaction(tempTrList.newestTransaction());
		tempTrList.deleteFirstTransaction();
	}
	return (trl); //os_transactionlist.str()
}

ostream& TransactionList::putDataInStream( ostream& os) const {
//put (unformatted) transaction list into an output stream
    TransactionList tempTrList( *this);
	while ( ! ( tempTrList.size() == 0))
    {
		os << tempTrList.newestTransaction() << endl;
        tempTrList.deleteFirstTransaction();
    }
	return os;
}
istream& TransactionList::getDataFromStream( istream& is) {
//read in (unformatted) transaction list from input stream
	Transaction aTransaction;
	is >> aTransaction;	//read first transaction
	while ( is) 	//while not end of file
	{
		listOfTransactions_.addAtEnd( aTransaction);   //add transaction to list of transactions
		is >> aTransaction;	//read in next transaction
	}
	return is;
}


//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream& os, const TransactionList& aTransactionList) {
    return ( aTransactionList.putDataInStream( os));
}
istream& operator>>( istream& is, TransactionList& aTransactionList) {
	return ( aTransactionList.getDataFromStream( is));
}
