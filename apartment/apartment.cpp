#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

// A custom exception class: we use this to indicate the user
// supplied bad dimensions for the rom
class BadDimensionException {};

// A class describing a room in a department
class Room {
    public:
        // This default constructor exists to support the
        // >> override function below. From a class design
        // perspective, it probably isn't a great idea to
        // do this: rooms have to have a width and a length,
        // and it doesn't make sense for a room to be 0x0.
        // See the commented code in main() to understand
        // why this is here.
        Room() {
            w = 0;
            l = 0;
        }
        Room(int w, int l) {
            // The class throws an exception if the width or
            // height variables are bad (i.e., they're less 
            // than 1). Doing this here allows us to prevent the
            // creation of a bad Room class, no matter where
            // the bad data comes from.
            if (this->w < 0 || this->l < 0) {
                throw BadDimensionException();
            }

            this->w = w;
            this->l = l;
        }

        // Calculate the square footage of the room
        int sqft() {
            return w * l;
        }

        // An operator override for the << operator
        // This allows us to output the room to any output
        // stream, including cout or an output file.
        // It is a friend function because we could not access
        // the private width and height member variables
        // otherwise.
        friend ostream& operator<<(ostream &os, Room &r);

        // An operator override for the >> operator
        // This allows us to read an input stream,
        // including cin or an input file, to fill a Room
        // with width and height dimensions.
        // Note that doing this requires us to have a Room
        // object created and avaliable to accept input from
        // the stream, which is not ideal: if you know you want
        // to read a Room from some input stream, it is often
        // better to read from the stream yourself and invoke the
        // Room constructor.
        //
        // Due to how this specific input stream operator overload works,
        // reading from the stream to populate values into a Room
        // requires the input stream to provide width and height
        // values separated by a space.
        friend istream& operator>>(istream &os, Room &r);
    private:
        int w;
        int l;
};

// Implementation of << operator overload
ostream& operator<<(ostream &os, Room &r) {
    os << "Room " << r.w << "x" << r.l << ": " << r.sqft();
    return os;
}

// Implementation of >> operator overload
istream& operator>>(istream &is, Room &r) {
    is >> r.w;
    is >> r.l;

    return is;
}

Room getRoom() {
    int w;
    int l;

    cout << "Width of room: ";
    cin >> w;
    cout << "Length of room: ";
    cin >> l;

    return Room {w, l};
}

int main() {
    vector<Room> rooms;

    while (true) {
        try {
            Room r = getRoom();
            rooms.push_back(r);
        } catch(BadDimensionException e) {
            cout << "Invalid room dimensions!" << endl;
        }

        char c;
        cout << "Continue? ";
        cin >> c;

        if (c == 'n') {
            break;
        }
    }

    // This code reads extra rooms from a file. Uncomment
    // it to load additional rooms beyond what is requested
    // from cin. Note that the code requires a Room objet to
    // overwrite with values read from the file, making it not
    // ideal if we don't want Room objects to have a default
    // constructor.

    // ifstream infile;
    // infile.open("rooms.txt");
    // Room r;
    // while(infile >> r) {
    //     rooms.push_back(r);
    // }
    // infile.close();

    int sqft = 0;
    for (Room r: rooms) {
        sqft += r.sqft();
        cout << r << endl;
    }
    cout << "Total: " << sqft << endl;
}