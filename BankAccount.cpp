//Pascale Vacher - March 15
//OOP Assignment Semester 2

#include "BankAccount.h"

//---------------------------------------------------------------------------
//BankAccount: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

BankAccount::BankAccount()
    : accountNumber_( "null"),
      sortCode_( "null"),
	  balance_( 0.0)
{}
BankAccount::BankAccount( const string& typ, const string& acctNum, const string& sCode,
                          const Date& cD, double b,
                          const TransactionList& trList)
    : accountType_(typ),
	  accountNumber_( acctNum), sortCode_( sCode),
      creationDate_( cD),
      balance_( b),
      transactions_( trList)
{}
BankAccount::~BankAccount()
{}


//____other public member functions

const string BankAccount::getAccountType() const {
    return accountType_;
}
const string BankAccount::getAccountNumber() const {
    return accountNumber_;
}
const string BankAccount::getSortCode() const {
    return sortCode_;
}
const Date BankAccount::getCreationDate() const {
    return creationDate_;
}
double BankAccount::getBalance() const {
    return balance_;
}
const TransactionList BankAccount::getTransactions() const {
    return transactions_;
}
bool BankAccount::isEmptyTransactionList() const {
	return transactions_.size() == 0;
}

void BankAccount::recordDeposit( double amountToDeposit) {
    //create a deposit transaction
	Transaction aTransaction( "deposit_to_ATM", amountToDeposit);
    //update active bankaccount
    transactions_.addNewTransaction( aTransaction);		//update transactions_
    updateBalance( amountToDeposit);			//increase balance_
}

double BankAccount::borrowable() const {
//return borrowable amount
    return balance_;
}
void BankAccount::produceAllDepositTransactions(string& str, double& total) const {
	//2.1 trl := getAllDepositTransactions():TransactionList
	TransactionList trl(transactions_.getAllDepositTransactions() );
	//2.2 total:= getTotalTransactions(): double
	total = trl.getTotalTransactions();
	//2.3 str:= toFormattedString(): string
	str = trl.toFormattedString();
}

const string BankAccount::produceNMostRecentTransactions(int numTransactions, double& total) const {
	ostringstream os;
	os << prepareFormattedAccountDetails() << "\n\nRECENT TRANSACTIONS \n";
	TransactionList trl = transactions_.getAllDepositTransactions();
	total = trl.getTotalTransactions();
	os << trl.toFormattedString();
	return(os.str());
}
void BankAccount::produceTransactionsForAmount( double amount, string& str, int& n) const {
	
	TransactionList trl = transactions_.getTransactionsForAmount(amount);	
	n = trl.size();
	str = trl.toFormattedString();
}

void BankAccount::produceTransactionsForDate(const Date& d, string& str, int& n) const {

	TransactionList trl = transactions_.getTransactionsForDate(d);
	n = trl.size();
	str = trl.toFormattedString();
}

void BankAccount::produceTransactionsUpToDate(const Date& d, string& str, int& n) const {
	
	TransactionList trl = transactions_.getTransactionsUpToDate(d);	
	n = trl.size();
	str = trl.toFormattedString();
}

void BankAccount::recordDeletionOfTransaction(const Date& d) {
	transactions_.deleteTransactionsUpToDate(d);

}

bool BankAccount::canWithdraw( double amountToWithdraw ) const {
//check if enough money in account
    return ( amountToWithdraw <= borrowable());
}
double BankAccount::maxWithdrawalAllowed() const {
	double maxWidthdrawal(0.0);
	maxWidthdrawal = balance_;

	return maxWidthdrawal;
}

void BankAccount::recordWithdrawal( double amountToWithdraw) {
	//create a withdrawal transaction
    Transaction aTransaction( "withdrawal_from_ATM", -amountToWithdraw);
    //update active bankaccount
    transactions_.addNewTransaction( aTransaction);		//update transactions_
    updateBalance( -amountToWithdraw);					//decrease balance_
}

