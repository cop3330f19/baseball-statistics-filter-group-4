#include "BaseballStatistic.h"
#include "Data.h"
#include "StringHelper.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void swap1(vector<BaseballStatistic>&, int, int);
void swap2(vector<BaseballStatistic>&, int, int);
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

void swap(vector<BaseballStatistic>& e_Stat, int a, int b);
  {
    
    int temp = *a;
    *a=*b;
    *b =temp;
  }


