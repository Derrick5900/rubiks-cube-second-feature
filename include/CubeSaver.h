#pragma once

#include <string>
#include "Cube.h"

class CubeSaver {
public:
    // Construct with the cube to save and target file name
    CubeSaver(const Cube& cube, const std::string& fileName);

    // Actually write the cube to the file
    void save() const;

private:
    const Cube& cube;     // reference to the cube we're saving
    std::string fileName; // where to save it
};


