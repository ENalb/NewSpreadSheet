#include <iostream>
#include "date.h"

Date::Date(int y, int m, int d) : year{y}, month{m}, day{d} {}

Date Date::toDate(const std::string& v){
	int year, month, day;
    sscanf(v.c_str(), "%d/%d/%d", &year, &month, &day);
    return Date(year, month, day);
}

void Date::setYear(int y)
{
	year = y;
}

int Date::getYear() const
{
	return year;
}

void Date::setMonth(int m)
{
	month = m;
}

int Date::getMonth() const
{
	return month;
}

void Date::setDay(int d)
{
	day = d;
}

int Date::getDay() const
{
	return day;
}