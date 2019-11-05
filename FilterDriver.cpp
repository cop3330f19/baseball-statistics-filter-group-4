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



int main(){ 
  
  Filter obj;
    
 
    
    
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
            cout << "Pre Sorted List" << endl;
	        for(int i = 0; i < e_Stat.size(); i++)
		    e_Stat[i].print();
            //loadFile(e_Stat);
			obj.sort1(e_Stat);
			obj.search1(e_Stat, firstName, lastName);
            break;
		case 'B':
			obj.sort2(e_Stat);
			obj.search2(e_Stat, teamName);
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
    
    
    
    while(in.good())
    {
       // deccaring temp variable as a string
        string temp;
        //read in line then slit by delimiter
        getline(in, temp, ',');
       teamName = temp;
        getline(in, temp,',');
       //convert the string to an int
       stringstream loading(temp);
       //set converted variable to corresponding variable 
       loading >> jerseyNum;
        getline(in, temp, ',');
       firstName = temp;
        getline(in, temp, ',');
       lastName = temp;
        getline(in, temp, ',');
       stringstream loading2(temp);
       loading2 >> year;
        getline(in, temp, ',');
       stringstream loading3(temp);
       loading3 >> month;
        getline(in, temp, ',');
       stringstream loading4(temp);
       loading4 >> day;
        getline(in, temp, ',');
       //create a char variable of the same length of the read in variable
       char p[temp.length()];
       //set the temp char variable to the read in variable
       p[0] = temp[0];
       //set the temp char variable to the corresponding variable
       batting = p[0];
        getline(in, temp, ',');
       p[0] = temp[0];
       throwing = p[0];
        getline(in, temp, ',');
       stringstream loading5(temp);
       loading5 >> atBats;
        getline(in, temp, ',');
       stringstream loading6(temp);
       loading6 >> battingAverage;
        getline(in, temp, ',');
       stringstream loading7(temp);
       loading7 >> hr;
        getline(in, temp, ',');
       stringstream loading8(temp);
       loading8 >> rbi;
        getline(in, temp, ',');
       stringstream loading9(temp);
       loading9 >> sb;
        getline(in, temp, ',');
       stringstream loading10(temp);
       loading10 >> ops;
        getline(in, temp, ',');
       stringstream loading11(temp);
       loading11 >> era;
        getline(in, temp);
       position = temp;
        
        
       // cout << teamName << " " << jerseyNum << " " << firstName << " " << lastName << " " << year << " " << month << " " << day << " " << batting << " " << throwing << " " << atBats << " " << battingAverage << " " << hr << " " << rbi << " " << sb << " " << ops << " " << era << " " << position << endl;
       BaseballStatistic temp1(firstName, lastName, teamName, jerseyNum, position, year, month, day, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era);
	e_Stat.push_back(temp1);
	}
     in.close();
    }
