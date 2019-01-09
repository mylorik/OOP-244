///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict
{
	double interact = 0.05;
	double transaction_fee = 0.50;
	double monthly_fee = 2.00;

	iAccount* CreateAccount(const char* type, const double amount)
	{
		if(type[0] == 'S'){
		auto *account = new SavingsAccount(amount, interact);
			return account;
		}
		if(type[0] == 'C')
		{
			auto *account = new ChequingAccount(amount,transaction_fee, monthly_fee );
			return account;
		}
		return nullptr;
	}
}
