#include <stdio.h>
/* PA1.c -- Hunter Trautz, hctrautz */

/**
* Calculates the day of the week on which the year starts
* @param  year  a year that we need to know the day of the week of Jan 1st
* @return       an integer which represents the day of the week, where 0 == Sunday and 6 == Saturday.
*/
int findStartingDay (int year){
  return ((year-1) + (year-1)/4 - (year-1)/100 + (year-1)/400 + 1)%7; //Tomohiko Sakamoto's algorithm for calculating the day of the week for
                                                                      //any day of any year on the Greogrian Calendar adjusted to calculate the
}                                                                     //first day of the dayOfWeek for the first of the yaer
                                                                      //Source: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods

/**
* Determines if the entered year is a leap year.
* @param  year  a year we need to know is a leap year or not
* @return       an integer (either 1 or 0) representing a boolean
*/
int isLeap(int year){
  if(year%4==0 && (year%400==0 || year%100 != 0)){
    return 1; //true
  } else {
    return 0; //false
  }
}

/**
* Prints the name of the month followed by the year, and returns the total number of days in that month
* @param  year  the year of the calender being printed out
* @param  month the month needed to be printed out
* @return       an integer representing the total number of days in that month
*/
int printMonthName(int year, int month){
  int totalDays;
  switch (month) {
    case 0:
    printf("January %d", year);
    totalDays = 31;
    break;

    case 1:
    printf("February %d", year);
    if(isLeap(year)){
      totalDays = 29;
    } else {
      totalDays = 28;
    }
    break;

    case 2:
    printf("March %d", year);
    totalDays = 31;
    break;

    case 3:
    printf("April %d", year);
    totalDays = 30;
    break;

    case 4:
    printf("May %d", year);
    totalDays = 31;
    break;

    case 5:
    printf("June %d", year);
    totalDays = 30;
    break;

    case 6:
    printf("July %d", year);
    totalDays = 31;
    break;

    case 7:
    printf("August %d", year);
    totalDays = 31;
    break;

    case 8:
    printf("September %d", year);
    totalDays = 30;
    break;

    case 9:
    printf("October %d", year);
    totalDays = 31;
    break;

    case 10:
    printf("November %d", year);
    totalDays = 30;
    break;

    case 11:
    printf("December %d", year);
    totalDays = 31;
    break;
  }

  printf("\n\n");

  return totalDays;
}

/**
* Prints the calender for the month of a specific year
* @param  year  the year of the calender being printed out
* @param  month the month needed to be printed
* @param  startingDay the day of the week on which the month starts
* @return       an integer representing the day of the week that the next month in the loop starts on
*/
int printMonth(int year, int month, int startingDay){
  int totalDays = printMonthName(year, month);

//INVARIANT: Day variable will always be less than 7 and greater than or equal to 0, will run when 0<=day<=6
  for(int day = 0; day < 7; day++){ // loops through and prints the days of the week
    switch(day){                    // for the top of the calendar
      case 0:
      printf("Sun  ");
      break;
      case 1:
      printf("Mon  ");
      break;
      case 2:
      printf("Tue  ");
      break;
      case 3:
      printf("Wed  ");
      break;
      case 4:
      printf("Thu  ");
      break;
      case 5:
      printf("Fri  ");
      break;
      case 6:
      printf("Sat");
      break;
    }
  }
  printf("\n");

  int dayOfWeek = 0; //0 == Sunday, 6 == Saturday
  int dayOfMonth = 1; //saves the day of the month to be printed

  //INVARIANT: The day variable will always be less than the totalDays in a month + the day of the dayOfWeek (0-6)
  //that the month starts on. Day will always be greater than 0 and run untl it equals totalDays+startingDay
  for(int day = 0; day < totalDays+startingDay; day++){

    if(day < startingDay){
      printf("     "); //put a blank space until the starting day of the month is reached
    } else{
      if(dayOfMonth < 10){
        printf("  %d  ", dayOfMonth); //two spaces for a single digit number
      } else {
        printf(" %d  ", dayOfMonth); //one space to account for 2 digit number
      }

      dayOfMonth++;
    }
    dayOfWeek++;

    //moves to next line of the calender once Saturday is reached
    if(dayOfWeek%7 == 0){
      dayOfWeek = 0;
      if(day != totalDays+startingDay-1){
        printf("\n");
      }
    }
  }

  return dayOfWeek;
}

/**
* Prints the calender for an entire year by looping through the printMonth
* fcn 12 times, saving the last day of the week through each iteration of the loop
* @param  year  the year of the calender being printed out
* @param  startingDay the day of the week on which the year starts (calculated by findStartingDay)
*/
void printCalendar(int year, int startingDay){

  printf("\n\n  ***    CALENDAR for %d   ***\n\n", year);

//INVARIANT: Month variable will always be less than 12 and greater than or equal to 0 , will run when 0<=day<=11
  for(int month = 0; month<12; month++){ //loops through every single month printing them all
    startingDay = printMonth(year, month, startingDay); //stores the day of the week on which the next month will start
    printf("\n\n");
  }
}

/**
* Runs the program - which promts for a year, and will print
* a calendar for that year as long as the year is greater than 0
* @return 0 if the program ran sucessfully
*/
int main(void) {
  int year = 1; //stores the user's input for year, initalized here
  printf("Please enter year for this calendar:-");
  scanf("%d", &year); //sets year to the user's input
  if(year < 0){
    printf("Error: Please Enter A Valid Year\n");
    main(); //restart the program if year is < 0
  } else {
    printCalendar(year, findStartingDay(year));
    return 0;
  }
}
