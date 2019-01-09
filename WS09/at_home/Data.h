///////////////////////////////////////////////////////////
// Name			Date		              
// Artem       2018/07/28      
///////////////////////////////////////////////////////////
#ifndef SICT_DATA_H__
#define SICT_DATA_H__

#include <iostream>
#include <cstring>

namespace sict
{
	const int LARGEST_NUMBER = 1000000000;
	const int SMALLEST_NUMBER = 0;
	const int COLUMN_WIDTH = 15;

	int min(const int* data, int n);
	void answers(const int*, const int*, const int*, const double*, const int*, int n);

	template <typename T>
	T max(const T* data, const int n)
	{
		T max = data[0];

		for (auto i = 1; i < n; ++i)
		{
			if (max < data[i])
				max = data[i];
		}
		return max;
	}

	template <typename T>
	T min(const T* data, const int n)
	{
		T min = data[0];

		for (auto i = 1; i < n; ++i)
		{
			if (min > data[i])
				min = data[i];
		}
		return min;
	}

	template <typename T>
	T sum(const T* data, const int n)
	{
		T sum = 0;

		for (auto i = 0; i < n; ++i)
		{
			sum += data[i];
		}
		return sum;
	}

	template <typename T>
	double average(const T* data, int n)
	{
		return sum(data, n) / n;
	}

	template <typename T>
	bool read(std::istream& input, T* data, int n)
	{
		for (auto i = 0; i < n; ++i)
		{
			input.ignore();
			input >> data[i];

			if (input.fail())
			{
				return false;
			}
		}
		return true;
	}

	template <typename T>
	void display(const char* name, const T* data, int n)
	{
		std::cout.width(20);
		std::cout << std::right << name;

		for (auto i = 0; i < n; ++i)
		{
			std::cout.width(15);
			std::cout << data[i];
		}
		std::cout << "\n";
	}

	template <typename T>
	T readRow(std::istream& fileInput, const char* name, T* data, int n)
	{
		char rowname[2000];
		auto check = !fileInput.bad();

		if (check)
		{
			fileInput.get(rowname, 2000, ',');

			if (std::strcmp(rowname, name) != 0)
			{
				std::cout << "Cannot parse row for " << name << std::endl;
				fileInput.ignore(2000, '\n');
				check = false;
			}
		}
		if (check)
			check = read(fileInput, data, n);
		fileInput.ignore(2000, '\n');
		return check;
	}
}
#endif
