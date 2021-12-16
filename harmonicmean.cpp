#include <iostream>

using namespace std;

// Custom error classes that allow us to throw very
// specific and descriptive errors from the harmonicMean
// function
class BadInputError{};
class DivideByZeroError{};

double harmonicMean(double x, double y) {
    // Error condition 1: Both x and y are 0.
    // For our problem domain and chosen program design,
    // this warrants throwing a BadInputError exception.
    if (x == 0 && y == 0) {
        throw BadInputError();
    }

    // Error condition 2: x = -y, resulting in a divide
    // by zero. For our problem domain and chosen problem
    // design, this warrants throwing a DivideByZeroError
    // exception.
    if (x == -y) {
        throw DivideByZeroError();
    }

    return 2.0 * x * y / (x + y);
}

int main() {
    double x;
    double y;
    char r = 'y';

    while(r == 'y') {
        cout << "x: ";
        cin >> x;
        cout << "y: ";
        cin >> y;

        // Try block: Try calling harmonicMean(), which could
        // throw an error depending on the input we received.
        try {
            cout << harmonicMean(x, y) << endl;
        } catch(DivideByZeroError e) {
            // Catch a DivideByZeroError: Leave a useful message and continue
            cout << "Error: Tried to divide by zero" << endl;
        } catch(BadInputError e) {
            // Catch a BadInputError: Leave a useful message and continue
            cout << x << " and " << y << " are not valid inputs for harmonic mean" << endl;
        }
        cout << "Continue? y/n: ";
        cin >> r;
    }
    return 0;
}