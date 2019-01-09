///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////

#include <iomanip>
#include "SavingsAccount.h"
#include <iostream>

using namespace std;

namespace sict
{
	SavingsAccount::SavingsAccount(double e_balance, double e_interest): Account(e_balance)
	{
		if (e_interest < 0)
		{
			interestRate = 0;
		}
		else
		{
			interestRate = e_interest;
		}
	};


	void SavingsAccount::monthEnd()
	{
		const auto pay_back = balance() *interestRate;
		credit(pay_back);	
	}

	void SavingsAccount::display(std::ostream& os) const
	{
		os << std::fixed << std::setprecision(2)
			<< "Account type: Savings" << std::endl
			<< "Balance: $" << balance() << std::endl
			<< "Interest Rate (%): " << interestRate * 100 << std::endl;
	}
}
