#pragma once

#include <string>
#include "Cube.h"

class CubeLoader {
public:
    // Construct with cube to fill and file name tp load from
    CubeLoader(Cube& cube, const std::string& fileName);

    // Load colors into the cube. Returns true on success.
    bool load();

private:
    Cube& cube;
    std::string fileName;
};