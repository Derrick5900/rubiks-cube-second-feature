# Checkpoint 2: Second Feature Plan

## Feature Name
Rotate Cube Face

## Feature 2: adds the ability for cube to:
- Rotate a face of a cube (simplified rotation)
- Update the cube's internal 3x3 face grids after a rotation
- Display the cube after the rotation to verify correctness
- Provide user interaction to choose which face to rotate.

At this stage, pointer-based `Side` objects are **not** used yet; the rotation works directly on the cube's `FaceGrid` arrays.

## Task to Complete
1. Add helper function `rotateFaceGridOnly(Face f, bool clockwise)` inside `Cube`.
2. Add `rotateFace(Face f, bool clockwise)` which calls the helper.
3. Implement rotation for the selected face using the pattern:
   - `(r,c) -> (c, 2 - r)` for clockwise
   - `(r,c) -> (2 - c, r) for counterclockwise
4. Add menu option in `CubeManager`:
   - Ask the user which face to rotate (U/D/L/R/F/B)
   - Ask for direction (clockwise or counter-clockwise)
5. After a rotation:
- display cube to visually confirm the rotation.

## Expected Output
After rotating a face:
Face O
WWW
WWW
WWW

Face 1
YYY
YYY
YYY

...updated faces after rotation...
