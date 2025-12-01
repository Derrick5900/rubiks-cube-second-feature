#include "CubeSaver.h"
#include <fstream>

CubeSaver::CubeSaver(const Cube& cube, const std::string& fileName)
    : cube(cube), fileName(fileName)
{
}

// Write the cube information to the file
void CubeSaver::save() const
{
    std::ofstream out(fileName);
    if (!out) {
        return;
    }

    // write all 6 faces in a simple text format
    for (int fi = 0; fi < 6; ++fi) {
        Face f = static_cast<Face>(fi);

        out << "Face " << fi << '\n';

        for (int r = 0; r < 6; ++r) {
            for (int c = 0; c < 3; ++c) {
                out << cube.getColor(f, r, c);
            }
            out << '\n';
        }
        out << '\n';
    }
}