## Checkpoint 3 - Plan (Feature 3: Save Cube to File)

## Goal
Implement Feature 3 so CubeManager can save the first cube to a text file (`cube_save.txt`) using the CubeSaver class.

## Task
1. Add CubeSaver class with:
- Constructor that accepts a const Cube* and filename.
- A `save()` function that writes all 6 faces to the file.
2. Update CubeManager to include:
- `saveFirstCube(const std::string& fileName) const`
3. In CubeManager::saveFirstCube:
- Check if at least one cube exists.
- if none -> print "No cubes available."
- Otherwise call CubeSaver to save the cube.
4. Run test for Feature 3.

## Expected Output
The file should contain:
- `Face 0` with 3x3 colors
- `Face 1`...
- Through `Face 5`