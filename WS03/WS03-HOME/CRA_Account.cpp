///////////////////////////////////////////////////////////
// Name			Date		              Reason
// Artem       2018/05/31          
///////////////////////////////////////////////////////////

#include <iostream>
#include "CRA_Account.h"
#include <cstring>
#include <iomanip>


using namespace std;

namespace sict{
    CRA_Account::CRA_Account(){
        sin_ = 0;
        *family_name_ = '\0';
        *given_name_ = '\0';
		*balance_ = '\0';
		*year_ =  '\0';
		years_ = '\0';
    }

    void CRA_Account::set(const char *familyName, const char *givenName, int sin) {
       //FIX IT
    	strcpy(family_name_, familyName);
        strcpy(given_name_, givenName);
        sin_ = sin;
        if(!isEmpty()){
            *given_name_ = '\0';
            *family_name_ = '\0';
		    *year_ = '\0';
            *balance_ = '\0';
            sin_ = 0;
		    years_ = 0;
        }
    }

	   void CRA_Account::set(int year, double balance) {
        if(isEmpty()){
            year_[years_] = year;
            balance_[years_] = balance;
            years_++;
        }
    }


 bool CRA_Account::isEmpty() const {
        auto temp_sin = sin_;
        int alternate_num[4];
        int sum_digits1[4];
        int sum_digits2[4];
        auto less_ten_total = 0;
        auto greater_then_total = 0;
       

	 if (sin_ >= MAX_SIN || sin_ <= MIN_SIN) {
            return false;
        } 
     if(*given_name_ == '\0'|| *family_name_ == '\0')
    	{
    		return false;
    	}
	 int sin_array[9];
	 for (auto i = 0; i <= 9; i++) {
		 sin_array[i] = temp_sin % 10;
		 temp_sin /= 10;
	 }

	 alternate_num[0] = sin_array[7] * 2; 
	 alternate_num[1] = sin_array[5] * 2;
	 alternate_num[2] = sin_array[3] * 2;
	 alternate_num[3] = sin_array[1] * 2;
	 alternate_num[4] = '\0';

	 for (int j = 0; j < 4; j++) {
		 if (alternate_num[j] > 10) {
			 sum_digits1[j] = alternate_num[j] % 10 + 1; 
			 greater_then_total += sum_digits1[j];
		 } else if (alternate_num[j] == 10) {
			 sum_digits2[j] = 1;
			 less_ten_total += sum_digits2[j];
		 } else if (alternate_num[j] < 10) {
			 sum_digits2[j] = alternate_num[j];
			 less_ten_total += sum_digits2[j];
		 } else {
			 sum_digits2[j] = '\0';
		 }
	 }

	 const auto other_total = sin_array[8] + sin_array[6] + sin_array[4] + sin_array[2];
	 const auto total = (greater_then_total + less_ten_total) + other_total;
	 const auto check_num = (total / 10 + 1) * 10 - total;

	 return check_num == sin_array[0];
    }


 void CRA_Account::display() const {
		if(isEmpty()){
            cout << "Family Name: " << family_name_ << endl;
            cout << "Given Name : " << given_name_ << endl;
            cout << "CRA Account: " << sin_ << endl;
            if(*year_ != '\0' && *balance_ != '\0'){
                for(int i = 0; i < years_; i++){
                    if(balance_[i] > 2){
						cout <<"Year (" <<year_[i]<<") balance owing: " << std::fixed << std::setprecision(2) << balance_[i] << endl;
                    }else if(balance_[i] < -2){
						cout <<"Year (" <<year_[i]<<") refund due: "<< std::fixed <<  std::setprecision(2) << -balance_[i] << endl;
                    }else{
                        cout << "Year (" << year_[i] << ") No balance owing or refund due!" << endl;
                    }
                }
            } else{
                cout << "Account object is empty!" << endl;
            }
		  }else{
            cout << "Account object is empty!" << endl;
        }
      
    }
    }
