#include "CubeManager.h"

#include <iostream>
#include <limits>
#include <cctype>
#include <stdexcept>

using std::cout;
using std::cin;
using std::endl;

namespace {

    Face charToFace(char ch) {
        ch = static_cast<char>(std::toupper(static_cast<unsigned char>(ch)));
        switch (ch) {
            case 'U': return Face::U;
            case 'D': return Face::D;
            case 'L': return Face::L;
            case 'R': return Face::R;
            case 'F': return Face::F;
            case 'B': return Face::B;
            default:
                throw std::invalid_argument("Invalid face character");
        }
    }
} // end anonymous namespace

CubeManager::CubeManager()
    : cube("Untitled"), hasCube(false) {

}

// ===== Feature 1 ========
void CubeManager::createSolvedCubeAndDisplay() {
    std::string name;
    cout << "Enter cube name (or leave blank for 'Untitled'): ";
    std::getline(cin, name);
    if (name.empty()) {
        name = "Untitled";
    }

    cube = Cube(name);  // create solved cube with that name
    hasCube = true;

    cout << "Created solved cube.\n";
    cube.display();
}

// ======= Feature 2 ========
void CubeManager::runRotateFaceFeature() {
    if (!hasCube) {
        cout << "No cube created yet. Please use option 1 first.\n";
        return;
    }

    char faceInput;
    cout << "Enter face to rotate (U, D, L, R, F, B) ";
    cin >> faceInput;

    char dirInput;
    cout << "Enter direction (C for clockwise, A for anticlockwise); ";
    cin >> dirInput;

    bool clockwise = (dirInput == 'C' || dirInput == 'c');

    try {
        Face face = charToFace(faceInput);
        cube.rotateFace(face, clockwise);

        cout << "Rotated face " << faceInput << (clockwise ? " clockwise.\n" : " counterclockwise.\n");
        cube.display();
    } catch (const std::exception& ex) {
        cout << "Error: " << ex.what() << '\n';
    }

    // clear leftover newline
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}