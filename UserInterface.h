//Pascale Vacher - March 15
//OOP Assignment Semester 2

#ifndef UserInterfaceH 
#define UserInterfaceH

//---------------------------------------------------------------------------
//UserInterface: class declaration
//---------------------------------------------------------------------------

#include "constants.h"
#include "Date.h"
#include "Time.h"

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class UserInterface {
public:
    void	showWelcomeScreen() const;
    void	showByeScreen() const;

	int		readInCardIdentificationCommand() const;
	int		readInAccountProcessingCommand() const;

	void	showErrorInvalidCommand() const;
    void	wait() const;
	const string	readInCardToBeProcessed( string& cardNum) const;
    void	showValidateCardOnScreen( int validCode, const string& cardNum) const;
	void	showCardOnScreen( const string& cardSt) const;
	const string  readInAccountToBeProcessed( string& aNum, string& sCod) const;
	void	showValidateAccountOnScreen( int valid, const string& aNum, const string& sCod) const;

    double	readInWithdrawalAmount() const;
    double	readInDepositAmount() const;

    void	showProduceBalanceOnScreen( double bal) const;
    void	showDepositOnScreen( bool auth, double deposit) const;
    void	showWithdrawalOnScreen( bool auth, double withdrawal) const;
    void	showStatementOnScreen( const string&) const;

	void showAllDepositsOnScreen(bool noTransaction, const string& str, double total) const;
	void showMiniStatementOnScreen(bool noTransaction, const string& str, double total) const;
	void showSearchMenu() const;
	void showMatchingTransactionsOnScreen(bool noTransaction, const string&str, double total) const;
	void showTransactionsForTitle(bool noTransactions, string title, string str, int n) const;
	int readInNumberOfTransactions() const;
	void showNoTransactionsOnScreen() const;
	int readInSearchCommand() const;
	int readInAmount() const;
	string readInTitle() const;
	Date readInvalidDate(Date& d) const;
	void showTransactionsUpToDate(bool noTransaction, Date& d, int n, const string& str) const;
	bool readInConfirmDeletion() const;
	void showDeletionUpToDate(int n, Date d, bool de) const;
	void showFundsAvailableOnScreen(bool empty, double m) const;


	double readInTransferAmount() const;
	void	showTransferResultOnScreen(bool trOutOK, bool trInOK, double transferAmount) const;

private:
    //support functions
	void	showCardIdentificationMenu() const;
	void	showAccountProcessingMenu() const;
    int		readInCommand() const;
    double	readInPositiveAmount() const;
	bool	readInValidConfirmation() const;
};

#endif
