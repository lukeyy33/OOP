#include "ISAAccount.h"


ISAAccount::ISAAccount()
: maximumYearlyDeposit_(0.0), currentYearlyDeposit_(0.0), endDepositPeriod_()
{}
ISAAccount::ISAAccount(const string& typ, const string& acctNum, const string& sCode,
	const Date& cD, double b,
	const TransactionList& trList, double minB, double maxYearly, double currentYearly, Date endDepositPeriod)
	:SavingsAccount(typ, acctNum, sCode,cD,b,trList, minB), maximumYearlyDeposit_(maxYearly), currentYearlyDeposit_(currentYearly), endDepositPeriod_(endDepositPeriod)
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


//ostream& BankAccount::putDataInStream(ostream& os) const {
//	//put (unformatted) BankAccount details in stream
//	putAccountDetailsInStream(os);			//put bank account core information in stream
//	if (transactions_.size() != 0)
//		os << transactions_;				//put all transactions, one per line
//	return os;
//}
//ostream& BankAccount::putAccountDetailsInStream(ostream& os) const {
//	//put (unformatted) BankAccount details in stream
//	os << accountType_ << "\n";				//put account type
//	os << accountNumber_ << "\n";			//put account number
//	os << sortCode_ << "\n";				//put sort code
//	os << creationDate_ << "\n";			//put creation date
//	os << balance_ << "\n";					//put balance
//	return os;
//}
//istream& BankAccount::getDataFromStream(istream& is) {
//	//get BankAccount details from stream
//	getAccountDataFromStream(is);			//get bank account ore information from stream
//	is >> transactions_;					//get all transactions (if any)
//	return is;
//}
//istream& BankAccount::getAccountDataFromStream(istream& is) {
//	//get BankAccount details from stream
//	is >> accountType_;						//get account type
//	is >> accountNumber_;					//get account number
//	is >> sortCode_;						//get sort code
//	is >> creationDate_;					//get creation date
//	is >> balance_;							//get balance
//	//	is >> transactions_;					//get transactions
//	return is;
//}
bool ISAAccount::canTransferIn(double transferAmount) const
{

	if ((transferAmount <= maximumYearlyDeposit_) && (currentYearlyDeposit_ + transferAmount <= maximumYearlyDeposit_) && (Date::currentDate() <= endDepositPeriod_))
		return true;
	else
		return false;
}

