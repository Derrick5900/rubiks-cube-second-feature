# Checkpoint 1 Test Cases

## Feature: Create & Display Rubik's Cube

### Test Setup
- Test file: `tests/test_feature.cpp`
- Build system: CMake (CLion)
- Run command: `test_feature` run configuration in CLion

### Test 1: Normal Operation
- **What it tests**: Creating a solved cube, adding it to the manager, and checking the first cube and a known color.
- **Expected result**: The manager has 1 cube and the upper-left sticker on the Up face is `'W'`.
- **Result**: Pass

### Test 2: Edge Case (Empty Manager)
- **What it tests**: Behavior when the manager has no cubes.
- **Expected result**: Manager is empty and `getFirst()` returns `nullptr`.
- **Result**: Pass

### Test 3: Boundary Conditions
- **What it tests**: Setting colors at valid and invalid indices.
- **Expected result**:
  - `setColor(Face::F,0,0,'X')` returns `true` and color is `'X'`.
  - `setColor(Face::F,3,0,'X')` returns `false` and lookup returns `'?'`.
- **Result**: Pass

### Test Output

```text
=== Running Tests for Feature 1: Create & Display Cube ===

Test 1: Normal Operation... PASSED
Test 2: Edge Case (Empty Manager)...PASSED
Test 3: Boundary Conditions... PASSED

 All tests passed!

Process finished with exit code 0
