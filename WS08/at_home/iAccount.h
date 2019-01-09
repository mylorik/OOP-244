// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: iAccount.h
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file defines the iAccount interface
///////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/19       
///////////////////////////////////////////////////////////

#ifndef SICT_IACCOUNT_H__
#define SICT_IACCOUNT_H__

#include <iostream> 

namespace sict
{
	class iAccount
	{
	public:
		virtual ~iAccount() = default;
		virtual bool credit(double) = 0;
		virtual bool debit(double) = 0;
		virtual void monthEnd() = 0;
		virtual	void display(std::ostream &os) const = 0;
	};
	iAccount* CreateAccount(const char*, double);
}
#endif

