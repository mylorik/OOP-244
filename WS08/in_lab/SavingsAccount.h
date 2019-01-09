///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////
#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"
#include <iostream> 

namespace sict
{
	class SavingsAccount : public Account
	{
		double interestRate;
	public:
		SavingsAccount(double, double);
		void monthEnd() override;
	    void display(std::ostream &os) const override;
	};
}
#endif
