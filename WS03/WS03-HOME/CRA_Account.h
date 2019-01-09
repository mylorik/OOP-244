///////////////////////////////////////////////////////////
// Name			Date		              Reason
// Artem       2018/05/31          
///////////////////////////////////////////////////////////
#ifndef CRA_ACCOUNT_H               
#define CRA_ACCOUNT_H 

#define MAX_NAME_LENGTH 41
#define MIN_SIN 100000000
#define MAX_SIN 999999999
#define MAX_YRS 4

using namespace std;

namespace sict{
    class CRA_Account{
      char family_name_[MAX_NAME_LENGTH]{};
      char given_name_[MAX_NAME_LENGTH]{};
      int sin_;
	  int year_[MAX_YRS]{};
      float balance_[MAX_YRS]{};
      int years_ = 0;
    public:
        CRA_Account();
	    bool isEmpty() const;
        void display() const;
        void set(const char* familyName, const char* givenName, int sin);
		void set(int year, double balance);
		
    };
}
#endif //CRA_ACCOUNT_H