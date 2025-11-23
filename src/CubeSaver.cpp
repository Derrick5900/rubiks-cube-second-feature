#include "CubeSaver.h"

#include <fstream>
#include <iostream>

// We will save and load faces in this fixed order.
static const Face FACE_ORDER[6] = {
    Face::U, Face::D, Face::L, Face::R, Face::F, Face::B
};

bool CubeSaver::save(const Cube& cube, const std::string& filename) {
    std::ofstream out(filename);
    if (!out) {
        std::cout << "Error: could not open '" << filename << "' for writing.\n";
        return false;
    }

    // First line: cube name
    out << cube.getName() << '\n';

    // Then 6 faces * 3 rows each
    for (int fi = 0; fi < 6; ++fi) {
        Face f = FACE_ORDER[fi];
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                out << cube.getColor(f, r, c);
            }
            out << '\n';
        }
    }

    std::cout << "Cube saved to '" << filename << "'.\n";
    return true;
}

bool CubeSaver::load(Cube& cube, const std::string& filename) {
    std::ifstream in(filename);
    if (!in) {
        std::cout << "Error: could not open '" << filename << "' for reading.\n";
        return false;
    }
    // Read cube name
    std::string name;
    if (!std::getline(in, name)) {
        std::cout << "Error: save file is empty.\n";
        return false;
    }
    if (name.empty()) {
        name = "Loaded cube";
    }
    cube.setName(name);

    // Read back 6 faces * 3 rows each, in same order
    std::string line;
    for (int fi = 0; fi < 6; ++fi) {
        Face f = FACE_ORDER[fi];
        for (int r = 0; r < 3; ++r) {
            if (!std::getline(in, line)) {
                std::cout << "Error: save file is incomplete.\n";
                return false;
            }
            if (line.size() < 3) {
                std::cout << "Error: row in save file is too short.\n";
                return false;
            }
            for (int c = 0; c < 3; ++c) {
                cube.setColor(f, r, c, line[c]);
            }
        }
    }

    std::cout << "Cube loaded from '" << filename << "'.\n";
    return true;
}