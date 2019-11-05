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
void swap1(vector<BaseballStatistic>&, int, int);
void swap2(vector<BaseballStatistic>&, int, int);
void sort1(vector<BaseballStatistic>& e_Stat);
void sort2(vector<BaseballStatistic>& e_Stat);
int search1(vector<BaseballStatistic> e_Stat, string, string);
int search2(vector<BaseballStatistic> e_Stat, string);


int main(){ 
 // Use cases to prompt user to choose from sorting options. 
       vector<BaseballStatistic> e_Stat;
       loadFile(e_Stat);
	char option;
	
	cout << "Would you like to search by A) Player Name & Position, or B) Team & Jersey Number? Enter A or B: ";
	cin >> option;
	
	switch(toupper(option))
	{
		case 'a':
			sort1(vector<BaseballStatistic>& e_Stat);
			search1(vector<BaseballStatistic>& e_Stat, string firstName, string lastName);
		case 'b':
			sort2(vector<BaseballStatistic>& e_Stat);
			search2(vector<BaseballStatistic>& e_Stat, string teamName);
		default:
			cout << "You did not select a correct option." << endl;
			break;
	}
	
	
			

}




void loadFile(vector<BaseballStatistic>& e_Stat){
	ifstream in;
	in.open("BStats.csv");
	
	while(in){
	string str;
	parse(str, ',');
		
	std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
        int birthDay, birthMonth, birthYear;
	
	in >> teamName >> jerseyNum >> firstName >> lastName >> birthYear >> birthMonth >> birthDay >> batting >> throwing >> atBats >> battingAverage >> hr >> rbi >> sb >> ops >> era >> position;
	
		
	BaseballStatistic temp(teamName, jerseyNum, firstName, lastName, birthYear, birthMonth, birthDay, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era, position);
	e_Stat.push_back(temp);
	}
}

void swap1(vector<BaseballStatistic>& e_Stat, int a, int b);
  {
    BaseballStatistic temp = *a;
    *a=*b;
    *b =temp;
  }

void swap2(vector<BaseballStatistic>& e_Stat, int a, int b);
  {
    BaseballStatistic temp = *a;
    *a=*b;
    *b =temp;
  }
