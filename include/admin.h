#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include <string>
using namespace std;

#include "student.h"   // to allow admin to manage students 


//                    ADMIN CLASS


class Admin : public Person
{
private:
    string id;        // admin ID
    string name;      // admin name
    int level;        // admin level (1 = normal, 2 = senior admin)

public:

    // Constructor
    Admin(string i, string n, int l)
    {
        id = i;
        name = n;
        level = l;
    }

    // ------------------- Overrides from Person -------------------
    string getId() const override
    {
        return id;
    }

    // returns details in csv form
    string summary() const override
    {
        return id + "," + name + "," + to_string(level);
    }

    // ------------------- Extra Admin Functions -------------------

    string getName() const { return name; }

    int getLevel() const { return level; }

    // Promote admin to higher level
    void promote()
    {
        level++;
    }

    // Check if admin is senior
    bool isSenior() const
    {
        return level >= 2;
    }

    // Display formatted details
    void display() const
    {
        cout << "------------------------------------\n";
        cout << "Admin ID   : " << id << endl;
        cout << "Name       : " << name << endl;
        cout << "Level      : " << level << endl;
        cout << "------------------------------------\n";
    }

    // Convert CSV → Admin object
    static Admin fromString(string line);

    // For easy printing with cout
    friend ostream& operator<<(ostream& out, const Admin& a)
    {
        out << "Admin[ID=" << a.id
            << ", Name=" << a.name
            << ", Level=" << a.level
            << "]";
        return out;
    }
};

#endif
