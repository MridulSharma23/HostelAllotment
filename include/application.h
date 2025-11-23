#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Application
{
public:
    string appId;
    string studentId;
    string roomId;
    string status;

    // Default constructor
    Application() {}

    // Correct 4-argument constructor
    Application(string a, string sId, string rId, string st = "PENDING")
    {
        appId = a;
        studentId = sId;
        roomId = rId;
        status = st;
    }

    // Needed by FileManager
    string getId() const { return appId; }
    string getStudentId() const { return studentId; }
    string getRoomId() const { return roomId; }

    void approve() { status = "APPROVED"; }
    void reject() { status = "REJECTED"; }

    void display() const
    {
        cout << "AppID: " << appId
             << " | Student: " << studentId
             << " | Room: " << roomId
             << " | Status: " << status << endl;
    }

    // Convert CSV line ---> Application object
    static Application fromString(string line)
    {
        string a, sId, rId, st;
        stringstream ss(line);

        getline(ss, a, ',');
        getline(ss, sId, ',');
        getline(ss, rId, ',');
        getline(ss, st, ',');

        return Application(a, sId, rId, st);
    }

    // Convert Application ---> CSV line
    string summary() const
    {
        return appId + "," + studentId + "," + roomId + "," + status;
    }
};

#endif
