///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////

#include <iostream>
#include <cstring>
#include "Data.h"
using namespace std;

namespace sict
{
	int min(const int* data, const int n)
	{
		auto min = LARGEST_NUMBER;
		for (auto i = 0; i < n; ++i)
		{
			if (data[i] < min)
				min = data[i];
		}
		return min;
	}

	void answers(const int* year, const int* population, const int* violentCrime, const double* violentCrimeRate,
	             const int* grandTheftAuto, const int n)
	{
		const auto up_or_down = violentCrime[0] < violentCrime[n - 1] ? "up" : "down";

		cout << "Population change from " << year[0] << " to " << year[n - 1] << " is ";
		cout.precision(2);
		cout.setf(ios::fixed);
		cout << static_cast<double>(population[n - 1] - population[0]) / 1000000 << " million" << endl;
		cout << "Violent Crime trend is " << up_or_down << endl;
		cout << "There are ";
		cout.precision(2);
		cout << fixed << average(grandTheftAuto, n) / 1.0E6 << " million Grand Theft Auto incidents on average a year" <<
			endl;
		cout << "The Minimum Violent Crime rate was " << static_cast<int>(min(violentCrimeRate, n)) << endl;
		cout << "The Maximum Violent Crime rate was " << static_cast<int>(max(violentCrimeRate, n)) << endl;
	}
}
