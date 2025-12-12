# Checkpoint 4 Plan (Feature 4)

## Goal
Add Feature 4: Load the first cube from a saved file (cube_save.txt) and restore its face colors.

## What I will build
- Add menu option 4: "Load first cube from a saved file"
- Implement CubeLoader class to read cube name + 6 faces from file
- Update first cube's faces with loaded values
- Print confirmation message after load
- Handle case where no cube's exist safely

## Files involved
- main.cpp (menu option + call manager.loadFirstCube)
- CubeManager.cpp / CubeManager.h (file reading + apply to cube)
- CubeLoader.cpp / CubeLoader.h (file reading + apply to cube)
- cube_save.txt (input file format)

## Steps
1. Add option 4 to menu and switch-case
2. Implement CubeManager::loadFirstCube(filename)
3. Implement CubeLoader::load() to read and apply data
4. Test: save cube, change cube, load cube, verify restored
5. Update README feature list