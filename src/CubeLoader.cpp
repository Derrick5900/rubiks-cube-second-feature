#include "Cubeloader.h"
#include <fstream>
#include <string>

CubeLoader::CubeLoader(Cube &cube, const std::string& fileName)
    : cube(cube), fileName(fileName) {}

// Our file format is the same as CubeSaver uses:
// Face 0
// WWW
// WWW
// WWW
// Face 1
// ...
bool CubeLoader::load() {
    std::fstream in (fileName);
    if (!in) {
        return false;
    }

    for (int fi = 0; fi < 6; ++fi) {
        std::string label;
        int faceIndex = -1;

        // Read "Face <number>"
        if (!(in >> label >> faceIndex)) {
            return false;
        }

        // Convert index back to Face enum
        Face f = static_cast<Face>(faceIndex);

        // Read 3 rows of 3 characters
        for (int r = 0; r < 3; ++r) {
            std::string row;
            if (!(in >> row) || row.size() < 3) {
                return false;
            }

            for (int c = 0; c < 3; ++c) {
                char color = row[c];
                cube.setColor(f, r, c, color);
            }
        }
    }

    return true;
}



