#include "../include/Cube.h"
#include "../include/CubeManager.h"
#include <cassert>
#include <iostream>

void testNormalOperation() {
    std::cout << "Test 1: Normal Operation...";
    Cube c("TestCube");
    CubeManager m; m.addCube(c);
    assert(m.getCubeCount() == 1);
    assert(c.getColor(Face::U,0,0) == 'W');
    std::cout << " PASSED\n";
}
void testEdgeCase() {
    std::cout << "Test 2: Edge Case (Empty Manager)...";
    CubeManager m;
    assert(m.isEmpty());
    assert(m.getFirst() == nullptr);
    std::cout << "PASSED\n";
}
void testBoundaryConditions() {
    std::cout << "Test 3: Boundary Conditions...";
    Cube c("Bounds");
    assert(c.setColor(Face::F,0,0, 'X') == true);
    assert(c.getColor(Face::F,0,0) == 'X');
    assert(c.setColor(Face::F,3,0,'X') == false);
    assert(c.getColor(Face::F,3,0) == '?');
    std::cout << " PASSED\n";
}
int main() {
    std::cout << "\n=== Running Tests for Feature 1: Create & Display Cube ===\n\n";
    testNormalOperation();
    testEdgeCase();
    testBoundaryConditions();
    std::cout << "\n All tests passed!\n";
    return 0;
}