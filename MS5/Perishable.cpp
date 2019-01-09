///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#include <iostream>
#include "Perishable.h"
using namespace std;

namespace AMA
{

Perishable::Perishable() : Product('P')
	{
		clear(); // safe empty state.
	}

	std::fstream & Perishable::store(std::fstream & file, bool newLine) const
	{
		Product::store(file, false); //false mens No "newLine" inside "Product::write"
		file << ',' << perishable_date_ << endl;

		return file;
	}
	std::fstream & Perishable::load(std::fstream & file)
	{
		Product::load(file);
		perishable_date_.read(file);
		file.ignore();

		return file;
	}
	std::ostream & Perishable::write(std::ostream & os, bool linear) const
	{
		Product::write(os, linear); 

		if (isClear() && !isEmpty())
		{
			if (linear)
				return perishable_date_.write(os);

				os << "\n Expiry date: ";
				return perishable_date_.write(os);
		}
		return os;
	}
	std::istream & Perishable::read(std::istream & is)
	{
		is.clear();
		clear();
		Product::read(is);

		if (error_state_.isClear()) 
		{
			cout << " Expiry date (YYYY/MM/DD): ";
			perishable_date_.read(is);
		}

		if (perishable_date_.errCode() == CIN_FAILED)
		{		
			message("Invalid Date Entry");
		}

		if (perishable_date_.errCode() == YEAR_ERROR)
		{
			message("Invalid Year in Date Entry");
		}

		if (perishable_date_.errCode() == MON_ERROR)
		{
			message("Invalid Month in Date Entry");
		}

		if (perishable_date_.errCode() == DAY_ERROR)
		{
			message("Invalid Day in Date Entry");
		}

		if (perishable_date_.errCode())
		{
			is.setstate(std::ios::failbit);
		}

		return is;
	}

	const Date & Perishable::expiry() const
	{
		return perishable_date_;
	}
}