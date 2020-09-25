// **************************************************************
// **************************************************************
//
// **********  DO NOT MODIFY ANYTHING IN THIS SECTION
//
// solution cpp file for project 10
// all helper function definitions go in this file

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include "P10.h"

using namespace std;

// **************************************************************
// **************************************************************
//
// **************************************************************
// **********   PUT ALL FUNCTION DEFINITIONS BELOW THIS COMMENT
//
// Function definitions start here. 

// ************** CONTRUCTORS **************
    Date::Date()
    {
        month = 1;
        day = 1;
        year = 1900;
    } //default constructor

    Date::Date(int initMonth, int initDay, int initYear) 
    {
        month = initMonth;
        day = initDay;
        year = initYear;
    }

    Date::Date(int initMonth, int initYear) {
        month = initMonth;
        year = initYear;
        day = 1;
    }
// ************** TRANSFORMERS **************
    void Date::SetDate(int mth, int dy, int yr)
    {
        month = mth;
        day = dy;
        year = yr;
    }

    void Date::IncrementDate() {
        day++;
        switch(month) {
            case 1 :
                if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 2 : 
                if (day > 28) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 3 :
                if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 4 :
                if (day > 30) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 5 :
                if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 6 : 
                if (day > 30) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 7 :
                if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 8 :
                if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 9 :
                if (day > 30) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 10 :
                 if (day > 31) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 11 :
                if (day > 30) {
                    month++;
                    day = 1;
                    break;
                }
                break;
            case 12 :
                if (day > 31) {
                    month = 1;
                    day = 1;
                    year++;
                    break;
                }
                break;
        }
        
    }
// ************** OBSERVERS *******************
    void Date::WriteNumberFormat() const {
        cout << setw(2) << setfill('0') << month << "/" << setw(2) << day << "/" << setfill(' ') << year << endl;
    }
    void Date::WriteNameFormat() const {
        string monthName;
        switch(month) {
            case 1 :
                monthName = "January";
                break;
            case 2 :
                monthName = "February";
                break;
            case 3 : 
                monthName = "March";
                break;
            case 4 :
                monthName = "April";
                break;
            case 5 :
                monthName = "May";
                break;
            case 6 :
                monthName = "June";
                break;
            case 7 :
                monthName = "July";
                break;
            case 8 :
                monthName = "August";
                break;
            case 9 :
                monthName = "September";
                break;
            case 10 :
                monthName = "October";
                break;
            case 11 : 
                monthName = "November";
                break;
            case 12 : 
                monthName = "December";
                break;    
        }
        cout << monthName << " " << day << ", " << year << endl;
    }
    bool Date::SameDate(Date dat) const {
        return (month == dat.month && day == dat.day && year == dat.year);
    }
    bool Date::BeforeDate(Date dat) const {
        return (year < dat.year ||
            year == dat.year && month < dat.month ||
            year == dat.year && month == dat.month && day < dat.day);
    }
    bool Date::AfterDate(Date dat)  const {
        return (year > dat.year ||
            year == dat.year && month > dat.month ||
            year == dat.year && month == dat.month && day > dat.day);
    }


