#include "time.h"
#include <fstream>

using namespace std;

/*
    Test program for the Time class.

    We create two Time objets and add them together.
*/

int main () {
    Time t {1, 30};
    Time t2 {0, 121};

    
    Time t3 = t+t2;
    Time t4 = 12 + t;


    // For practice: try opening an output file
    // and writing t4 to it instead
    cout << t4 << endl;
}