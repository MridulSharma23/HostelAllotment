#include "../include/student.h"
#include <sstream>
using namespace std;

Student Student::fromString(string line)
{
    string id, name, yearStr, room;

    stringstream ss(line);

    
    getline(ss, id, ',');      // student id
    getline(ss, name, ',');    // student name
    getline(ss, yearStr, ','); // year (as string)
    getline(ss, room, ',');    // room id

    int year = 0;


    //   SIMPLE conversion: only check FIRST character
   
    try
    {
        if (yearStr.length() == 0)
        {
            throw "Year missing!";
        }

        char c = yearStr[0];   // take FIRST character only

        if (c < '0' || c > '9')
        {
            throw "Invalid year!";
        }

        year = c - '0';  // convert single digit char → int
    }
    catch (const char* msg)
    {
        cout << "Error in line: " << line << endl;
        cout << "Reason: " << msg << endl;
        year = 0;  
    }

    // Return final Student object
    return Student(id, name, year, room);
}
