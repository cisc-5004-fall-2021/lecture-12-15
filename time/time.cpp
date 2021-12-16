#include <iostream>
#include "time.h"

using namespace std;

// Default constructor for Time objects.
// We set hours and minutes to sane defaults (0)
Time::Time() {
    hours = 0;
    minutes = 0;
}

// Parameterized constructor for Time objects.
// This constructor requires two integers for hours
// and minutes.
Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

// Add a specified number of hours to the Time object.
void Time::addHours(int h) {
    hours += h;
}

// Add a specified number of minutes to the Time object.
void Time::addMinutes(int m) {
    minutes += m;

    // In case minutes overflow past 60, add the extra
    // time to the hours variable
    hours = hours + (minutes / 60);
    minutes = minutes % 60;
}

// Operator overload: allow addding two Time objects together
Time Time::operator+(const Time &t) const {
    Time newTime;

    newTime.addHours(hours);
    newTime.addHours(t.hours);

    newTime.addMinutes(minutes);
    newTime.addMinutes(t.minutes);

    return newTime;
}

Time Time::operator+(double m) const {
    Time newTime;

    newTime.addHours(hours);
    newTime.addMinutes(minutes);

    newTime.addMinutes(m);

    return newTime;
}

Time operator+(double m, Time& t) {
    Time newTime;

    newTime.addMinutes(m);
    newTime.addMinutes(t.minutes);
    newTime.addHours(t.hours);

    return newTime;
}

ostream & operator<<(ostream &os, Time &t) {
    os << t.hours << ":" << t.minutes;
    return os;
}