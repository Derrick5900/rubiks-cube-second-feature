#include <iostream>
#include <limits>
#include "CubeManager.h"

using std::cin;
using std::cout;
using std::string;

int main()
{
    CubeManager manager;

    while (true) {
        cout << "\n=== Rubik's Cube Manger ===\n";
        cout << "1) Create solved cube and display all cubes\n";
        cout << "2) Rotate a cube face\n";
        cout << "3) Save first cube to file\n";
        cout << "0) Exit\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            // input validation
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input.\n";
            continue;;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            cout << "Enter cube name (or leave blank for 'Untitled'):";
            string name;
            std::getline(std::cin, name);
            if (name.empty()) name = "Untitled";

            Cube cube(name);
            manager.addCube(cube);

            cout << "\nCreated cube and displaying all cubes:\n";
            manager.displayAll();
        } else if (choice == 2) {
            manager.runRotateFaceFeature();
        } else if (choice == 3) {
            manager.saveFirstCube("cube_save.txt");
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}