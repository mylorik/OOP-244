///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////
#include "Account.h"

namespace sict
{
	Account::Account(double e_balance)
	{
		if (e_balance >= 0)
		{
			account_balance = e_balance;
		}
		else
		{
			account_balance = 0.0;
		}
	};

	bool Account::credit(double e_credit)
	{
		if (e_credit > 0)
		{
			account_balance += e_credit;
			return true;
		}
		return false;
	};

	bool Account::debit(double e_debit)
	{
		if (account_balance < e_debit)
		{
			return false;
		}
		account_balance -= e_debit;
		return true;
	};

	double Account::balance() const
	{
		return account_balance;
	}
}
