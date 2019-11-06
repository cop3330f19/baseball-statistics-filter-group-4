// FilterDriver.cpp
// Kristin McGee, Tramia McGee, Nicholas Buggs, Jermaine Le Grand
// November 5, 2019
// The purpose of this program is to read in multiple lines from a file, sort the file, and search through the file.


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
  
  
    //Create object
    Filter obj;
 
    // Use cases to prompt user to choose from sorting options. 
    vector<BaseballStatistic> e_Stat;
    loadFile(e_Stat);
	char option;
    string firstName, lastName, teamName;
    string key, filter;
    
    cout << "******FILTER OPTIONS******" << endl;
    cout << "* T   - Team             *" << endl;
    cout << "* P   - Position         *" << endl;
    cout << "* B   - Batting          *" << endl;
    cout << "* BA  - Batting Average  *" << endl;
    cout << "* H   - Home Runs        *" << endl;
    cout << "* R   - Runs Batted In   *" << endl;
    cout << "* S   - Stolen Bases     *" << endl;
    cout << "* O   - OPS              *" << endl;
    cout << "* E   - ERA              *" << endl;
    cout << "**************************" << endl;
    
   //Declaration of new vector 
   vector<BaseballStatistic> result = e_Stat;
    
    do{
      cout << "Enter all filter key pairs you would like to use (enter F when finished):" << endl;
      cin >> filter >> key;
      StringHelper::toUpper(filter);
      if(filter != "F" && filter != "T" && filter != "P" && filter != "B" && filter != "BA" && filter != "H" && filter != "R" && filter != "S" && filter != "O" && filter != "E")
        cout << "Invalid input! Please select from the filter options or F to end filter options." << endl;
      else if (filter != "F")
       result=  Filter::search(result, key, filter);
    }// End of do loop 
       while(filter != "F");
       
    
    
    
    
    
	
    //Switch statement to prompt user to choose between 1 of 2 options.
	cout << "Would you like to search by A) Player Name & Position, B) Team & Jersey Number, C) No Sort? Enter A, B, or C: ";
	cin >> option;
	
	switch(option)
	{
		case 'A':
            // Case #1: using sorting option 1
			obj.sort1(result);
            
            cout << "Sorted List #1" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print();
            
			
            break;
		case 'B':
            // Case #2: using sorting option 1
			obj.sort2(result);
            cout << "Sorted List #2" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print();
            
           break;
        case 'C':
            // Unsorted vector 
            cout << "Unsorted List" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print(); 
			break;
		default:
			cout << "You did not select a correct option." << endl;
            cin >> option;
			break;
	 }
    
	
			
}



// Loading file into the vector
void loadFile(vector<BaseballStatistic>& e_Stat)
{
	ifstream in;
	in.open("BStats.csv");
	
	std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
    int day, month, year;
    
    
    // Reading in file and splitting at comma. 
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
        
        
       
       BaseballStatistic temp1(firstName, lastName, teamName, jerseyNum, position, year, month, day, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era);
	e_Stat.push_back(temp1);
	}
     in.close();
    }
    
