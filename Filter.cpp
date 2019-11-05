// Filter.cpp
// Kristin McGee, Tramia McGee, Nicholas Buggs, Jermaine Le Grand
// November 5, 2019
// The purpose of this program is to read in multiple lines from a file, sort the file, and search through the file.


#include "Filter.h"
#include "BaseballStatistic.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void Filter::swap(vector<BaseballStatistic>& e_Stat, int oIdx, int nIdx)
  {
    BaseballStatistic temp = e_Stat[oIdx]; 
    e_Stat[oIdx] = e_Stat[nIdx]; 
    e_Stat[nIdx] = temp;
  }

//First sort for option 1(Sort by name and position)
void Filter::sort1(vector<BaseballStatistic>& e_Stat)
{
  
  std::string firstName, lastName, teamName, position;
	int jerseyNum, atBats, hr, rbi, sb;
	char batting, throwing;
	double battingAverage, ops,era;
    int day, month, year;
    
    int i, j, min_idx; 
    
  
  for (i = 0; i < e_Stat.size()-1; i++) 
  { 

        min_idx = i;     
       //Compare last name to first name
        for (j = i+1; j < e_Stat.size(); j++) 
           if (

              (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) < 0)
             
              || (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) == 0 && e_Stat[j].getFirstName().compare(e_Stat[min_idx].getFirstName() ) < 0)

             // || (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) == 0 && e_Stat[j].getFirstName().compare(e_Stat[min_idx].getFirstName()) == 0 && e_Stat[j].getPosition() < e_Stat[min_idx].getPosition()) 
              )
       

            min_idx = j; 

        swap(e_Stat, min_idx, i);
     
          cout << teamName << " " << jerseyNum << " " << firstName << " " << lastName << " " << year << " " << month << " " << day << " " << batting << " " << throwing << " " << atBats << " " << battingAverage << " " << hr << " " << rbi << " " << sb << " " << ops << " " << era << " " << position << endl;
      
} 
}
  //Second sort for option 2(sorting by team name and jersey number)
void Filter::sort2(vector<BaseballStatistic>& e_Stat)
{

	  int i, j, min_idx; 
    // Compare the team names 
    for (i = 0; i < e_Stat.size()-1; i++) 
    { 

        min_idx = i; 

        
        for (j = i+1; j < e_Stat.size(); j++) 

          if (

             (e_Stat[j].getTeamName().compare(e_Stat[min_idx].getTeamName()) < 0)

             // || (e_Stat[j].getTeamName().compare(e_Stat[min_idx].getTeamName()) == 0 && e_Stat[j].getJerseyNum().compare(e_Stat[min_idx].getJerseyNum()) < 0)

              )

		  min_idx = j; 

      

        swap(e_Stat, min_idx, i);

         } 
}
  
int Filter::search1(vector<BaseballStatistic> e_Stat, string firstName, string lastName)
{

  int lo = 0;

  int hi = e_Stat.size();
    while (lo <= hi) 

    { 

        int location = lo + (hi-lo)/2; 

        if (e_Stat[location].getLastName() == lastName && e_Stat[location].getFirstName() == firstName) 

            return location;
    
        if (e_Stat[location].getLastName() < lastName 	|| (e_Stat[location].getLastName() == lastName && e_Stat[location].getFirstName() < firstName)) 

            lo = location + 1;
      
        else
            hi = location - 1; 
    } 

    return -1; 
}
  
int Filter::search2(vector<BaseballStatistic> e_Stat, string teamName)
{
  
  int lo = 0;

  int hi = e_Stat.size();
    while (lo <= hi) 

    { 

        int location = lo + (hi-lo)/2; 

        if (e_Stat[location].getTeamName() == teamName ) 

            return location; 

        if (e_Stat[location].getTeamName() < teamName || (e_Stat[location].getTeamName() == teamName))

            lo = location + 1; 
      
        else
            hi = location - 1; 

    } 

    return -1;
}
