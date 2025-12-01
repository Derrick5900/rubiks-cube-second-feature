#include "../include/Cube.h"
#include "../include/CubeManager.h"
#include <cassert>
#include <iostream>

using std::cout;

void testNormalOperation() {
    std::cout << "Test 1: Normal Operation...";
    Side c("TestCube");
    CubeManager m; m.addCube(c);
    assert(m.getCubeCount() == 1);
    assert(c.getColor(Face::U,0,0) == 'W');
    std::cout << " PASSED\n";
}
void testEdgeCaseEmptyManager() {
    cout <<"Test 2: Edge Case (Empty Manager)...\n";
    CubeManager m;
    assert(m.getCubeCount() == 0);
    assert(m.getFirst() == nullptr);
    std::cout << "PASSED\n";
}
void testBoundaryConditions() {
    std::cout << "Test 3: Boundary Conditions...";
    Side c("Bounds");
    // valid
    assert(c.setColor(Face::F,0,0, 'X') == true);
    assert(c.getColor(Face::F,0,0) == 'X');
    // invalid index
    assert(c.setColor(Face::F,3,0,'X') == false);
    assert(c.getColor(Face::F,3,0) == '?');
    std::cout << " PASSED\n";
}
int main() {
    std::cout << "\n=== Running Tests for Feature 1: Create & Display Cube ===\n\n";
    testNormalOperation();
    testEdgeCaseEmptyManager();
    testBoundaryConditions();
    std::cout << "\n All tests passed!\n";
    return 0;
}