///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////
#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__

#include "iAccount.h"
namespace sict
{
	class Account : public iAccount
	{
		double account_balance;
	public:
		Account(double);
		bool credit(double) override;
		bool debit(double) override;
	protected:
		double balance() const;
	};
}
#endif
