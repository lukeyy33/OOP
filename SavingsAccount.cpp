//Jack Starkey, Alessandro Fasolilli, David McCabe, Tom Gray - Group: 2
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
    : minimumBalance_( 0), interestRate_(0.0)
{}
SavingsAccount::SavingsAccount(const string& typ,const string& acctNum, const string& sCode, const Date& cD, double b, const TransactionList& trList, double minB, double intRate)
	:BankAccount(typ, acctNum, sCode,cD,b,trList),minimumBalance_(minB),interestRate_(intRate)
{}
SavingsAccount::~SavingsAccount()
{}
double SavingsAccount::getInterestRate()
{
	return interestRate_;
}

double SavingsAccount::getMinimumBalance()
{
	return minimumBalance_;
}

double SavingsAccount::borrowable() const {
//return borrowable amount
    return (getBalance()-minimumBalance_);
}

const string SavingsAccount::prepareFormattedStatement() const{
	ostringstream os;
	//account details
	os << BankAccount::prepareFormattedStatement();
	//list of transactions (or message if empty)
	os << "\nMINIMUM BALANCE: \234" << minimumBalance_;
	os << "\nINTEREST RATE: " << interestRate_<<"%";
	return ( os.str());
}

istream& SavingsAccount::getDataFromStream( istream& is) {
//get BankAccount details from stream
    is >> accountType_;						//get account type
    is >> accountNumber_;					//get account number
	is >> sortCode_;						//get sort code
 	is >> creationDate_;					//get creation date
	is >> balance_;							//get balance_
	is >> interestRate_;	
	is >> minimumBalance_;
	is >> transactions_;					//get all transactions (if any)
	
	return is;
}

ostream& SavingsAccount::putDataInStream( ostream& os) const {
//put (unformatted) BankAccount details in stream
    os << accountType_ << "\n";				//put account type
    os << accountNumber_ << "\n";			//put account number
	os << sortCode_ << "\n";				//put sort code
    os << creationDate_ << "\n";			//put creation date
	os << balance_ << "\n";					//put balance
	os << interestRate_ << "\n";
	os << minimumBalance_ << "\n";
	if (  ! transactions_.size() == 0)
		os << transactions_;				//put all transactions, one per line
	return os;
}