const string BankAccount::prepareFormattedStatement() const {
	ostringstream os;
	//account details
	os << prepareFormattedAccountDetails();
	//list of transactions (or message if empty)
	os << prepareFormattedTransactionList();
	return os.str();
}
void BankAccount::readInBankAccountFromFile( const string& fileName) {
	ifstream fromFile;
	fromFile.open( fileName.c_str(), ios::in); 	//open file in read mode
	if ( fromFile.fail())
		cout << "\nAN ERROR HAS OCCURED WHEN OPENING THE FILE.";
	else
        fromFile >> (*this);  	//read  all info from bank account file
    fromFile.close();			//close file: optional here
}

void BankAccount::storeBankAccountInFile( const string& fileName) const {
	ofstream toFile;
	toFile.open( fileName.c_str(), ios::out);	//open copy file in write mode
	if ( toFile.fail())
		cout << "\nAN ERROR HAS OCCURED WHEN OPENING THE FILE.";
	else
        toFile << (*this);	//store all info to bank account file
	toFile.close();			//close file: optional here
}
ostream& BankAccount::putDataInStream( ostream& os) const {
//put (unformatted) BankAccount details in stream
	putAccountDetailsInStream(os);			//put bank account core information in stream
	if ( transactions_.size() != 0)
		os << transactions_;				//put all transactions, one per line
	return os;
}
ostream& BankAccount::putAccountDetailsInStream(ostream& os) const {
	//put (unformatted) BankAccount details in stream
	os << accountType_ << "\n";				//put account type
	os << accountNumber_ << "\n";			//put account number
	os << sortCode_ << "\n";				//put sort code
	os << creationDate_ << "\n";			//put creation date
	os << balance_ << "\n";					//put balance
	return os;
}
istream& BankAccount::getDataFromStream( istream& is) {
//get BankAccount details from stream
	getAccountDataFromStream(is);			//get bank account ore information from stream
	is >> transactions_;					//get all transactions (if any)
	return is;
}
istream& BankAccount::getAccountDataFromStream(istream& is) {
	//get BankAccount details from stream
	is >> accountType_;						//get account type
	is >> accountNumber_;					//get account number
	is >> sortCode_;						//get sort code
	is >> creationDate_;					//get creation date
	is >> balance_;							//get balance
//	is >> transactions_;					//get transactions
	return is;
}
//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------
void BankAccount::updateBalance( double amount) {
    balance_ += amount;   //add/take amount to/from balance_
}
const string BankAccount::prepareFormattedAccountDetails() const {
	//collect account details in string
	ostringstream os;
	//account details
	os << "\nACCOUNT TYPE:    " << accountType_ << " ACCOUNT";						//display account type
	os << "\nACCOUNT NUMBER:  " << accountNumber_;									//display account number
	os << "\nSORT CODE:       " << sortCode_;										//display sort code
	os << "\nCREATION DATE:   " << creationDate_.toFormattedString();				//display creation date
	os << fixed << setprecision(2) << setfill(' ');
	os << "\nBALANCE:         \234" << setw(10) << balance_;	//display balance
	return os.str();
}
const string BankAccount::prepareFormattedTransactionList() const {
	ostringstream os;
	//list of transactions (or message if empty)
	if ( ! transactions_.size() == 0)
		os << "\n\nLIST OF TRANSACTIONS \n"	<< transactions_.toFormattedString();	//one per line
	else
		os << "\n\nNO TRANSACTIONS IN BANK ACCOUNT!";
	return os.str();
}


//---------------------------------------------------------------------------
//non-member operator functions
//---------------------------------------------------------------------------

ostream& operator<<( ostream& os, const BankAccount& aBankAccount) {
//put (unformatted) BankAccount details in stream
    return ( aBankAccount.putDataInStream( os));
}
istream& operator>>( istream& is, BankAccount& aBankAccount) {
//get BankAccount details from stream
	return ( aBankAccount.getDataFromStream( is));
}
