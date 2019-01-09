// TODO: add file header comments here
///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/06/07          
///////////////////////////////////////////////////////////


#include <iostream>
#include "Passenger.h"
#include <cstring>

using namespace std;

// TODO: continue your namespace here

namespace sict {
// TODO: implement the default constructor here
	Passenger::Passenger() {
		*name_ = '\0';
		*destination_ = '\0';
	}

	// TODO: implement the constructor with 2 parameters here
	Passenger::Passenger(const char *name, const char* destination) {
		if (name == '\0' || destination == '\0' ){
			*name_ = '\0';
			*destination_ = '\0';
		}else if(name == nullptr && destination == nullptr){
			*name_ = '\0';
			*destination_ = '\0';
		} else {
			strcpy(name_, name);
			strcpy(destination_, destination);
		}
	}

	// TODO: implement isEmpty query here
	bool Passenger::isEmpty() const {
		if (*name_ == '\0' || *destination_ == '\0' || name_ == nullptr || destination_ == nullptr) {
			return true;
		}
		return false;
	}

	// TODO: implement display query here
	void Passenger::display() const {
		if(!isEmpty())
		cout << name_ << " - " << destination_ << endl;
		else
			cout <<"No passenger!\r" << endl;
	}
}
   