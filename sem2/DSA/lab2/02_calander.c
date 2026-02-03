/*Problem 2: Design a Calendar
Goal:
Design a calendar for a given month and year using arrays to store:
    ● The names of the days of the week.
    ● The names of the months.
    ● The number of days in each month.
Task:
    ● Implement a C program to display the calendar for any given month and year.*/

#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        return 1;
    return 0;
}

int main()
{

    char *days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    char *months[] = {"January", "February", "March", "April", "May", "June",
                      "July", "August", "September", "October", "November", "December"};

    int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31};

    int month, year;
    int totalDays = 0;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    printf("Enter year: ");
    scanf("%d", &year);

    // Adjust February for leap year
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    // Calculate total days from 1900
    for (int y = 1900; y < year; y++)
    {
        totalDays += isLeapYear(y) ? 366 : 365;
    }
    for (int m = 0; m < month - 1; m++)
    {
        totalDays += daysInMonth[m];
    }
    // January 1, 1900 was a Monday, so we add 1 to align
    int firstDay = (totalDays + 1) % 7;
    firstDay = (firstDay == 0) ? 6 : firstDay - 1;

    printf("\n    %s %d\n", months[month - 1], year);

    for (int i = 0; i < 7; i++)
    {
        printf("%s ", days[i]);
    }
    printf("\n");

    for (int i = 0; i < firstDay; i++)
    {
        printf("    ");
    }
    for (int day = 1; day <= daysInMonth[month - 1]; day++)
    {
        printf("%3d ", day);
        if ((day + firstDay) % 7 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}
