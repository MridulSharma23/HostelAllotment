#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    string id;
    string name;
    int year;
private:
    string roomId;

public:
    Student() {}

    Student(string i, string n, int y, string r)
    {
        id = i;
        name = n;
        year = y;
        roomId = r;
    }

    // Getter for ID (required by FileManager)
    string getId() const { return id; }

    // Getter for room
    string getRoomId() const { return roomId; }

    // ⭐ Setter added (IMPORTANT FIX)
    void setRoomId(string r) { roomId = r; }

    // Display info
    void display() const
    {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Year: " << year
             << " | Room: " << roomId << endl;
    }

    // Convert CSV → Student object
    static Student fromString(string line)
    {
        string id, name, yearStr, room;
        stringstream ss(line);

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, yearStr, ',');
        getline(ss, room, ',');

        int y = 0;
        if (yearStr.size() > 0 && isdigit(yearStr[0]))
            y = yearStr[0] - '0';

        return Student(id, name, y, room);
    }

    // Convert Student → CSV
    string summary() const
    {
        return id + "," + name + "," + to_string(year) + "," + roomId;
    }
};

#endif
