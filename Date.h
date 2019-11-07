// Date.h
// Kristin McGee, Tramia McGee, Nicholas Buggs, Jermaine Le Grand
// November 7, 2019
// The purpose of this program is to read in multiple lines from a file, sort the file, and search through the file.

#ifndef DATE_H
#define DATE_H
#include "BaseballStatistic.h"
#include <string>

class Date
{
	
	private:
		const int day;
        const int month;
        const int year;
	
    public:
		//Constructor accepts the date in the format YYYY, MM, DD
		//eg Date date(2019, 9, 27);
		explicit Date(int y, int m, int d):
			year(y), month(m), day(d){
				
			}
		
		int getDay()const; //Returns the day
		int getMonth()const; //Returns the month
		int getYear()const; //Returns the year
		std::string getDate()const; //Returns the date string (YYYY-MM-DD)
		int getAge()const; //Calculates age in years
};

#endif
