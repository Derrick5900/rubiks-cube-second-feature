# Checkpoint 4 Reflection (Feature 4)

## What I built
I added Feature 4 to load the first cube from 'cube_save.txt'

## What worked
- Menu option 4 correctly calls CubeManager::loadFirstCube
- CubeLoader reads file values and updates all 6 faces
- Program safely handles "No cubes available"

## What I learned
- How to restore program state from a file
- How to validate data and avoid crashing when objects don't exist
- How to integrate a new feature into an existing class design

## Next improvements
- Add error message if the file is missing or corrupted
- Allow loading a specific cube (not just thr first)