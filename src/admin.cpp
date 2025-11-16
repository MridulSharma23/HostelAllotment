#include "../include/admin.h"
#include <sstream>
using namespace std;


Admin Admin::fromString(string line)
{
    string id, name, levelStr;

    stringstream ss(line);

    // Split by commas
    getline(ss, id, ',');        // admin ID
    getline(ss, name, ',');      // admin name
    getline(ss, levelStr, ',');  // admin level (as string)

    int level = 0;

    // ---------------- Simple conversion with try-catch ----------------
    try
    {
        if (levelStr.length() == 0)
            throw "Level missing!";

        char c = levelStr[0];    // only first digit

        if (c < '0' || c > '9')
            throw "Invalid level!";

        level = c - '0';
    }
    catch (const char* msg)
    {
        cout << "Error in Admin CSV line: " << line << endl;
        cout << "Reason: " << msg << endl;
        level = 1; 
    }

    // Return final Admin object
    return Admin(id, name, level);
}
