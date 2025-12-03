#include <iostream>
#include <limits>
#include "CubeManager.h"

using std::cin;
using std::cout;
using std::string;

// Helper: safely read an integer in a range
int readIntInRange(int min, int max) {
    while (true) {
        int value;
        cin >> value;

        if (!cin) {
            // Non-numeric input
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
            cout << "Choice: ";
            continue;
        }

        if (value < min || value > max) {
            cout << "Choice is out of range. Please enter a number between " << min << " and " << max
                 << ".\n";
            cout << "Choice: ";
            continue;;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

int main() {
    CubeManager manager;

    while (true) {
        cout << "\n=== Rubik's Cube Manger ===\n";
        cout << "1) Create solved cube and display all cubes\n";
        cout << "2) Rotate a cube face\n";
        cout << "3) Save first cube to file\n";
        cout << "4) Load first cube from file\n";
        cout << "0) Exit\n";
        cout << "Choice: ";

        // main menu allows 0-4
        int choice = readIntInRange(0, 4);

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                // Create a new solved cube and display all cubes
                Cube cube("Default Cube");
                manager.addCube(cube);
                manager.displayAll();
                break;
            }
            case 2:
                // Rotate a face on the first cube
                manager.runRotateFaceFeature();
                break;

                case 3:
                // Save first cube to file
                manager.saveFirstCube("cube_save.txt");
                break;

                case 4:
                // load first cube from cube_save.txt
                manager.loadFirstCube("cube_save.txt");
                break;

                default:
                // Should never happen because of readIntInRange
                cout << "Unknown option.\n";
                break;
            }
        }
        return 0;
    }