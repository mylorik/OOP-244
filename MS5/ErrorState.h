///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/20          
///////////////////////////////////////////////////////////

#ifndef AMA_ERRORSTATE_H__
#define AMA_ERRORSTATE_H__

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
		virtual bool isClear() const;
		virtual void message(const char* str);
		const char* message() const;
	};
	std::ostream& operator<<(std::ostream&, const ErrorState&);
}
#endif
