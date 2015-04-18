
#include "CurrentAccount.h"

CurrentAccount::CurrentAccount()
    : overdraftLimit_(0)
{}
CurrentAccount::CurrentAccount(const string& typ,const string& acctNum, const string& sCode,
								const Date& cD, double b, const TransactionList& trList, double overdraftLimit)
	:BankAccount(typ, acctNum, sCode,cD,b,trList),overdraftLimit_(overdraftLimit)
{}
CurrentAccount::~CurrentAccount()
{}

double CurrentAccount::getOverDraftLimit() const
{
	return overdraftLimit_;
}

double CurrentAccount::borrowable() const {
//return borrowable amount
    return (getBalance()+overdraftLimit_);
}
const string CurrentAccount::prepareFormattedStatement() const{
	ostringstream os;
	//account details
	os << BankAccount::prepareFormattedStatement();
	//list of transactions (or message if empty)
	os << "\nOVERDRAFT LIMIT: \234" << overdraftLimit_ << "\n";
	return ( os.str());
}

istream& CurrentAccount::getDataFromStream( istream& is) {
//get BankAccount details from stream
    is >> accountType_;						//get account type
    is >> accountNumber_;					//get account number
	is >> sortCode_;						//get sort code
 	is >> creationDate_;					//get creation date
	is >> balance_;							//get balance_
	is >> overdraftLimit_;
	is >> transactions_;					//get all transactions (if any)
	
	return is;
}

ostream& CurrentAccount::putDataInStream( ostream& os) const {
//put (unformatted) BankAccount details in stream
    os << accountType_ << "\n";				//put account type
    os << accountNumber_ << "\n";			//put account number
	os << sortCode_ << "\n";				//put sort code
    os << creationDate_ << "\n";			//put creation date
	os << balance_ << "\n";					//put balance
	os << overdraftLimit_ << "\n";
	if (  ! transactions_.size() == 0)
		os << transactions_;				//put all transactions, one per line
	return os;
}

