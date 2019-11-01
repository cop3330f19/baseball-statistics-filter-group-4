#include "BaseballStatistic.h"
#include "Data.h"
#include "StringHelper.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void swap1(vector<BaseballStatistic>&, string, char);
void swap2(vector<BaseballStatistic>&, string, int);
void sort1(vector<BaseballStatistic>&);
void sort2(vector<BaseballStatistic>&);
int search(vector<BaseballStatistic>, string, string);
void loadFile(vector<BaseballStatistic>&);

int main(){
  
  
}




void loadFile(vector<BaseballStatistic>& e_Stat){
	ifstream in;
	in.open("BStats.csv");
	
	std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
  int birthDay, birthMonth, birthYear; 
	
	while(teamName >> jerseyNum >> firstNmae >> lastName >> birthYear >> birthMonth >> birthDay >> batting >> throwing >> atBats >> battingAverage >> hr >> rbi >> sb >> ops >> era >> position){
		
		BaseballStatistic temp(teamName, jerseyNum, firstNmae, lastName, birthYear, birthMonth, birthDay, batting, throwing, atBats, battingAverage, hr, rbi, sb, ops, era, position);
		e_Stat.push_back(temp);
	}
}

void swap1(vector<BaseballStatistic>& e_Stat, string a, char b);
  {
    string temp = *a;
    *a=*b;
    *b =temp;
  }
void sort1(vector<BaseballStatistic>& e_Stat){
    
     int i, j, min_idx; 
   
    for (i = 0; i < e_Stat.size()-1; i++) 
    { 
        min_idx = i; 
        
        for (j = i+1; j < e_Stat.size(); j++) 
          if (
              (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) < 0)
              
              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFisrtName()const.compare(e_Stat[min_idx].getFirstName()const ) < 0)
              
              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFirstName()const.compare(e_Stat[min_idx].getFirstName()const) == 0 && e_Stat[j].getPostion()const < e_Stat[min_idx].getPosition()const ) 
              )
            min_idx = j; 
      
        swap1(e_Stat, min_idx, i);
         } 
}

