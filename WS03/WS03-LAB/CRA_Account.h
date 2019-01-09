///////////////////////////////////////////////////////////
// Name			Date		              Reason
// Artem       2018/05/31          
///////////////////////////////////////////////////////////
#ifndef CRA_ACCOUNT_H               
#define CRA_ACCOUNT_H 


#include <iostream>
#define MAX_NAME_LENGTH 41
#define MIN_SIN 100000000
#define MAX_SIN 999999999

using namespace std;

namespace sict{
    class CRA_Account{
      char family_name_[MAX_NAME_LENGTH]{};
      char given_name_[MAX_NAME_LENGTH]{};
      int sin_;
    public:
        CRA_Account();
	    bool isValid() const;
        void display() const;
        void set(const char* familyName, const char* givenName, int sin);
    };
}
#endif //CRA_ACCOUNT_H