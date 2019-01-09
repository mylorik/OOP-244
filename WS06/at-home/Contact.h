///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/05          
///////////////////////////////////////////////////////////

#ifndef CONTACT_H
#define CONTACT_H

namespace sict {
    class Contact {
        char contact_name_[21]{};
        long long* contact_phone_numbers_;
        int count_total_numbers_;
    public:
        Contact();
        Contact(const char* name, const long long* phone_numbers, int count_total_numbers);
        ~Contact();
		bool isEmpty() const;
        void display() const;
    	Contact(const Contact& contact);
        Contact& operator=(const Contact&);
        Contact& operator+=(const long long phoneNumber);
    };
}
#endif
