// Filter.cpp
// Kristin McGee, Tramia McGee, Nicholas Buggs, Jermaine Le Grand
// November 7, 2019
// The purpose of this program is to read in multiple lines from a file, sort the file, and search through the file.


#include "Filter.h"
#include "BaseballStatistic.h"
#include "StringHelper.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

//Swap function
void Filter::swap(vector<BaseballStatistic>& e_Stat, int oIdx, int nIdx)
  {
    BaseballStatistic temp = e_Stat[oIdx]; // //temporary baseball variable to hold the old value during swap
    e_Stat[oIdx] = e_Stat[nIdx]; // assign the min_idx(element to be moved) to it's position
    e_Stat[nIdx] = temp; //assign the element previously at the now sorted postion
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
  { // Start of for loop

        min_idx = i;     

        for (j = i+1; j < e_Stat.size(); j++) 
           if (

              (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) < 0)
             
              || (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) == 0 && e_Stat[j].getFirstName().compare(e_Stat[min_idx].getFirstName() ) < 0)

             || (e_Stat[j].getLastName().compare(e_Stat[min_idx].getLastName()) == 0 && e_Stat[j].getFirstName().compare(e_Stat[min_idx].getFirstName()) == 0 && e_Stat[j].getPosition() < e_Stat[min_idx].getPosition()) 
              )
       

            min_idx = j; 

        swap(e_Stat, min_idx, i);
     
      
} // End of for loop 
}
  //Second sort for option 2(sorting by team name and jersey number)
void Filter::sort2(vector<BaseballStatistic>& e_Stat)
{

	  int i, j, min_idx; 

    for (i = 0; i < e_Stat.size()-1; i++) 
    { // Start of for loop.

        min_idx = i; 

        
        for (j = i+1; j < e_Stat.size(); j++) 

          if (

             (e_Stat[j].getTeamName().compare(e_Stat[min_idx].getTeamName()) < 0)

             || (e_Stat[j].getTeamName().compare(e_Stat[min_idx].getTeamName()) == 0 && e_Stat[j].getJerseyNum() < e_Stat[min_idx].getJerseyNum())

              )

		  min_idx = j; 

      

        swap(e_Stat, min_idx, i);

         } // End of for loop
}
  

// Search/ Filter Function 
std::vector<BaseballStatistic> Filter::search(std::vector<BaseballStatistic>& e_Stat, std::string key , std::string filter){
    
    bool valid;
    vector<BaseballStatistic> result;
    
    for(int i = 0; i < e_Stat.size(); i++)
    { //Start of for loop
        valid = false;
        if(filter == "T"){
            if(e_Stat[i].getTeamName() == key)
                valid = true;
        }
        else if(filter == "P"){
            if(e_Stat[i].getPosition() == key)
                valid = true;
        }
        else if(filter == "B"){
            if(e_Stat[i].getBatting() == key[0])
                valid = true;
        }
        else if(filter == "BA"){
            if(e_Stat[i].getBattingAverage() == atof(key.c_str()))
                valid = true;
        }
        else if(filter == "H"){
            if(e_Stat[i].getHR() == atoi(key.c_str()))
                valid = true;
        }
        else if(filter == "R"){
            if(e_Stat[i].getRBI() == atoi(key.c_str()))
                valid = true;
        }
        else if(filter == "S"){
            if(e_Stat[i].getSB() == atoi(key.c_str()))
                valid = true;
        }
        else if(filter == "O"){
            if(e_Stat[i].getOPS() == atoi(key.c_str()))
                valid = true;
        }
        else if(filter == "E"){
            if(e_Stat[i].getERA() == atoi(key.c_str()))
                valid = true;
        }
        if(valid)
           result.push_back(e_Stat[i]);
    }// End of for loop
    return result;
}


