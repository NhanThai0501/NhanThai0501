#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <ctime>
#include <cmath>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include <numeric>

#include "DynamicStackTemplate.h"
#include "input.h"

using namespace std;

class Inventory 
{
private:
	int serialNum;
	string manufactDate;
	int lotNum;
public:
	Inventory()
	{
		serialNum = 0;
		manufactDate = "";
		lotNum = 0;
	}

	// PreCondition: valid integer 's'
	// PostCondition: assigned 'serialNum' as 's'
	void setSerialNum(int s)
	{
		serialNum = s;
	}

	// PreCondition: valid string 'd'
	// PostCondition: assigned 'manufactDate' as 'd'
	void setManufactDate(string d)
	{
		manufactDate = d;		
	}

	// PreCondition: valid integer 'l'
	// PostCondition: assigned 'lotNum' as 'l'
	void setLotNum(int l)
	{
		lotNum = l;
	}

	// PreCondition: NA 
	// PostCondition: return 'serialNum'
	int getSerialNum() const
	{
		return serialNum;
	}

	// PreCondition: NA
	// PostCondition: return 'manufactDate'
	string getManufactDate() const
	{
		return manufactDate;
	}

	// PreCondition: NA
	// PostCondition: return 'lotNum'
	int getLotNum() const
	{
		return lotNum;
	}

	// PreCondition: valid string 'date'
	// PostCondition: return true if date is validated, and false if it's not
	bool dateValidation(string date)
	{
		// Check the string length of date format: MM/DD/YYYY
		if (date.length() != 10)
			return false;

		// Check the symbol in the date format
		if (date[2] != '/' || date[5] != '/')
			return false;

		// Check if date is digit number except the symbol
		for (int i = 0; i < date.length(); i++)
		{
			if (i == 2 || i == 5)
				continue;
			if (!isdigit(date[i]))
				return false;
		}
		
		// Check month, date, year relatively of date
		if ((stoi(date.substr(0, 2))) <= 0 || (stoi(date.substr(0, 2)) > 12))
			return false;
		if ((stoi(date.substr(3, 2))) <= 0 || (stoi(date.substr(3, 2)) > 31))
			return false;
		if ((stoi(date.substr(6, 4))) < 1000)
			return false;

		// If date is in correct format, return true
		else	
			return true;
	}

};

