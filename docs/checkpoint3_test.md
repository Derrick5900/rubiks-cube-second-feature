# Checkpoint 3 - Test (Feature 3: Save Cube to File)

## Test 1 - Normal Operation
**Goal:** Ensure a solved cube is saved correctly.
**Steps:**
1. Create a CubeManager.
2. Add one solved Cube.
3. Call saveFirstCube.
4. Check the file contents.

**Expected:**
File contains 6 faces (0-5), each face has excatly 3 rows of 3 identical letters.

Result: **PASSED**

----

## Test 2 - Empty Manager
**Goal:** Saving with no cubes should not crash.

**Steps:**
1. Create a CubeManager.
2. Call saveFirstCube("cube_save.txt") without adding a cube.

**Expected:**
Program prints:
`No cubes available.`
No file written.

Result: **PASSED**

----

## Test 3 - Data Accuracy
**Goal:** Ensure colors saved match the Cube's internal data.

**Steps:**
1. After saving, open `cube_save.txt`.
2. Compare all 9 chars of all 6 faces.
3. verify U=WWW, D=YYY, L=OOO, R=RRR, F=GGG, B=BBB.

Result: **PASSED**