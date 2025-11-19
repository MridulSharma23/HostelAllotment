#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>
using namespace std;



class Application
{
private:
    string appId;       // Unique application ID (ex: APP001)
    string studentId;   // The student who applied
    string roomId;      // Preferred room
    string status;      // PENDING, APPROVED, REJECTED

public:

    // ---------------------- Constructor ----------------------
    Application(string a, string sId, string rId, string st = "PENDING")
    {
        appId = a;
        studentId = sId;
        roomId = rId;
        status = st;
    }

    // ---------------------- Getters --------------------------
    string getAppId() const { return appId; }

    // Generic ID getter (for templates and map index)
    string getId() const { return appId; }

    string getStudentId() const { return studentId; }
    string getRoomId() const { return roomId; }
    string getStatus() const { return status; }

    // ---------------------- Status Controls -------------------
    void approve()
    {
        status = "APPROVED";
    }

    void reject()
    {
        status = "REJECTED";
    }

    void reset()
    {
        status = "PENDING";
    }

    // ---------------------- Display ---------------------------
    void display() const
    {
        cout << "------------------------------------\n";
        cout << "Application ID : " << appId << endl;
        cout << "Student ID     : " << studentId << endl;
        cout << "Room Requested : " << roomId << endl;
        cout << "Status         : " << status << endl;
        cout << "------------------------------------\n";
    }

    // ---------------------- CSV Support -----------------------

    string summary() const
    {
        return appId + "," + studentId + "," + roomId + "," + status;
    }

    // Convert CSV → Application object
    static Application fromString(string line);

    // ---------------------- Operator Overloading --------------
    friend ostream &operator<<(ostream &out, const Application &a)
    {
        out << "Application[ID=" << a.appId
            << ", Student=" << a.studentId
            << ", Room=" << a.roomId
            << ", Status=" << a.status << "]";
        return out;
    }
};

#endif
