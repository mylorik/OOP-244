///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05          
///////////////////////////////////////////////////////////

// Final Project Milestone 1
//

#ifndef AMA_DATE_H__
#define AMA_DATE_H__

namespace AMA
{
#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3
#define DAY_ERROR 4

	const int min_year = 2000;
	const int max_year = 2030;

	class Date
	{
		int year_;
		int month_;
		int day_;
		int error_code_;

		int value_formula() const; // just simplifying my code
		bool validation_check(int year, int month, int day); // just simplifying my code

		void errCode(int errorCode);
		int mdays(int mon, int year) const;

	public:

		Date();
		Date(int year, int month, int day);

		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
		bool operator<(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;

		int errCode() const;
		bool bad() const;

		std::istream& read(std::istream& istr);
		std::ostream& write(std::ostream& ostr) const;
	};

	std::istream& operator>>(std::istream& istr, Date& date);
	std::ostream& operator<<(std::ostream& ostr, const Date& date);
}
#endif
