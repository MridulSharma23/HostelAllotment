#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
using namespace std;



class FileManager
{
public:

    // ---------------------------------------------------
    //      Load ANY Class T from a CSV file
    // ---------------------------------------------------
    template <class T>
    static map<string, T> loadAll(string filename)
    {
        map<string, T> data;
        ifstream file(filename);

        if (!file.is_open())
        {
            cout << "Error opening file: " << filename << endl;
            return data;  // return empty map
        }

        string line;

        while (getline(file, line))
        {
            if (line.length() == 0)
                continue; // skip empty lines

            // Convert CSV line → object
            T obj = T::fromString(line);

            // Store in map using object.getId()
            data[obj.getId()] = obj;
        }

        file.close();
        return data;
    }

    // ---------------------------------------------------
    //      Save ANY Class T to a CSV file
    // ---------------------------------------------------
    template <class T>
    static void saveAll(map<string, T> &data, string filename)
    {
        ofstream file(filename);

        if (!file.is_open())
        {
            cout << "Error opening file for writing: " << filename << endl;
            return;
        }

        // Write ALL entries
        for (auto &entry : data)
        {
            file << entry.second.summary() << endl;
        }

        file.close();
    }
};

#endif
