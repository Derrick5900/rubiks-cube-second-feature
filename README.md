# Rubik's Cube Final Project - Feature 1

This project implements **Feature 1: Create and display a Solved Rubik's Cube**
using a `Cube` class and `CubeManager`.

---

##  Current Status

### Completed
- Feature 1 fully implemented
- All unit test pass
  - Test 1: Normal Operation
  - Test 2: Empty Manager
  - Test 3: Boundary Conditions

###  In Progress
- Planning Feature 2: Cube rotations
- Planning Feature 3; Check if cube is solved

###  Known Issues
- None. Feature 1 builds and runs successfully.
- `test_feature` also compiles, runs, and passes every test.

---

##  Project Structure

Rubik_sCubeFirstFeature/
 -----CMakeList.txt
 -----README.md
 -----docs/
|  ----checkpoint1_reflection.md
|  ----checkpoint_tests.md
 ----include/
|  ----Cube.h
|  ----CubeManader.h
 ----src/
|  -----Cube.cpp
|  -----main.cpp
 ----tests/
 ----test_feature.cpp


---

## How to Build & Run

### Build:
Press **Shift+F10** or click the green Run arrow
next to **Rubik_sCubeFirstFeature** in CLion.

### Run Test:
Use the Run menu dropdown -> select **test_feature** -> Run.

All test will pass with output:

---

##  Feature Summary

**Feature 1 Includes:**
- Creates a Rubik's Cube in its solved state using solid colors (W, Y, O, R, G, B)
- Displays all six faces in 3x3 format

**Feature 2 Includes:**
- Rotate a cube face**
- allows user to choose a face (U, D, L, R, F, B)
- Rotates clockwise or counterclockwise
- Display the updated cube

**Feature 3 Includes:**
- Writes cube state to file
- Uses CubeSaver class
- Saves cube name and face colors
- Integrates with cube creation & rotation features


---

##  Reflection Documents
Located in `docs/`:
- `checkpoint1_reflection.md`
-  `checkpoint1_tests.md`

Those documents describe:
- Implementation summary
- What worked well
- Challenges
- What was learned
- Next steps

---