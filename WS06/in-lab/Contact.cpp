///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05          
///////////////////////////////////////////////////////////

#include <iostream>
#include "Contact.h"
#include <string>
#include <iomanip>
#include <cstring>

using namespace std;

namespace sict {
    Contact::Contact() {
        contact_name_[0] = '\0';
        contact_phone_numbers_ = nullptr;
        count_total_numbers_ = 0;
    }

    bool Contact::isEmpty() const {
	    return contact_name_[0] != '\0' || contact_phone_numbers_ != nullptr;
    }

    Contact::~Contact() {
        delete[] contact_phone_numbers_;
        contact_phone_numbers_ = nullptr;
    }

    Contact::Contact(const char *name, const long long* phone_numbers, const int count_total_numbers) {
        if (name != nullptr) {
            if (isEmpty()) {
                strncpy(contact_name_, name,19);
                count_total_numbers_ = count_total_numbers;

                if (count_total_numbers_ > 0) {
	                const auto new_phone_numebr = new long long[count_total_numbers_];
                    for (auto i = 0; i < count_total_numbers_; i++) {
                        new_phone_numebr[i] = phone_numbers[i];
                    }
                    contact_phone_numbers_ = new_phone_numebr;
                }else{
                    contact_phone_numbers_ = nullptr;
                }
            } else {
                for (auto& contact_name : contact_name_)
                {
	                contact_name = '\0';
                }
                contact_phone_numbers_ = nullptr;
                count_total_numbers_ = 0;
            }
        } else {
            for (auto& i : contact_name_)
            {
	            i = '\0';
            }
            contact_phone_numbers_ = nullptr;
            count_total_numbers_ = 0;
        }
    }
    void Contact::display() const{
        if (!isEmpty()) {
            cout << "Empty contact!" << endl;
        }else{
	    cout <<  contact_name_ << endl; 
            for(auto i = 0; i < count_total_numbers_; i++){	        
	            const auto check = int(contact_phone_numbers_[i]/10000000);

	            if(std::to_string(check).length() < 4 || 
					std::to_string(check).length() > 5 ||
					std::to_string(check)[0] == '0')
					continue;

					cout.fill('0');
                    cout << "(+" << check / 1000 << ")" << " " << check % 1000 << " " << contact_phone_numbers_[i]/10000 % 1000
                         << "-" << setw(4) << contact_phone_numbers_[i] % 10000 << endl;
            }
        }
    }
}