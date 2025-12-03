#pragma once
#include <vector>
#include <string>
#include "Cube.h"

class CubeManager {
public:
    // Add a cube to the manager
    void addCube( const Cube& cube);

    // How many cubes?
    int getCubeCount() const;

    // First cube (const + non-const overloads)
    Cube*       getFirst();
    const Cube* getFirst() const;

    // Show all cubes
    void displayAll() const;

    // Feature 2: (rotate face)
    void runRotateFaceFeature();

    // Feature 3: save first cube to file
    void saveFirstCube(const std::string& fileName) const;

    // Feature 4: load first cube from file
    void loadFirstCube(const std::string& fileName);

private:
    std::vector<Cube> cubes;
};