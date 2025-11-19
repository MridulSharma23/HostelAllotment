#include "../include/application.h"
#include <sstream>
using namespace std;


Application Application::fromString(string line)
{
    string appId, studentId, roomId, status;

    stringstream ss(line);

    // Extract values separated by commas
    getline(ss, appId, ',');
    getline(ss, studentId, ',');
    getline(ss, roomId, ',');
    getline(ss, status, ',');

    // ---------------- Basic error checking using try-catch ----------------
    try
    {
        if (appId.length() == 0)
            throw "Missing Application ID!";
        if (studentId.length() == 0)
            throw "Missing Student ID!";
        if (roomId.length() == 0)
            throw "Missing Room ID!";
        if (status.length() == 0)
            throw "Missing Status!";
    }
    catch (const char *msg)
    {
        cout << "Error in Application CSV line: " << line << endl;
        cout << "Reason: " << msg << endl;

        // Provide safe fallback values
        if (status.length() == 0)
            status = "PENDING";
    }

    // Return final Application object
    return Application(appId, studentId, roomId, status);
}
