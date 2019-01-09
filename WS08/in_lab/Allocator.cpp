///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////
#include "SavingsAccount.h"

namespace sict
{
	double interact = 0.05;
	iAccount* CreateAccount(const char* type, double amount)
	{
		auto *Account = new SavingsAccount(amount, interact);
			return Account;
	}
}
