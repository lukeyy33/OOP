//Pascale Vacher - March 15
//OOP Assignment Semester 2

#include "UserInterface.h" 

//---------------------------------------------------------------------------
//UserInterface: class implementation
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
//public member functions
//---------------------------------------------------------------------------

//____constructors & destructors

//____other public member functions

//menu functions

void UserInterface::wait() const {
	char ch;
	cout << "\n\nPress RETURN to go back to menu\n";
	cin.get( ch);
	cin.get( ch);
//	flushall();
}
int UserInterface::readInCardIdentificationCommand() const {
    showCardIdentificationMenu();
    return ( readInCommand());
}
void UserInterface::showCardIdentificationMenu() const {
	cout << "\n\n\n ________________________________________";
	cout << "\n     ________CARD IDENTIFICATION MENU________";
	cout << "\n     ________________________________________";
	cout << "\n       0           Quit CashPoint application";
	cout << "\n       1              Enter your card details";
	cout << "\n     ________________________________________";
}
int UserInterface::readInAccountProcessingCommand() const{
    showAccountProcessingMenu();
    return ( readInCommand());
}
void UserInterface::showAccountProcessingMenu() const {
	cout << "\n\n\n ________________________________________";
	cout << "\n     ________ACCOUNT PROCESSING MENU_________";
	cout << "\n     ________________________________________";
	cout << "\n       0 End account processing & remove card";
	cout << "\n       1                      Display balance";
	cout << "\n       2                Withdraw from account";
	cout << "\n       3                 Deposit into account";
	cout << "\n       4                       Show statement";
	cout << "\n       5                    Show all deposits";
	cout << "\n       6                  Show mini statement";
	cout << "\n       7                  Search Transactions";
	cout << "\n       8    Clear all transactions up to date";
	cout << "\n       9                 Show Funds Available";
	cout << "\n       10         Transfer to another account";
	cout << "\n     ________________________________________";
}

const string UserInterface::readInCardToBeProcessed( string& aCardNumber) const {
	cout << "\n SELECT THE CARD ...\n";
	cout << "   CARD NUMBER:  ";         //ask for card number
    cin >> aCardNumber;
    cout << "\n=========================================";
    //create card file name
    return( FILEPATH + "card_" + aCardNumber + ".txt");
}

void UserInterface::showValidateCardOnScreen( int validCode, const string& cashCardNum) const {
    switch( validCode)
    {
    	case VALID_CARD:		//card valid: it exists, is accessible with that card (and not already open: TO BE IMPLEMENTED)
			cout << "\nTHE CARD (NUMBER: " << cashCardNum << ") EXIST!";
            break;
    	case UNKNOWN_CARD:		//card does not exist
			cout << "\nERROR: INVALID CARD\n"
                 << "\nTHE CARD (NUMBER: " << cashCardNum << ") DOES NOT EXIST!";
            break;
    	case EMPTY_CARD:		//account exists but is not accessible with that card
        	cout << "\nERROR: EMPTY CARD"
                  << "\nTHE CARD (NUMBER: " << cashCardNum << ") DOES NOT LINK TO ANY ACCOUNT!";
             break;
    }
}

void UserInterface::showCardOnScreen( const string& aCardDetails) const {
    cout << "\n=========================================";
    cout << "\n________ CARD DETAILS ___________________";
	cout << aCardDetails;
    cout << "\n________ END CARD DETAILS _______________";
    cout << "\n=========================================";
}

const string UserInterface::readInAccountToBeProcessed( string& anAccountNumber, string& aSortCode) const {
    cout << "\n SELECT THE ACCOUNT ...\n";
	cout << "   ACCOUNT NUMBER:  ";	//ask for account number
    cin >> anAccountNumber;
	cout << "   SORT CODE:       ";	//ask for sort code
    cin >> aSortCode;
    cout << "\n=========================================";
    //create account file name
    return( FILEPATH + "account_" + anAccountNumber + "_" + aSortCode + ".txt");
}

