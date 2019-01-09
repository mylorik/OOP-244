// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////

#include "ChequingAccount.h"
#include<iostream>
#include<iomanip>
using namespace std;
using namespace std;

namespace sict
{
	ChequingAccount::
	ChequingAccount(const double c_balance, const double c_transcation_fee, const double month_end_fee): Account(c_balance)
	{
		if (c_transcation_fee < 0)transaction_fee_ = 0;
		else
		{
			transaction_fee_ = c_transcation_fee;
			month_end_fee_ = month_end_fee;
		}
	}

	bool ChequingAccount::credit(const double credit_amount)
	{
	return Account::credit(credit_amount - transaction_fee_ - transaction_fee_);
	}

	bool ChequingAccount::debit(const double debit_amount)
	{
		return Account::debit(debit_amount);
	}

	void ChequingAccount::display(std::ostream& os) const
	{
		os << fixed << setprecision(2);
		os << "Account type: Chequing" << endl;
		os << "Balance: $" << balance() << endl;
		os << "Per Transaction Fee: " << transaction_fee_ << endl;
		os << "Monthly Fee: " << month_end_fee_ << endl;
	}

	void ChequingAccount::monthEnd()
	{
		debit(month_end_fee_ + transaction_fee_);
	}
}
