///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/06/14          
///////////////////////////////////////////////////////////

// TODO: insert header files
#include <iostream>
#include "Fraction.h"

// TODO: continue the namespace
using namespace std;
using namespace sict;

	// TODO: implement the default constructor
    Fraction::Fraction() {
        numerator_ = 0;
        denominator_ = 0;
    }

	// TODO: implement the two-argument constructor
	    Fraction::Fraction(const int numerator, const int denominator){
        if(numerator > 0  && denominator > 0){
            numerator_ = numerator;
            denominator_ = denominator;
            reduce();
        }else{
            denominator_ = 0;
            numerator_ = 0;
        }
    }

	// TODO: implement the max query
	 int Fraction::max() const
	 {
        if (numerator_ > denominator_) return numerator_;
		 return denominator_;
	 }

    // TODO: implement the min query
	    int Fraction::min() const
	    {
        if (numerator_ > denominator_) return denominator_;
         return numerator_;
		}


	// gcd returns the greatest common divisor of num and denom
    //
    int Fraction::gcd() const {
        int mn = min();  // min of numerator and denominator
        int mx = max();  // max of numerator and denominator
        int g_c_d = 1;
        bool found = false;

        for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
            if (mx % x == 0 && mn % x == 0) {
                found = true;
                g_c_d = x;
            }
        }
        return g_c_d;
    }

    // TODO: implement the reduce modifier
    void Fraction::reduce() {
	    const auto reduce = gcd();
        numerator_ /= reduce;
        denominator_ /= reduce;
    }
	
    // TODO: implement the display query
	    void Fraction::display() const {
        if(isEmpty()){
            cout << "no fraction stored";
        } else {
            if(denominator_ == 1){
                cout << numerator_;
            } else {
                cout << numerator_ << "/" << denominator_;
            }
        }
    }

    // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const {
        return denominator_ == 0;
    }
    // TODO: implement the + operator
		Fraction Fraction::operator+(const Fraction & rhs) const
	{
		Fraction fraction;
        if(!rhs.isEmpty()) {
            fraction.numerator_ = denominator_ *rhs.numerator_ + numerator_ * rhs.denominator_;
            fraction.denominator_ = denominator_ * rhs.denominator_;
        }
        return fraction;
	}

