#include "CubeManager.h"
#include "CubeSaver.h"
#include <iostream>


using std::cout;
using std::cin;
using std::string;

// ---------------------------------------------
// Add a cube to the manager
// ---------------------------------------------
void CubeManager::addCube(const Cube& cube) {
    cubes.push_back(cube);
}

// ---------------------------------------------
// How many cubes are stored?
// ---------------------------------------------
int CubeManager::getCubeCount() const {
    return static_cast<int>(cubes.size());
}

// -------------------------------------
// First cube (const)
// -------------------------------------
const Cube* CubeManager::getFirst() const {
    if (cubes.empty()) return nullptr;
    return &cubes.front();
}

// --------------------------------------
// Return first cube (non-const)
// -------------------------------------
Cube* CubeManager::getFirst() {
    if (cubes.empty()) return nullptr;
    return &cubes.front();
}

// --------------------------------------
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
// helper: read face letter (U, D, L, R, F, B)
// ------------------------------------------------
static Face readFaceFromUser() {
    while (true) {
        cout << "Choose face (U/D/L/R/F/B): ";
        char ch;
        cin >> ch;

        switch (ch) {
            case 'U': case 'u': return Face::U;
            case 'D': case 'd': return Face::D;
            case 'L': case 'l': return Face::L;
            case 'R': case 'r': return Face::R;
            case 'F': case 'f': return Face::F;
            case 'B': case 'b': return Face::B;
        }

        cout << "Invalid face. try again.\n";
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

    int dir;
    cout << "1) Clockwise\n2) Counter-clockwise\nChoice: ";
    cin >> dir;

    bool clockwise = (dir == 1);
    cube->rotateFace(face, clockwise);
    cube->display();
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