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
    string name;
    
    
    
    cout << "*************************************************************" << endl;
    cout << "* Welcome to the National League Baseball Statistics Search *" << endl;
    cout << "*                                                           *" << endl;
    cout << "* This tool allows you to sort and search National League   *" << endl;
    cout << "* team statstics per player for 2019.                       *" << endl;
    cout << "* Use the menus to select your sort/search options          *" << endl;
    cout << "*************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter your name: ";
    cin >> name;
    cout << "********************************************************************" << endl;
    cout << "Hello " << name << "! Follow the steps below to search for a player." << endl;
    cout << "********************************************************************" << endl;
    cout << endl;
    cout << endl;
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
    cout << endl;
    cout << "Example input:" << endl;
    cout << "Enter all filter key pairs you would like to use (enter 'F F' when finished):" << endl;
    cout << "T Braves" << endl;
    cout << "B R" << endl;
    cout << "H 2" << endl;
    cout << "F F" << endl;
    cout << endl;
    
    bool yesOrNo = true;
    
   //Declaration of new vector 
   vector<BaseballStatistic> result = e_Stat;
    while(yesOrNo){
    do{
      cout << name << " please enter all filter key pairs you would like to use (enter 'F F' when finished):" << endl;
      cin >> filter >> key;
      StringHelper::toUpper(filter);
      if(filter != "F" && filter != "T" && filter != "P" && filter != "B" && filter != "BA" && filter != "H" && filter != "R" && filter != "S" && filter != "O" && filter != "E")
        cout << "Invalid input! Please select from the filter options or F to end filter options." << endl;
      else if (filter != "F")
       result=  Filter::search(result, key, filter);
    }// End of do loop 
       while(filter != "F");
       
    
    
    
    
    
	
    //Switch statement to prompt user to choose between 1 of 2 options.
	cout << "Would you like to sort by:" << endl;
    cout << "A) Player Name & Position" << endl; 
    cout << "B) Team & Jersey Number" << endl; 
    cout << "C) No Sort?" << endl;
    cout << "Enter A, B, or C: ";
	cin >> option;
	
	switch(option)
	{
		case 'A':
            // Case #1: using sorting option 1
			obj.sort1(result);
            
            // Header for output.
            cout << "RESULT" << endl;
            cout << "Player Name||Age||#||Team||P||B/T||AB||AVG||HR||RBI||SB||OPS||ERA" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print();
            
			
            break;
		case 'B':
            // Case #2: using sorting option 1
			obj.sort2(result);
            cout << "RESULT" << endl;
            cout << "Player Name||Age||#||Team||P||B/T||AB||AVG||HR||RBI||SB||OPS||ERA" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print();
            
           break;
        case 'C':
            // Unsorted vector 
            cout << "RESULT" << endl;
            cout << "Player Name||Age||#||Team||P||B/T||AB||AVG||HR||RBI||SB||OPS||ERA" << endl;
            cout << "-----------------------------------------------------------------" << endl;
            for(int i = 0; i < result.size(); i++)
		    result[i].print(); 
			break;
		default:
			cout << "You did not select a correct option." << endl;
            cin >> option;
			break;
	 }
        string choice2;
        bool answer = false;        
        
        while(!answer){
            cout << "Would you like to enter another filter (Y/N)? " << endl; 
            cin >> choice2;
        if(choice2 == "Y" || choice2 == "y"){
            vector<BaseballStatistic> temp = e_Stat;
            result = e_Stat;
            answer = true;
            continue;
        } 
	     else if(choice2 == "N" || choice2 == "n"){
             answer = true;
             yesOrNo = false;
             break;
         }
        else
            cout << "Invalid choice" << endl;
    }
    }    
    return 0;
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
    