void UserInterface::showValidateAccountOnScreen( int validCode, const string& accNum, const string& srtCode) const {
    switch( validCode)
    {
    	case VALID_ACCOUNT:		//account valid: it exists, is accessible with that card (and not already open: TO BE IMPLEMENTED)
        	cout << "\nTHE ACCOUNT (NUMBER: " << accNum
             	 << " CODE: " << srtCode << ") IS NOW OPEN!";
            break;
    	case UNKNOWN_ACCOUNT:		//account does not exist
        	cout << "\nERROR: INVALID ACCOUNT"
                 << "\nTHE ACCOUNT (NUMBER: " << accNum
                 << " CODE: " << srtCode << ") DOES NOT EXIST!";
            break;
    	case UNACCESSIBLE_ACCOUNT:		//account exists but is not accessible with that card
        	cout << "\nERROR: INVALID ACCOUNT"
             	 << "\nTHE ACCOUNT (NUMBER: " << accNum
             	 << " CODE: " << srtCode << ") IS NOT ACCESSIBLE WITH THIS CARD!";
            break;
    }
}
void UserInterface::showAllDepositsOnScreen(bool noTransaction, const string& str, double total) const {
	if (noTransaction)
		cout << "\nNO TRANSACTION IN BANK ACCOUNT";
	else
		cout << "\nALL DEPOSIT TRANSACTIONS REQUESTED AT" << Time::currentTime()
		<< "ON " << Date::currentDate();
		cout << str;
		cout << "TOTAL DEPOSIT: \234" << total;
}
void UserInterface::showFundsAvailableOnScreen(bool empty, double m) const {
	
	cout << m << "\n COMING FROM USERINTERFACE::SHOWFUNDS ";
}
//input functions

double UserInterface::readInWithdrawalAmount() const {
    //ask for the amount to withdraw
    cout << "\nAMOUNT TO WITHDRAW: \234" ;
	return ( readInPositiveAmount() );
}
double UserInterface::readInDepositAmount() const {
    //ask for the amount to deposit
    cout << "\nAMOUNT TO DEPOSIT: \234" ;
	return ( readInPositiveAmount() );
}
int UserInterface::readInNumberOfTransactions() const {
	//ask for number of transactions
	cout << "\nNUMBER OF TRANSACTIONS: ";
	return (readInPositiveAmount() );
}
int UserInterface::readInSearchCommand() const {
	return (readInCommand());
}
int UserInterface::readInAmount() const {
	double a;
	cout << "\nAMOUNT TO SEARCH: \234";
	cin >> a;
	return a;
}
string UserInterface::readInTitle() const {
	string title;
	cout << "\nTITLE TO SEARCH BY: ";
	cin >> title;
	return title;
}
Date UserInterface::readInvalidDate(Date& d) const {

	cout << "\nDATE TO SEARCH BY: ";
	cin >> d;
	while (!d.isValid(d))
	{
		cout << "DATE NOT VALID - TRY AGAIN: ";
		cin >> d;
	}
	return d;
}
bool UserInterface::readInConfirmDeletion() const{
	cout << "\nARE YOU SURE YOU WANT TO DELETE THESE TRANSACTIONS? (Y/N): ";
	return (readInValidConfirmation());
}

double UserInterface::readInTransferAmount() const{
	cout << "\nEnter the amount to be transfered: \234";
	double amount;
	cin >> amount;
	return (amount);
}
//output functions

void UserInterface::showProduceBalanceOnScreen( double balance) const {
	cout << fixed << setprecision(2) << setfill(' ');
    cout << "\nTHE CURRENT BALANCE IS: \234" << setw(12) << balance;//display balance
}
void UserInterface::showWithdrawalOnScreen( bool trAuthorised, double amountWithdrawn) const {
    if ( trAuthorised)
    	cout << "\nTRANSACTION AUTHORISED!: \n\234"
             << setw(0) << amountWithdrawn
             << " WITHDRAWN FROM ACCOUNT";
    else //not enough money
		cout << "\nTRANSACTION IMPOSSIBLE!";
}
void UserInterface::showDepositOnScreen( bool trAuthorised, double amountDeposited) const {
    if ( trAuthorised)
    	cout << "\nTRANSACTION AUTHORISED!:\n\234"
             << setw(0) << amountDeposited
             << " DEPOSITED INTO ACCOUNT";
    else //too much to deposit
		cout << "\nTRANSACTION IMPOSSIBLE!";
}
void UserInterface::showStatementOnScreen( const string& statement) const {
    cout << "\nPREPARING STATEMENT...";
    cout << "\n________ ACCOUNT STATEMENT _____";
	cout << statement;
    cout << "\n________ END ACCOUNT STATEMENT _____";
}
void UserInterface::showMiniStatementOnScreen(bool noTransaction, const string& str, double total) const {
	cout << "\nRECENT TRANSACTIONS WERE REQUESTED AT "
		<< Time::currentTime().toFormattedString()
		<< "ON " << Date::currentDate().toFormattedString()
		<< "\n";
	if (noTransaction)
	{
		cout << "\nNO TRANSACTIONS IN BANK ACCOUNT";
	}
	else
	{
		cout << str;
		cout.setf(ios::fixed);
		cout << "\nTOTAL OF DISPLAYED TRANSACTIONS: " << static_cast<char>(156)
			 << setw(0) << setprecision(2) << total;
	}
	cout << "\n____________ END OF MINI STATEMENT_____________";
}
void UserInterface::showMatchingTransactionsOnScreen(bool noTransaction, const string&str, double total) const {
	if (noTransaction)
	cout << "\nNO TRANSACTIONS IN BANK ACCOUNT ";
	else
	{
		cout << str;
		cout.setf(ios::fixed);
		cout << "\nTRANSACTIONS\n" << static_cast<char>(156)
			 << setw(0) << setprecision(2) << total;
	}
	cout << "\nEND OF TRANSACTIONS\n";
}
void UserInterface::showTransactionsForTitle(bool noTransaction, string title, string str, int n) const {
	if (noTransaction)
		cout << "\nNO TRANSACTIONS IN BANK ACCOUNT ";
	else
	{
		cout << "\n" << str;
	}
}

