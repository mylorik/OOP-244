/***********************************************************
// Workshop 2: Dynamic Memory
// File w2_in_Home.cpp
// Version 2.0
// Date 24.05.2018
// Author Artem Kulihina
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////
***********************************************************/

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);


int main()
{
	auto count = 0; // the number of kingdoms in the array
	 Kingdom* pKingdom = nullptr;
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of Kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;

	// TODO: allocate dynamic memory here for the pKingdom pointer
	 pKingdom  = new Kingdom[count];

	for (auto i = 0; i < count; ++i)
	{
		cout << "Kingdom #" << i + 1 << ": " << endl;

		// TODO: add code to accept user input for Kingdom i
		read(pKingdom [i]);
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The 1st Kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom [0]);
	cout << "------------------------------" << endl << endl;

	
	auto pKingdoms = new Kingdom[count+1];
	// TODO: copy elements from original array into this newly allocated array
	for (auto i = 0; i < count; i++)
	{
		pKingdoms[i] = pKingdom [i];
	}
	// TODO: deallocate the dynamic memory for the original array
	delete[] pKingdom;

	// TODO: copy the address of the newly allocated array into pKingdom pointer
	pKingdom = pKingdoms;

	count++;
	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count << ": " << endl;
	// TODO: accept input for the new element in the array

	read(pKingdom [count]);
	cout << "==========\n" << endl;
	// testing that the overload of "display(...)" works
	display(pKingdom , count);
	cout << endl;

	/*
	// TODO: deallocate the dynamic memory here
	delete[] pKingdoms ;
	delete[] pKingdom ;
	*/
	return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
	cout << "Enter the name of the Kingdom: ";
	cin.get(kingdom.m_name, 32, '\n');
	cin.ignore(2000, '\n');
	cout << "Enter the number of people living in " << kingdom.m_name << ": ";
	cin >> kingdom.m_population;
	cin.ignore(2000, '\n');
	
}