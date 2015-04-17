//Jack Starkey, Alessandro Fasolilli, David McCabe, Tom Gray - Group: 2
#include "ISAAccount.h"


ISAAccount::ISAAccount()
    :  maximumYearlyDeposit_(0.0), currentYearlyDeposit_(0.0) // initialise date to following 5th april??????????!!??!?
{}
ISAAccount::ISAAccount(const string& typ,const string& acctNum, const string& sCode, const Date& cD, double b, const TransactionList& trList, double minB, double intRate,  double maxYearly, double currentYearly, Date endDepositPeriod)
	:SavingsAccount(typ, acctNum, sCode,cD,b,trList, minB, intRate), maximumYearlyDeposit_(maxYearly), currentYearlyDeposit_(currentYearly), endDepositPeriod_(endDepositPeriod)
{}
ISAAccount::~ISAAccount()
{}

double ISAAccount::getMaximumYearlyDeposit()
{
	return maximumYearlyDeposit_;
}
double ISAAccount::getCurrentYearlyDeposit()
{
	return currentYearlyDeposit_;
}
Date ISAAccount:: getEndDepositPeriod()
{
	return endDepositPeriod_;
}
double ISAAccount::borrowable() const {
//return borrowable amount
    return (SavingsAccount::borrowable());
}

void ISAAccount::recordDeposit( double amountToDeposit) {

	if ((Date::currentDate()<endDepositPeriod_) && (currentYearlyDeposit_+amountToDeposit <= maximumYearlyDeposit_))
	{
		BankAccount::recordDeposit(amountToDeposit);
		currentYearlyDeposit_+=amountToDeposit;
	}
}

const string ISAAccount::prepareFormattedStatement() const{
	ostringstream os;
	//account details
	os << SavingsAccount::prepareFormattedStatement();
	//list of transactions (or message if empty)
	os << "\nMAXIMUM YEARLY DEPOSIT: \234" << maximumYearlyDeposit_;
	os << "\nCURRENT YEARLY DEPOSIT: \234" << currentYearlyDeposit_;
	os << "\nEND DEPOSIT PERIOD: " << endDepositPeriod_ << "\n";
	return ( os.str());
}

istream& ISAAccount::getDataFromStream( istream& is) {
//get BankAccount details from stream
    is >> accountType_;						//get account type
    is >> accountNumber_;					//get account number
	is >> sortCode_;						//get sort code
 	is >> creationDate_;					//get creation date
	is >> balance_;							//get balance_
	is >> interestRate_;
	is >> minimumBalance_;
	is >> maximumYearlyDeposit_;
	is >> currentYearlyDeposit_;
	is >> endDepositPeriod_;
	is >> transactions_;					//get all transactions (if any)
	
	return is;
}

ostream& ISAAccount::putDataInStream( ostream& os) const {
//put (unformatted) BankAccount details in stream
    os << accountType_ << "\n";				//put account type
    os << accountNumber_ << "\n";			//put account number
	os << sortCode_ << "\n";				//put sort code
    os << creationDate_ << "\n";			//put creation date
	os << balance_ << "\n";					//put balance
	os << interestRate_ << "\n";
	os << minimumBalance_ << "\n";
	os << maximumYearlyDeposit_ << "\n";
	os << currentYearlyDeposit_ << "\n";
	os << endDepositPeriod_ << "\n";
	if (  ! transactions_.size() == 0)
		os << transactions_;				//put all transactions, one per line
	return os;
}

bool ISAAccount::canTransferIn(double transferAmount) const
{	
	
	if ((transferAmount <= maximumYearlyDeposit_) && (currentYearlyDeposit_+transferAmount <= maximumYearlyDeposit_) && (Date::currentDate() <= endDepositPeriod_))
		return true;
	else
		return false;
}