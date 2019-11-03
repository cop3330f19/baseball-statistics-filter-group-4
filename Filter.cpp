#include "Filter.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void sort1(vector<BaseballStatistic>&)
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

void search(vector<BaseballStatistic>, string, string)
{
  
}
