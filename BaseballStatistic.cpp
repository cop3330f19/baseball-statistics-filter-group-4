#include <iostream>
#include <string>
#include "BaseballStatistic.h"
#include "Date.h"

BaseballStatistic::BaseballStatistic(std::string fname, std::string lname, std::string tname, int j_num, std::string p_postion, char num_bat, char num_throw, int at_bat, double bat_avg, int hour, int num_rbi, int stolen_base, double num_ops, double num_ers){
   	        setFirstName(fname);
		setLastName(lname);
		setTeamName(tname);
		setJerseyNum(j_num);
		setPosition(p_position);
		setBatting(num_bat);
		setThrowing(num_throw);
		setAtBats(at_bats);
		setBattingAverage(bat_avg);
		setHR(hour);
		setRBI(num_rbi);
		setSB(stolen_base);
		setOPS(num_ops);
		setERA(num_ers);
}
Date::Date(int y, int m, int d):year(y), month(m), day(d){
				}
void Date::setYear(int y){year = y;}
void Date::setMonth(int m){month = m; }
void Date::setDay(int d){day = d; }

void BaseballStatistic::setFirstName(std::string fname){
  firstName = fname;
}
void BaseballStatistic::setLastName(std::string lname){
  lastName = lname;
}
void BaseballStatistic::setTeamName(std::string tname){
 teamName = tname;
}
void BaseballStatistic::setJerseyNum(int j_num){
 jerseyNum = j_num;
}
void BaseballStatistic::setPosition(std::string p_postion){
  position = p_position;
}
void BaseballStatistic::setBatting(char num_bat){
  batting = num_bat;
}
void BaseballStatistic::setThrowing(char num_throw){
  throwing = num_throw;
}
void BaseballStatistic::setAtBats(int at_bat){
  atBats = at_bat;
}
void BaseballStatistic::setBattingAverage(double bat_avg){
  battingAverage = bat_avg;
}
void BaseballStatistic::setHR(int hour){
  hr = hour;
}
void BaseballStatistic::setRBI(int num_rbi){
  rbi = num_rbi;
}
void BaseballStatistic::setSB(int stolen_base){
  sb = stolen_base;
}
void BaseballStatistic::setOPS(double num_ops){
  ops = num_ops;
}
void BaseballStatistic::setERA(double num_era){
  era = num_era;
}
std::string BaseballStatistic::getFirstName()const{
  return firstName;
}
std::string BaseballStatistic::getLastName()const{
  return lastName;
}
std::string BaseballStatistic::getTeamName()const{
  return teamName;
}
int BaseballStatistic::getJerseyNum()const{
  return jerseyNum;
}
std::string BaseballStatistic::getPosition()const{
  return position;
}
//Check function below
std::string getDate(int c_month, int c_day, int c_year;)const {
  int c_month, c_day, c_year;	
  cout << "Enter current date(MM DD YYYY): ";
  cin >> c_month >> c_day >> c_year;
	return (c_month, c_day, c_year); 
}
int BaseballStatistic::getAge()const{
  int delta = 0;
  //int c_month, c_day, c_year;
  //cout << "Enter current date(month, day, year): ";
  // cin >> c_month >> c_day >> c_year;
  if (getMonth()const > c_month) delta = -1;
  if ((getMonth()const == c_month) && (getDay()const > c_day)) delta = -1;
  return(c_year - getYear()const + delta);
}
char BaseballStatistic::getBatting()const{
  return batting;
}
char BaseballStatistic::getThrowing()const{
  return throwing;
}
int BaseballStatistic::getAtBats()const{
  return atBats;
}
double BaseballStatistic::getBattingAverage()const{
  return battingAverage;
}
int BaseballStatistic::getHR()const{
  return hr;
}
int BaseballStatistic::getRBI()const{
  return rbi;
}
int BaseballStatistic::getSB()const{
  return sb;
}
double BaseballStatistic::getOPS()const{
  return ops;
}
double BaseballStatistic::getERA()const{
  return era;
}
int getDay()const{
  return day;
}
int getMonth()const{
    return month;
}
int getYear()const{
    return year;
}
