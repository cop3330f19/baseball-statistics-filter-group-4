#include "BaseballStatistic.h"
#include "Date.h"
#include "StringHelper.h"
#include "Filter.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void loadFile(vector<BaseballStatistic>&);
/*void swap1(vector<BaseballStatistic>&, int, int);
void swap2(vector<BaseballStatistic>&, int, int);
void sort1(vector<BaseballStatistic>& e_Stat);
void sort2(vector<BaseballStatistic>& e_Stat);
int search1(vector<BaseballStatistic> e_Stat, std::string, std::string);
int search2(vector<BaseballStatistic> e_Stat, std::string);
*/

int main(){ 
    
    
 // Use cases to prompt user to choose from sorting options. 
       vector<BaseballStatistic> e_Stat;
       loadFile(e_Stat);
	char option;
    string firstName, lastName, teamName;
    
    loadFile(e_Stat);
	
	cout << "Would you like to search by A) Player Name & Position, or B) Team & Jersey Number? Enter A or B: ";
	cin >> option;
	
	switch(option)
	{
		case 'A':
            cout << teamName;
			//sort1(e_Stat);
			//search1(e_Stat, firstName, lastName);
			break;
		case 'B':
			//sort2(e_Stat);
			//search2(e_Stat, teamName);
			break;
		default:
			cout << "You did not select a correct option." << endl;
			break;
	}
	
	
			

}




void loadFile(vector<BaseballStatistic>& e_Stat)
{
	ifstream in;
	in.open("BStats.csv");
	
	std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
    int day, month, year;
    while(in){
	//string str;
    
	//parse(str, ',');
	
	in >> teamName >> jerseyNum >> firstName >> lastName >> year >> month >> day >> batting >> throwing >> atBats >> battingAverage >> hr >> rbi >> sb >> ops >> era >> position;
	
	BaseballStatistic temp(firstName, lastName, teamName, jerseyNum, position, year, month, day, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era);
	e_Stat.push_back(temp);
	}
}


