# Checkpoint 3 - Reflection (Feature 3: Save Cube to File)

## What I Completed
I successfully implemented Feature 3 which allows saving the first cube to a text file.
I added the CubeSaver class and updated CubeManager to call it.
The save file includes all 6 faces in the required formatting.

## Challenges
- Understanding const correctness in CubeManager.
- Passing Cube pointers correctly to CubeSaver.
- Ensuring file format matches the assignment's example.

## What I Learned
- How to write structured output to a file using fstream.
- How to use `static_cast<int>` when accessing Face enums.
- How to design small helper classes like CubeSaver.

## Next Steps 
Future checkpoint features ( loading cubes, comparing cubes ect.).