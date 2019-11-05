#ifndef FILTER
#define FILTER
#include <string>
#include <vector>
#include "BaseballStatistic.h"

class Filter{
  
  public:
          void sort1(std::vector<BaseballStatistic>&);
          void sort2(std::vector<BaseballStatistic>&);
          int search1(std::vector<BaseballStatistic>, std::string, std::string);
          int search2(std::vector<BaseballStatistic>, std::string);
          void swap1(std::vector<BaseballStatistic>&, int, int);
          void swap2(std::vector<BaseballStatistic>&, int, int);
  
};        

#endif


