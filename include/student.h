#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

//                ABSTRACT BASE CLASS: Person
class Person
{
public:
    // Pure virtual functions 
    virtual string getId() const = 0;
    virtual string summary() const = 0;

    // Virtual destructor 
    virtual ~Person() {}
};


//                       STUDENT CLASS

// This class inherits from Person and represents a student
// in your Hostel Allotment System.
// It contains: ID, Name, Year of study, Room allocation.
class Student : public Person
{
private:
    string id;       // Student ID (unique)
    string name;     // Student name
    int year;        // Year of study (1/2/3/4)
    string roomId;   // Room assigned (empty if not assigned)

public:


    //                    Constructor
    
    Student(string i, string n, int y, string r = "")
    {
        id = i;
        name = n;
        year = y;
        roomId = r;
    }

    
    //          Overrides the abstract functions of Person.
    string getId() const override
    {
        return id;
    }

    
    string summary() const override
    {
        return id + "," + name + "," + to_string(year) + "," + roomId;
    }


    string toCSV() const
    {
        return summary();
    }

    // -------------------------------------------------------
    //                     Getters
    // -------------------------------------------------------
    string getName() const { return name; }
    int getYear() const { return year; }
    string getRoomId() const { return roomId; }

    // -------------------------------------------------------
    //                     Setters
    // -------------------------------------------------------
    // Update room ID
    void setRoomId(string r)
    {
        roomId = r;
    }

    // Update student name
    void updateName(string newName)
    {
        name = newName;
    }

    // Update student year
    void updateYear(int newYear)
    {
        year = newYear;
    }

    

    // Check if student already has a room
    bool hasRoom() const
    {
        return roomId != "";
    }

    // Remove the room allocation
    void clearRoom()
    {
        roomId = "";
    }

    // Business logic: Check if student is senior
    bool isSenior() const
    {
        return year >= 3; // 3rd or 4th year = senior
    }

    // Check if 2 IDs match (useful for searching)
    bool compareId(string otherId) const
    {
        return id == otherId;
    }

    // Display student details in clean format
    void display() const
    {
        cout << "------------------------------------\n";
        cout << "Student ID   : " << id << endl;
        cout << "Name         : " << name << endl;
        cout << "Year         : " << year << endl;
        if (roomId == "")
            cout << "Room         : Not allotted\n";
        else
            cout << "Room         : " << roomId << endl;
        cout << "------------------------------------\n";
    }

    // Format expected:
    // id,name,year,roomId
    // Example:
    // s1,Ananya,2,R101
    static Student fromString(string line);

   
    //     Operator overloading for printing << 
   
    friend ostream &operator<<(ostream &out, const Student &s)
    {
        out << "Student[ID=" << s.id
            << ", Name=" << s.name
            << ", Year=" << s.year
            << ", Room=" << s.roomId
            << "]";
        return out;
    }
};

#endif
