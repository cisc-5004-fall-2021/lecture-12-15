#include <iostream>

using namespace std;

class Time {
    public:
        Time();
        Time(int, int);
        void display() {
            cout << hours << ":" << minutes << endl;
        }
        void addMinutes(int);
        void addHours(int);
        Time operator+(const Time&) const;
        Time operator+(double) const;    // Supports time + double
        friend Time operator+(double, Time&);   // Supports double + time

        // Output the Time object to an output stream
        // This effectively replaces time.display() above,
        // and allows us to directly stream the Time object
        // to cout or an output file stream.
        //
        // Time objects do not publicly expose their internals
        // (i.e., hour and minute), but we need them to properly
        // display a time. Therefore, this operator overload
        // is a friend of the Time class.
        friend ostream& operator<<(ostream &os, Time &t);
    private:
        int hours;
        int minutes;
};

