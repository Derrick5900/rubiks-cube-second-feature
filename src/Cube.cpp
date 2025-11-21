#include "Cube.h"

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cctype>

using std::cout;
using std::endl;

// ---------- Helper functions only visible inside this file ----------
namespace {
    // Rotate a 3x3 grid clockwise
    Cube::FaceGrid rotateGridClockwise(const Cube::FaceGrid& g) {
        Cube::FaceGrid result{};
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                result[c][2 - r] = g[r][c];
            }
        }
        return result;
    }

    // Rotate a 3x3 grid counter-clockwise
    Cube::FaceGrid rotateGridCounterClockwise(const Cube::FaceGrid& g) {
        Cube::FaceGrid result{};
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                result[2 - c][r] = g[r][c];
            }
        }
        return result;
    }
} // end ananymoys namespace


// ----------- Static helper for default colors ---------

char Cube::defaultColor(Face f) {
    switch (f) {
        case Face::U: return 'W'; // UP = White
        case Face::D: return 'Y'; // Down = Yellow
        case Face::L: return 'O'; // Left = Orange
        case Face::R: return 'R'; // Right = Red
        case Face::F: return 'G'; // Front = Green
        case Face::B: return 'B'; // Back = Blue
    }
    return '?';
}

// ---------- Constructors -----------

Cube::Cube() : Cube("Untitled") {}

Cube::Cube(const std::string& cubeName) : name(cubeName) {
    // initialize to solve state
    for (int fi = 0; fi < 6; ++fi) {
        char c = defaultColor(static_cast<Face>(fi));
        for (int r = 0; r < 3; ++r) {
            for (int col = 0; col < 3; ++col) {
                faces[fi][r][col] = c;
            }
        }
    }
}

// -------- accessors / mutators ------------

const std::string& Cube::getName() const {
    return name;
}

char Cube::getColor(Face f, int row, int col) const {
    int fi = static_cast<int>(f);
    if (fi < 0 || fi >= 6 || row < 0 || row >= 3 || col < 0 || col >= 3) {
        throw std::out_of_range("getColor: invalid indices");
    }
    return faces[fi][row][col];
}

// ------------- Mutators ---------------

void Cube::setName(const std::string& newName) {
    name = newName;
}

bool Cube::setColor(Face f, int row, int col, char color) {
    int fi = static_cast<int>(f);
    if (fi < 0 || fi >= 6 || row < 0 || row >= 3 || col < 0 || col >= 3) {
        return false;
    }
    faces[fi][row][col] = color;
    return true;
}

// ---------- Display -------
void Cube::display() const {
    static const char* faceNames[6] = { "U", "D", "L", "R", "F", "B" };

    cout << "\nCube: " << name << endl;

    for (int f = 0; f < 6; ++f) {
        cout << faceNames[f] << " face:\n";
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                cout << faces[f][r][c] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
}

// ------------ Second feature: rotate a face --------------

void Cube::rotateFace(Face face, bool clockwise) {
    int index = static_cast<int>(face);
    if (index < 0 || index >= 6) {
        throw std::out_of_range("rotateFace: invalid face");
    }

    FaceGrid& grid = faces[index];

    if (clockwise) {
        grid = rotateGridClockwise(grid);
    } else {
        grid = rotateGridCounterClockwise(grid);
    }

    // For this checkpoint we only rotate the face itself.
    // Full Rubik's behavior (rotating adjacent edges) will be added later.
}





