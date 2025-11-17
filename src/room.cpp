#include "../include/room.h"
#include <sstream>
using namespace std;


Room Room::fromString(string line)
{
    string id, capStr, occStr;

    stringstream ss(line);

    // Split CSV values
    getline(ss, id, ',');       // example: R101
    getline(ss, capStr, ',');   // example: "3"
    getline(ss, occStr, ',');   // example: "1"

    int capacity = 0;
    int occupied = 0;

    // ========== Convert capacity (simple 1-digit conversion) ==========
    try
    {
        if (capStr.length() == 0)
            throw "Capacity missing!";

        char c = capStr[0];

        if (c < '0' || c > '9')
            throw "Invalid capacity!";

        capacity = c - '0';   // '3' → 3
    }
    catch (const char* msg)
    {
        cout << "Error in Room CSV line: " << line << endl;
        cout << "Reason: " << msg << endl;
        capacity = 1; // safe fallback
    }

    // ========== Convert occupied (same logic) ==========
    try
    {
        if (occStr.length() == 0)
            throw "Occupied value missing!";

        char c = occStr[0];

        if (c < '0' || c > '9')
            throw "Invalid occupied value!";

        occupied = c - '0';   // '1' → 1
    }
    catch (const char* msg)
    {
        cout << "Error in Room CSV line: " << line << endl;
        cout << "Reason: " << msg << endl;
        occupied = 0; // safe fallback
    }

    // Return final Room object
    return Room(id, capacity, occupied);
}
