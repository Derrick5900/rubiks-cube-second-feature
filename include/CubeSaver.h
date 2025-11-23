#pragma once

#include <string>
#include "Cube.h"

// Utility class for saving and loading a Cube to/from a file
class CubeSaver {
    public:
        // Save the cube to a text file. Returns true on success.
        static bool save(const Cube& cube, const std::string& filename);

        // Load the cube from a text file. Returns true on success.
        static bool load(Cube& cube, const std::string& filename);
};


