#pragma once

#include "Cube.h"
#include <string>

class CubeManager {
private:
    Cube cube;
    bool hasCube;

public:
    CubeManager();

    // ===== Feature 1 =======
    void createSolvedCubeAndDisplay();

    // ===== Feature 2 ========
    void runRotateFaceFeature();

};
