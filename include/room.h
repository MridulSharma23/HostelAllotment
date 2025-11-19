#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
using namespace std;


class Room
{
private:
    string roomId;     // Example: R101
    int capacity;      // Total beds
    int occupied;      // Students currently living

public:

    // ---------------------- Constructor ----------------------
    Room(string id, int cap, int occ)
    {
        roomId = id;
        capacity = cap;
        occupied = occ;
    }

    // ---------------------- Getters --------------------------
    string getRoomId() const { return roomId; }

    // Generic ID getter (for templates and map index)
    string getId() const { return roomId; }

    int getCapacity() const { return capacity; }
    int getOccupied() const { return occupied; }

    // ---------------------- Room Logic ------------------------

    // Check if room has empty beds
    bool isAvailable() const
    {
        return occupied < capacity;
    }

    // Try adding a student if room has space
    bool addStudent()
    {
        if (isAvailable())
        {
            occupied++;
            return true;
        }
        return false;
    }

    // Try removing a student if someone is living
    bool removeStudent()
    {
        if (occupied > 0)
        {
            occupied--;
            return true;
        }
        return false;
    }

    // Display full room information
    void display() const
    {
        cout << "------------------------------------\n";
        cout << "Room ID    : " << roomId << endl;
        cout << "Capacity   : " << capacity << endl;
        cout << "Occupied   : " << occupied << endl;

        if (isAvailable())
            cout << "Status     : Available\n";
        else
            cout << "Status     : Full\n";

        cout << "------------------------------------\n";
    }

    // Convert object → CSV string
    string summary() const
    {
        return roomId + "," + to_string(capacity) + "," + to_string(occupied);
    }

    // Convert CSV string → Room object
    static Room fromString(string line);

    // For printing with cout
    friend ostream& operator<<(ostream& out, const Room& r)
    {
        out << "Room[ID=" << r.roomId
            << ", Capacity=" << r.capacity
            << ", Occupied=" << r.occupied
            << "]";
        return out;
    }
};

#endif
