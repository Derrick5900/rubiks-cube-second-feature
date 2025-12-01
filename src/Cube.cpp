#include "Cube.h"
#include <iostream>

using std::cout;
using std::string;

// -------- static helpers --------------

char Cube::defaultColor(Face f) {
    switch (f) {
        case Face::U: return 'W';  // Up: white
        case Face::D: return 'Y';  // Down: yellow
        case Face::L: return 'O';  // Left: orange
        case Face::R: return 'R';  // Right: red
        case Face::F: return 'G';  // Front: green
        case Face::B: return 'B';  // Back: blue
    }
    return '?';
}

bool Cube::inRange(int r, int c) {
    return (r >= 0 && r < 3 && c >= 0 && c < 3);
}

// ---- constructor -----------------

Cube::Cube(const string& n)
    : name(n) {
    initFaces();
    initSides();
}

// ----------------- init helpers ---------------------------------

void Cube::initFaces() {
    for (int i = 0; i < 6; ++i) {
        Face f = static_cast<Face>(i);
        char color = defaultColor(f);

        FaceGrid& grid = faces[static_cast<int>(f)];
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                grid[r][c] = color;
            }
        }
    }
}

void Cube::initSides() {
    for (int i = 0; i < 6; ++i) {
        Face f = static_cast<Face>(i);
        // attach sideStorage[i] to corresponding face grid
        sideStorage[i].attach(f, &faces[static_cast<int>(f)]);
        sides[i] = &sideStorage[i];   // Cube includes pointers to all 6 Sides
    }
}

// --------------- name + color -------------------------------

string Cube::getName() const {
    return name;
}

void Cube::setName(const string& n) {
    name = n;
}

char Cube::getColor(Face f, int r, int c) const {
    if (!inRange(r, c)) return '?';
    return faces[static_cast<int>(f)][r][c];
}

bool Cube::setColor(Face f, int r, int c, char color)
{
    if (!inRange(r, c)) return false;
    faces[static_cast<int>(f)][r][c] = color;
    return true;
}

// ---------------------- side access ------------------------

Side* Cube::getSide(Face f) {
    return sides[static_cast<int>(f)];
}

const Side* Cube::getSide(Face f) const {
    return sides[static_cast<int>(f)];
}

// --------- rotation logic (Feature 2 + side pointers) ------
// public wrappers so both old and new names wor
void Cube::rotateFaceGridOnly(Face f, bool clockwise) {
    FaceGrid src = faces[static_cast<int>(f)];
    FaceGrid dst{};

    if (clockwise) {
        // (r, c) -> (c, 2 - r) pattern
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                dst[r][c] = src[2 - c][r];
            }
        }
    } else {
        // counter-clockwise: inverse mapping
        for (int r = 0; r < 6; ++r) {
            for (int c = 0; c < 3; ++c) {
                dst[r][c] = src[c][2 - r];
            }
        }
    }

    faces[static_cast<int>(f)] = dst;
}

// For now this rotates just the Face grid itself ( no neighbor edge stickers)
void Cube::rotateFace(Face f, bool clockwise) {
    rotateFaceGridOnly(f, clockwise);
}

// ------------------ display ---------------------------------------------

static void printFace(const Cube::FaceGrid& g, const char* label) {
    cout << label << "\n";
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            cout << g[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void Cube::display() const {
    cout << "Cube: " << name << "\n\n";
    printFace(faces[static_cast<int>(Face::U)], "Up (U):");
    printFace(faces[static_cast<int>(Face::D)], "Down (D):");
    printFace(faces[static_cast<int>(Face::L)], "Left (L):");
    printFace(faces[static_cast<int>(Face::R)], "Right (R):");
    printFace(faces[static_cast<int>(Face::F)], "Front (F):");
    printFace(faces[static_cast<int>(Face::B)], "Back (B):");
}
