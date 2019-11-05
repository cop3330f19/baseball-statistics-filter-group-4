#include "Filter.h"
#include "BaseballStatistic.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Filter::sort1(vector<BaseballStatistic>& e_Stat)
{
  
  int i, j, min_idx; 
  
  for (i = 0; i < e_Stat.size()-1; i++) 
  { 

        min_idx = i;     

        for (j = i+1; j < e_Stat.size(); j++) 
           if (

              (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) < 0)
             
              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFirstName()const.compare(e_Stat[min_idx].getFirstName()const ) < 0)

              || (e_Stat[j].getLastName()const.compare(e_Stat[min_idx].getLastName()const) == 0 && e_Stat[j].getFirstName()const.compare(e_Stat[min_idx].getFirstName()const) == 0 && e_Stat[j].getPosition()const < e_Stat[min_idx].getPosition()const ) 

              )

            min_idx = j; 

        swap1(e_Stat, min_idx, i);
} 
}
  
void Filter::sort2(vector<BaseballStatistic>& e_Stat)
{

	  int i, j, min_idx; 

    for (i = 0; i < e_Stat.size()-1; i++) 
    { 

        min_idx = i; 

        
        for (j = i+1; j < e_Stat.size(); j++) 

          if (

              (e_Stat[j].getTeamName()const.compare(e_Stat[min_idx].getTeamName()const) < 0)

              

              || (e_Stat[j].getTeamName()const.compare(e_Stat[min_idx].getTeamName()const) == 0 && e_Stat[j].getJerseyNum()const.compare(e_Stat[min_idx].getJerseyNum()const ) < 0)

    )

		  min_idx = j; 

      

        swap2(e_Stat, min_idx, i);

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
