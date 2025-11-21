#include <iostream>
#include <limits>
#include "include/CubeManager.h"
#include "include/Cube.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    CubeManager manager;

    while (true) {
        cout << "\n=== Rubik's Cube Manger ===\n";
        cout << "1) Create solved cube and display all cubes\n";
        cout << "2) Rotate a cube face\n";
        cout << "0) Exit\n";
        cout << "Choice: ";

        int choice;
        if (!(cin >> choice)) {
            // input validation
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input, try again.\n";
            continue;
        }

        // Clear leftover newline
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        if (choice == 1) {
            manager.createSolvedCubeAndDisplay();
            continue;
        }

        if (choice == 2) {
            manager.runRotateFaceFeature();
            continue;
        }

        std::cout << "Unknown option, try again.\n";
    }

    return 0;
}