#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Room {
public:
    string roomId;
    int capacity;
    int occupied;

    // Default constructor REQUIRED for map[]
    Room() : roomId(""), capacity(0), occupied(0) {}

    Room(string id, int cap, int occ)
        : roomId(id), capacity(cap), occupied(occ) {}

    bool isAvailable() const { return occupied < capacity; }

    void addStudent() { if (occupied < capacity) occupied++; }

    static Room fromString(string line) {
        string id, c, o;
        stringstream ss(line);
        getline(ss, id, ',');
        getline(ss, c, ',');
        getline(ss, o, ',');
        return Room(id, stoi(c), stoi(o));
    }

    string summary() const {
        return roomId + "," + to_string(capacity) + "," + to_string(occupied);
    }

    string getId() const { return roomId; }
};

#endif
