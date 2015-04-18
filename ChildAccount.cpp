#include "ChildAccount.h"

ChildAccount::ChildAccount()
    :  maximumPaidIn_(0.0), minimumPaidIn_(0.0)
{}
ChildAccount::ChildAccount(const string& typ,const string& acctNum, const string& sCode, const Date& cD, double b, const TransactionList& trList, double minB, double intRate, double maxPaidIn, double minPaidIn)
	:SavingsAccount(typ, acctNum, sCode,cD,b,trList, minB, intRate), maximumPaidIn_(maxPaidIn), minimumPaidIn_(minPaidIn)
{}
ChildAccount::~ChildAccount()
{}


double ChildAccount::getMaximumPaidIn()
{
	return maximumPaidIn_;
}
double ChildAccount::getMinimumPaidIn()
{
	return minimumPaidIn_;
}

void ChildAccount::recordDeposit( double amountToDeposit) {

	if ((amountToDeposit >= minimumPaidIn_) && (amountToDeposit <= maximumPaidIn_))
	{
		BankAccount::recordDeposit(amountToDeposit);
	}
}

double ChildAccount::borrowable() const {
//return borrowable amount
    return (SavingsAccount::borrowable());
}

istream& ChildAccount::getDataFromStream( istream& is) {
//get BankAccount details from stream
    is >> accountType_;						//get account type
    is >> accountNumber_;					//get account number
	is >> sortCode_;						//get sort code
 	is >> creationDate_;					//get creation date
	is >> balance_;							//get balance_
	is >> interestRate_;
	is >> minimumBalance_;
	is >> minimumPaidIn_;
	is >> maximumPaidIn_;
	is >> transactions_;					//get all transactions (if any)
	
	return is;
}

ostream& ChildAccount::putDataInStream( ostream& os) const {
//put (unformatted) BankAccount details in stream
    os << accountType_ << "\n";				//put account type
    os << accountNumber_ << "\n";			//put account number
	os << sortCode_ << "\n";				//put sort code
    os << creationDate_ << "\n";			//put creation date
	os << balance_ << "\n";					//put balance
	os << interestRate_ << "\n";
	os << minimumBalance_ << "\n";
	os << minimumPaidIn_ << "\n";
	os << maximumPaidIn_ << "\n";
	if (  ! transactions_.size() == 0)
		os << transactions_;				//put all transactions, one per line
	return os;
}

const string ChildAccount::prepareFormattedStatement() const{
	ostringstream os;
	//account details
	os << SavingsAccount::prepareFormattedStatement();
	//list of transactions (or message if empty)
	os << "\nMINIMUM PAID IN: \234" << minimumPaidIn_;
	os << "\nMAXIMUM PAID IN: \234" << maximumPaidIn_<< "\n";
	return ( os.str());
}

bool ChildAccount::canTransferIn(double transferAmount) const
{	
	if ((transferAmount <= maximumPaidIn_) && (transferAmount >= minimumPaidIn_))
		return true;
	else
		return false;
}