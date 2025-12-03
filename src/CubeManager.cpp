#include "CubeManager.h"
#include "CubeSaver.h"
#include "Cubeloader.h"

#include <iostream>
#include <limits>

using std::cout;
using std::cin;
using std::string;

// ---------------------------------------------
// Add a cube to the manager
// ---------------------------------------------
void CubeManager::addCube(const Cube& cube) {
    cubes.push_back(cube);
}

int CubeManager::getCubeCount() const {
    return static_cast<int>(cubes.size());
}

Cube* CubeManager::getFirst() {
    if (cubes.empty()) {
        return nullptr;
    }
    return &cubes[0];
}


const Cube* CubeManager::getFirst() const {
    if (cubes.empty()) {
        return nullptr;
    }
    return &cubes[0];
}

// Display all cubes
// ---------------------------------------
void CubeManager::displayAll() const {
    if (cubes.empty()) {
        cout << "No cubes in manager.\n";
        return;
    }
    for (const auto& c : cubes) {
        c.display();  // <- now OK; c is a Cube
    }
}

// -----------------------------------------------
// helper: read face & int -----------------------

// Read an int in [lo, hi]
static int readIntInRange(int lo, int hi) {
    while (true) {
        int value;
        cin >> value;

        if (!cin) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid number. Try again: ";
            continue;
        }

        if (value < lo || value > hi) {
            cout << "Please enter a value between "
                 << lo << " and " << hi << ": ";
            continue;
        }

        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return value;
    }
}

// Read a face letter from thr user (U / D / L / R / F / B)
static Face readFaceFromUser() {
    while (true) {
        cout << "Choose face (U/D/L/R/F/B): ";
        char ch;
        cin >> ch;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (ch) {
            case 'U': case 'u': return Face::U;
            case 'D': case 'd': return Face::D;
            case 'L': case 'l': return Face::L;
            case 'R': case 'r': return Face::R;
            case 'F': case 'f': return Face::F;
            case 'B': case 'b': return Face::B;
            default:
                cout << "Invalid face, Try again.\n";
                break;
        }
    }
}

// -------------------------------------------------------
// Feature 2: rotation runner
// -------------------------------------------------------
void CubeManager::runRotateFaceFeature() {
    Cube* cube = getFirst();
    if (!cube) {
        cout << "No cubes available.\n";
        return;
    }

    Face face = readFaceFromUser();

    cout << "1) Clockwise\n"
         << "2) Counter-Clockwise\n"
         << "3) Choice: ";
    int dir = readIntInRange(1, 2);
    bool clockwise = (dir == 1);

    cube->rotateFace(face, clockwise);
    cout << "Face rotated.\n";
}

// ---------------------------------------------------------------
// Feature 3: save first cube to file
// ---------------------------------------------------------------
void CubeManager::saveFirstCube(const std::string& fileName) const {
    const Cube* cube = getFirst();
    if (!cube) {
        cout << "No cubes available.\n";
        return;
    }

    CubeSaver saver(*cube, fileName);
    saver.save();

    cout << "Cube saved to '" << fileName << "'.\n";
}

// ---- Feature 4: load first cube ------------------------

void CubeManager::loadFirstCube(const std::string& fileName) {
    Cube* cube = getFirst();
    if (!cube) {
        cout << "No cubes available.\n";
        return;
    }

    CubeLoader loader(*cube, fileName);
    loader.load();

    cout << "Cube loaded from '" << fileName << "'.\n";
}