#include <iostream>
#include <map>
#include "../include/student.h"
#include "../include/admin.h"
#include "../include/room.h"
#include "../include/application.h"
#include "../include/file_manager.h"

using namespace std;

int main()
{
   
    map<string, Student> students =
        FileManager::loadAll<Student>("data/students.txt");

    map<string, Admin> admins =
        FileManager::loadAll<Admin>("data/admins.txt");

    map<string, Room> rooms =
        FileManager::loadAll<Room>("data/rooms.txt");

    map<string, Application> apps =
        FileManager::loadAll<Application>("data/applications.txt");


    cout << "=============================================\n";
    cout << "     HOSTEL ALLOTMENT MANAGEMENT SYSTEM\n";
    cout << "=============================================\n\n";

    int choice;

    while (true)
    {
        cout << "\n--------- MENU ---------\n";
        cout << "1. Show all students\n";
        cout << "2. Show all rooms\n";
        cout << "3. Show all applications\n";
        cout << "4. Approve an application\n";
        cout << "5. Reject an application\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        switch (choice)
        {
        case 1:
            cout << "\n----- STUDENTS -----\n";
            for (auto &p : students)
            {
                p.second.display();
            }
            break;

        case 2:
            cout << "\n----- ROOMS -----\n";
            for (auto &p : rooms)
            {
                p.second.display();
            }
            break;

        case 3:
            cout << "\n----- APPLICATIONS -----\n";
            for (auto &p : apps)
            {
                p.second.display();
            }
            break;

        case 4:
        {
            cout << "\nEnter Application ID to APPROVE: ";
            string appId;
            cin >> appId;

            if (apps.find(appId) == apps.end())
            {
                cout << "Invalid Application ID!\n";
                break;
            }

            Application &ap = apps[appId];
            string studentId = ap.getStudentId();
            string roomId = ap.getRoomId();

            // Try to assign room
            if (rooms[roomId].isAvailable())
            {
                rooms[roomId].addStudent();
                ap.approve();
                students[studentId].roomId = roomId; // student now lives there
                cout << "Application Approved & Room Assigned!\n";
            }
            else
            {
                cout << "Room is FULL! Cannot approve.\n";
            }

            break;
        }

        case 5:
        {
            cout << "\nEnter Application ID to REJECT: ";
            string appId;
            cin >> appId;

            if (apps.find(appId) == apps.end())
            {
                cout << "Invalid Application ID!\n";
                break;
            }

            apps[appId].reject();
            cout << "Application Rejected.\n";

            break;
        }

        default:
            cout << "Invalid option!\n";
            break;
        }
    }

    // ============================================================
    //                SAVE CHANGES BACK TO FILES
    // ============================================================
    FileManager::saveAll<Student>(students, "data/students.txt");
    FileManager::saveAll<Admin>(admins, "data/admins.txt");
    FileManager::saveAll<Room>(rooms, "data/rooms.txt");
    FileManager::saveAll<Application>(apps, "data/applications.txt");

    cout << "\nAll changes saved successfully. Exiting...\n";

    return 0;
}
