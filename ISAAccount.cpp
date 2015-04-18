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

bool ISAAccount::canTransferIn(double transferAmount) const
{

	if ((transferAmount <= maximumYearlyDeposit_) && (currentYearlyDeposit_ + transferAmount <= maximumYearlyDeposit_) && (Date::currentDate() <= endDepositPeriod_))
		return true;
	else
		return false;
}


