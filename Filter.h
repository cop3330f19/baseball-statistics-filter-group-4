// Filter.h
// Kristin McGee, Tramia McGee, Nicholas Buggs, Jermaine Le Grand
// November 5, 2019
// The purpose of this program is to read in multiple lines from a file, sort the file, and search through the file.

#ifndef FILTER
#define FILTER
#include <string>
#include <vector>
#include "BaseballStatistic.h"

class Filter{
  
  public:
          void sort1(std::vector<BaseballStatistic>&);
          void sort2(std::vector<BaseballStatistic>&);
          static std::vector<BaseballStatistic> search(std::vector<BaseballStatistic>&, std::string, std::string);
          void swap(std::vector<BaseballStatistic>&, int, int);
  
};        

#endif

