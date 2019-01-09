// TODO: add file header comments here
///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/06/07          
///////////////////////////////////////////////////////////


#include <iostream>
#include "Passenger.h"
#include <cstring>
#include<stdio.h>

using namespace std;

// TODO: continue your namespace here

namespace sict {
// TODO: implement the default constructor here
	Passenger::Passenger() {
		*name_ = '\0';
		*destination_ = '\0';
		year_of_departure_ = 0;
		month_of_departure_ = 0;	
		day_of_departure_ = 0;
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char* destination) {
		if (name == '\0' || destination == '\0' || (name == nullptr && destination == nullptr)){
			*name_ = '\0';
			*destination_ = '\0';
			year_of_departure_ = 0;
			month_of_departure_ = 0;	
			day_of_departure_ = 0;
		}else {
			strcpy(name_, name);
			strcpy(destination_, destination);
			year_of_departure_ = 2017;
			month_of_departure_ = 7;	
			day_of_departure_ = 1;
		}
	}

	 //Overloading 5
		Passenger::Passenger(const char *PassengerName, const char *PassengerDestination, int years, int months, int days) {
		if(PassengerName != nullptr && strlen(PassengerName) > 0 &&
				PassengerDestination != nullptr && strlen(PassengerDestination) > 0 &&
				years >= 2017 && years <= 2020 && months >= 1 && months <=12 &&
				days >= 1 && days <= 31){
			strcpy(name_, PassengerName);
			strcpy(destination_, PassengerDestination);
			year_of_departure_ = years;
			month_of_departure_ = months;
			day_of_departure_ = days;
		}else{
			*name_ = '\0';
			*destination_ = '\0';
			year_of_departure_ = 0;
			month_of_departure_ = 0;
			day_of_departure_ = 0;
		}
	}

	/*
	bool Passenger::dateCheck() const {
		return (name_ != nullptr && strlen(name_) > 0 &&
				destination_ != nullptr && strlen(destination_) > 0 &&
				year_of_departure_ >= 2017 && year_of_departure_ <= 2020 && month_of_departure_ >= 1 && month_of_departure_ <=12 &&
				day_of_departure_ >= 1 && day_of_departure_ <= 31);
	}*/


	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		return (*name_ == '\0' || *destination_ == '\0' || name_ == nullptr || destination_ == nullptr);
	}

	// TODO: implement display query here
		void Passenger::display() const {
		cout << name_ << " - " << destination_ << " on " << year_of_departure_ << "/";
        if(month_of_departure_ < 10) {
            cout << "0" << month_of_departure_ << "/";
            if (day_of_departure_ < 10) {
                cout << day_of_departure_ << endl;
            } else {
                cout << day_of_departure_ << endl;
            }
        } else {
            cout << month_of_departure_ << day_of_departure_ << endl;
		}
		}

	const char* Passenger::name() const {
        return name_;
	}

	bool Passenger::canTravelWith(const Passenger& passenger) const{
	return strcmp(passenger.destination_, destination_) == 0 &&
			strcmp(passenger.destination_, destination_) == 0 &&
			passenger.year_of_departure_ == year_of_departure_ &&
			passenger.month_of_departure_ == month_of_departure_ &&
			passenger.day_of_departure_ == day_of_departure_ ;	
	}

}

   