void UserInterface::showSearchMenu() const {
	cout << "\n\t 1 Show transactions for amount ";
	cout << "\n\t 2 Show transactions for title ";
	cout << "\n\t 3 show transactions for Date \n";	
}
void UserInterface::showNoTransactionsOnScreen() const {
	cout << "\nNO TRANSACTIONS FOUND";
}

void UserInterface::showTransactionsUpToDate(bool noTransaction, Date& d, int n, const string& str) const {
	if (noTransaction)
	{
		cout << "\nNO TRANSACTIONS FOUND IN BANK ACCOUT\N";
		cout << "\N_________END OF ACCOUNT ENQUIRY_______";
	}
	else
	{
		if (n == 0)
		{
			cout << "\nNO TRANSACTIONS IN BANK ACCOUNT UP TO THIS DATE";
			cout << "\n________END OF ACCOUNT ENQUIRY________";
		}
		else
		{
			cout << "\n\n" << str;
		}
	}
}

void UserInterface::showTransferResultOnScreen(bool trOutOK, bool trInOK, double transferAmount) const
{
	if (trOutOK && trInOK)
	{
		cout << "\nTRANSFER SUCCESSFUL";
		cout << "\nAMOUNT TRANSFERRED: " << transferAmount;
	}
	else
	{
		cout << "\nTRANSFER FAILED";
	}

}
void UserInterface::showDeletionUpToDate(int n, Date d, bool de) const {

		if (de)
		{
			cout << "\nTHE " << n << " TRANSACTIONS IN BANK ACCOUNT UP TO DATE " << d << " HAVE BEEN DELETED";
		}
		else
			cout << "\nOPERATION CANCELLED - NO TRANSACTIONS HAVE BEEN DELETED";
}

//---------------------------------------------------------------------------
//private support member functions
//---------------------------------------------------------------------------

void UserInterface::showWelcomeScreen() const {
	cout << "\n\n\n             _____WELCOME TO THE ATM_____";
}
void UserInterface::showByeScreen() const {
    cout << "\n\n\n________________NEXT CUSTOMER...\n\n";
}
int UserInterface::readInCommand() const{
	int com;
	cout << "\n          ENTER YOUR COMMAND: ";
	cin >> com;
	return com;
}
void UserInterface::showErrorInvalidCommand() const {
	cout << "\nINVALID COMMAND CHOICE, TRY AGAIN";
}
double UserInterface::readInPositiveAmount() const {
    double amount;
	cin >> amount;
	while ( amount <= 0.0)
    {
	    cout << "\nAMOUNT SHOULD BE A POSITIVE AMOUNT, TRY AGAIN: ";
		cin >> amount;
	}
    return amount;
}
bool UserInterface::readInValidConfirmation() const{
	char confirm;
	cin >> confirm;
	while ((confirm != 'y') && (confirm != 'Y') && (confirm != 'n') && (confirm != 'N'))
	{
		cout << "INPUT NOT VALID - PLEASE ENTER Y or N: ";
		cin >> confirm;
	}
	if ((confirm == 'y') || (confirm == 'Y'))
		return true;
	else
		return false;
}
