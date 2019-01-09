///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////

#ifndef SICT_CHEQUINGACCOUNT_H__
#define SICT_CHEQUINGACCOUNT_H__

#include "Account.h"

namespace sict
{
	class ChequingAccount : public Account
	{
		double transaction_fee_;
		double month_end_fee_;
	public:
		ChequingAccount(double, double, double);
		bool credit(double) override;
		bool debit(double) override;
		void display(std::ostream&) const override;
		void monthEnd() override;
	};
}
#endif
