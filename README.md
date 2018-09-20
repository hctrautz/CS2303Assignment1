Hunter Trautz - hctrautz
HW1 - Calendar Assignment, README.txt

Instructions: Navigate to the directory where the program is stored and then
compile the program through terminal with the command: gcc -Wall -o PA1 PA1.c
After running the program with the command ./PA1, enter any positive positive number for the year
and a calendar will be printed for that year.

Description:
My calendar program works by first asking the user to input a year, if the year is not positive
then the program will print an error and prompt for another year. Next, the program takes the user's
year and runs the printCalendar function with the user's year and the first day of the week of that year.
The first day of the week is calculated by Tomohiko Sakamoto's algorithm, which calculates the day of the
week of any day of any year. Although, I changed the algorithm by plugging in 1 for the month
variable and the day variable. This is because, for this program, we always want to calculate the day of the week
of the first of January of the inputed year.

I obtained the algorithm from this source:s
 https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods

Here is the original code for the algorithim:
int dow(int y, int m, int d){
  static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
  y -= m < 3;
  return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

Next the printCalendar function prints the Calendar's header and then loops (for every month)
through the printMonth function, which prints the name of the month and the days of the month in the correct positions,
leaving blank spaces for the days not used. The printMonth function also returns the day of the week that it stopped on,
so that it continue right where it left off, without having to calculate a startingDay again.

Loop Invariants:

printMonth loop #1:
INVARIANT: Day variable will always be less than 7 and greater than or equal to 0, will run when 0<=day<=6

printMonth loop #2:
INVARIANT: The day variable will always be less than the totalDays in a month + the day of the dayOfWeek (0-6)
that the month starts on. Day will always be greater than 0 and run until it equals totalDays+startingDay

printCalendar loop #1:
INVARIANT: Month variable will always be less than 12 and greater than or equal to 0, will run when 0<=day<=11
