// TODO: add file header comments here
///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/06/07          
///////////////////////////////////////////////////////////

// TODO: add header file guard here
#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
// TODO: declare your namespace here

namespace sict {
// TODO: define the Passenger class here
	class Passenger {
			char name_[33];
			char destination_[33];
		public:
			Passenger();
			Passenger(const char *PassengerName, const char* PassengerDestination);
			bool isEmpty() const;
			void display() const;
	};
}
#endif // SICT_PASSENGER_H_

