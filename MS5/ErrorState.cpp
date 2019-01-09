///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/20          
///////////////////////////////////////////////////////////

#include <cstring>
#include "ErrorState.h"
using namespace std;

namespace AMA
{
	ErrorState::ErrorState(const char* errorMessage)
	{
		message_ = nullptr;
		if (errorMessage != nullptr)
			ErrorState::message(errorMessage);
	}

	ErrorState::~ErrorState()
	{
		delete[] message_;
		message_ = nullptr;
	}

	void ErrorState::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}

	bool ErrorState::isClear() const
	{
		return message_ == nullptr;
	}

	void ErrorState::message(const char* str)
	{
		delete[] message_;
		message_ = nullptr;
		message_ = new char[strlen(str) + 1];
		strcpy(message_, str);
	}

	const char* ErrorState::message() const
	{
		return message_;
	}


	std::ostream& operator<<(std::ostream& os, const ErrorState& e)
	{
		if (!e.isClear())
		{
			os << e.message();
		}
		return os;
	}
}
