#include <stdio.h>
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define SECONDS_IN_AN_HOUR 3600
#define TRACE printf("Current line is: %d\n",__LINE__)

//initialization of time struct
struct time {
  int hours;
  int minutes;
  int seconds;
};
//definition of enum for months
enum months {January, February, March, April, May, June, July, August, September, October, November, December};
//initialization of date and time struct
struct DateTime {
  enum months m;
  int day;
  int year;
  struct time t;
};
  
//function signatures
int numSeconds (int hours, int minutes, int seconds);
struct time timeStructCalc(struct time time1, struct time time2);
char* returnMonth(enum months m);

int main() {
 printf("\n-------------- Part A --------------\n\n");
 //Test values for part A
 struct time time1 = {3,45,15};
 struct time time2 = {9,44,3};
 timeStructCalc(time1, time2);
 
 time1.hours = 1; time1.minutes = 30; time1.seconds = 45;
 time2.hours = 16; time2.minutes = 30; time2.seconds = 45;
 timeStructCalc(time1, time2);
  
 time1.hours = 12; time1.minutes = 0; time1.seconds = 0;
 time2.hours = 12; time2.minutes = 0; time2.seconds = 0;
 timeStructCalc(time1, time2);
  
 printf("-------------- Part B --------------\n\n");
 //Test values for part B
 //january 19 1809 12:01
 enum months m = January;
 struct DateTime DateTime1 = {January,19,1809,12,1,0};
 printf("Date: \t\t%s %d, %d\nTime: \t\t%d:%d:%d\n", returnMonth(DateTime1.m), DateTime1.day, DateTime1.year, DateTime1.t.hours, DateTime1.t.minutes, DateTime1.t.seconds);
 /*
 //Nov 11 1922 6:00
 enum months m = November;
 struct DateTime DateTime2 = {m,11,1922,6,0,0};
 printf("Date: %s %d, %d\nTime: %d:%d:%d\n", returnMonth(DateTime2.m), DateTime2.day, DateTime2.year, DateTime1.2.hours, DateTime1.2.minutes, DateTime1.2.seconds);
 */
 return 0;
}

//function that takes two time structs and returns their difference
struct time timeStructCalc(struct time time1, struct time time2) {
 printf("Time 1: \t\t%d:%d:%d\nTime 2: \t\t%d:%d:%d\n", time1.hours, time1.minutes, time1.seconds, time2.hours, time2.minutes, time2.seconds); 
 //converting the two given times to seconds
 int time1_sec = numSeconds(time1.hours,time1.minutes,time1.seconds);
 int time2_sec = numSeconds(time2.hours,time2.minutes,time2.seconds);
 int time_difference_sec;
 //calculating difference of two times
 if (time1_sec <= time2_sec) {
   time_difference_sec = time2_sec -  time1_sec;
 }
 else {
   time_difference_sec = time1_sec -  time2_sec;
 } 
 //converting seconds back to hours, minutes and seconds and storing in new struct
 struct time time_difference = {
   .hours = time_difference_sec/SECONDS_IN_AN_HOUR,
   .minutes = (time_difference_sec - (SECONDS_IN_AN_HOUR * time_difference.hours)) / SECONDS_IN_A_MINUTE,
   .seconds = (time_difference_sec - (SECONDS_IN_AN_HOUR * time_difference.hours)) - (SECONDS_IN_A_MINUTE * time_difference.minutes)
 };
 printf("Time difference: \t%d:%d:%d\n\n", time_difference.hours, time_difference.minutes, time_difference.seconds);
 return time_difference;
}  

//function that takes a number of hours, minutes and seconds and returns total number of seconds
int numSeconds (int hours, int minutes, int seconds) {
 TRACE;
 int total = (hours * MINUTES_IN_AN_HOUR * SECONDS_IN_A_MINUTE) + (minutes * SECONDS_IN_A_MINUTE) + seconds; 
 return total;
}

char* returnMonth (enum months m) {
 switch (m) {
  case January: return "January";
  case February: return "Februray";
  case March: return "March";
  case April: return "April";
  case May: return "May";
  case June: return "June";
  case July: return "July";
  case August: return "August";
  case September: return "September";
  case October: return "October";
  case November: return "November";
  case December: return "December";
 }
}
