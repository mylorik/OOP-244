///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05         
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Date.h"
#include <iomanip>

namespace AMA
{
	Date::Date()
	{
		year_ = 0;
		month_ = 0;
		day_ = 0;
		error_code_ = NO_ERROR;
	}

	Date::Date(const int year, const int month, const int day)
	{
		if (validation_check(year, month, day))
		{
			year_ = year;
			month_ = month;
			day_ = day;
			error_code_ = NO_ERROR;
		}
		else
			Date();
	}

	int Date::value_formula() const
	{
		return year_ * 372 + month_ * 31 + day_;
	}

	bool Date::validation_check(const int year, const int month, const int day)
	{	
		if (year > max_year || year < min_year)
		{
			errCode(YEAR_ERROR);
			return false;
		}
		if (month > 12 || month < 1)
		{
			errCode(MON_ERROR);
			return false;
		}
		if (day > mdays(month, year))
		{
			errCode(DAY_ERROR);
			return false;
		}
		
		return true;
	}

	int Date::errCode() const
	{
		return error_code_;
	}

	int Date::mdays(const int mon, const int year) const
	{
		int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1};
		auto month = mon >= 1 && mon <= 12 ? mon : 13;
		month--;
		return days[month] + int((month == 1) * (year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
	}

	bool Date::operator==(const Date& rhs) const
	{
		return this->value_formula() == rhs.value_formula();
	}

	bool Date::operator!=(const Date& rhs) const
	{
		return this->value_formula() != rhs.value_formula();
	}

	bool Date::operator<(const Date& rhs) const
	{
		return this->value_formula() < rhs.value_formula();
	}

	bool Date::operator>(const Date& rhs) const
	{
		return this->value_formula() > rhs.value_formula();
	}

	bool Date::operator<=(const Date& rhs) const
	{
		return this->value_formula() <= rhs.value_formula();
	}

	bool Date::operator>=(const Date& rhs) const
	{
		return this->value_formula() >= rhs.value_formula();
	}

	void Date::errCode(int errCode)
	{
		error_code_ = errCode;
	}

	bool Date::bad() const
	{
		return error_code_ != 0;
	}

	std::istream& Date::read(std::istream& istr)
	{
		char input;
		errCode(NO_ERROR);
		istr >> year_ >> input >> month_ >> input >> day_;
		if (istr.fail() || std::cin.fail())
		{
			*this = Date();
			errCode(CIN_FAILED);
		}
		else if(!validation_check(year_, month_, day_))
		{
			istr.clear();
			return istr;
		}

		istr.clear();
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr) const
	{
		if (year_ > max_year || year_ < min_year || month_ > 12 || month_ < 1 || day_ > mdays(month_, year_))
		{
			ostr << "0/00/00";
		}
		else
		{
			// I had to use "std::setfill" otherwise with using "ostr.fill" it would set garbage values.
			ostr << year_
				<< "/"
				<< std::setw(2)
				<< std::setfill('0')
				<< month_
				<< "/"
				<< std::setw(2)
				<< std::setfill('0')
				<< day_
				<< std::setfill(' ');
		}
		return ostr;
	}

	std::istream& operator >>(std::istream& istr, Date& date)
	{
		return date.read(istr);
	}

	std::ostream& operator <<(std::ostream& ostr, const Date& date)
	{
		return date.write(ostr);
	}
}
