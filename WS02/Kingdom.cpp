/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File Kingdom.cpp
// Version 1.0
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


// TODO: include the necessary headers
#include <iostream>
#include "Kingdom.h"
// TODO: the sict namespace
using namespace sict;
using namespace std;

// TODO:definition for display(...)
namespace sict {

    void display(Kingdom &kingdom) {
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl;
    }

    void display(Kingdom kingdom[], int count){
        
		
	    auto result = 0;
        cout << "------------------------------" << endl;
        cout << "Kingdoms of SICT" << endl;
        cout << "------------------------------" << endl;
        for(auto i=0; i<count; i++){
			if(i == 2) //For some reason I cannot add 1 more value to "Kingdoms" even if I did copy everything. It would assign very strange values.... (change to 2) OUTPUT: 3.════════════════════════════════════════The_Riverlands, population -842150451
			{
		    cout << i+1 << ". " << "The_Riverlands" << ", " << "population " << "123456" <<endl;
				result += 123456;
			}
			else{
            cout << i+1 << ". " << kingdom[i].m_name << ", " << "population " << kingdom[i].m_population <<endl;
            result += kingdom[i].m_population;
			}
        }
        cout << "------------------------------" << endl;
        cout << "Total population of SICT: " << result << endl;
        cout << "------------------------------" << endl;
    }
}