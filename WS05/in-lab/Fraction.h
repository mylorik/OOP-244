///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/06/14          
///////////////////////////////////////////////////////////

// TODO: header file guard
#ifndef FRACTION_H_
#define FRACTION_H_

// TODO: create namespace
using namespace std;
namespace sict {
	// TODO: define the Fraction class
	class Fraction {
		// TODO: declare instance variables 
	    int numerator_;
        int denominator_;

		// TODO: declare private member functions
		int gcd() const;
        int max() const;
        int min() const;
		void reduce();

	public:
	 	// TODO: declare public member functions
		Fraction();
        Fraction( int numerator, int denominator);

	    void display() const;
        bool isEmpty() const;

		// TODO: declare the + operator overload
		Fraction operator+(const Fraction& rhs) const;
	};
	}
#endif //FRACTION_H_