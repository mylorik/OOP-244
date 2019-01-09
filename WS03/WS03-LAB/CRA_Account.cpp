///////////////////////////////////////////////////////////
// Name			Date		              Reason
// Artem       2018/05/31          
///////////////////////////////////////////////////////////

#include <iostream>
#include "CRA_Account.h"
#include <cstring>

using namespace std;
namespace sict{
    CRA_Account::CRA_Account(){
        sin_ = 0;
        *family_name_ = '\0';
        *given_name_ = '\0';
    }

    void CRA_Account::set(const char *familyName, const char *givenName, int sin) {
       
    	strcpy(family_name_, familyName);
        strcpy(given_name_, givenName);
        sin_ = sin;
        if(!isValid()){
            *given_name_ = '\0';
            *family_name_ = '\0';
            sin_ = 0;
        }
    }

    bool CRA_Account::isValid() const {
	    const bool sinTF = !(sin_ >= MAX_SIN || sin_ <= MIN_SIN);
	    return sinTF;
    }

    void CRA_Account::display() const {
        if(isValid()){
            cout << "Family Name: " << family_name_ << endl;
            cout << "Given Name : " << given_name_ << endl;
            cout << "CRA Account: " << sin_ << endl;
        }else{
            cout << "Account object is empty!" << endl;
        }
    }
}