///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/20          
///////////////////////////////////////////////////////////

#ifndef ERRORSTATE
#define ERRORSTATE

#include <iostream>

namespace AMA
{
	class ErrorState
	{
		char* message_;
	public:
		explicit ErrorState(const char* errorMessage = nullptr);
		ErrorState(const ErrorState& em) = delete;
		ErrorState& operator=(const ErrorState& em) = delete;
		virtual ~ErrorState();

		void clear();
		bool isClear() const;
		void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif
