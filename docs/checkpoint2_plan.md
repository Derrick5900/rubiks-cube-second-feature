# Checkpoint 2: Second Feature Plan

## Feature Name
Rotate Cube Face

## Description
This feature lets the user rotate one face of the Rubik's Cube (example the front, back, left, right, up, or down face) and then displays the updated cube. The user chooses which face and the direction of the rotation.

## Why this feature?
Rotating faces is a key action in any Rubik's Cube game. This feature builds on my first feature, which creates a solved cube and displays all faces. Now, instead of only viewing a solved cube, the user can start changing the cube's state in a controlled way.

## Classes Involved
- `Cube` - stores the cube's faces and squares; will get new methods to rotate faces.
- `CubeManager` - manages the `Cube` object and connects the feature to the menu in `main.cpp`.
- Any helper structs or enums if needed to represent faces or directions.

## Expected User Workflow
1. User runs the program and sees the main menu.
2. User chooses menu option 2: Rotate a cube face.
3. Program ask which face to rotate(example: F, B, L, R, U,D).
4. Program ask for direction (clockwise or counterclockwise).
5. Program applies the rotation to the `Cube` object.
6. Program displays the cube again so the user can see the updated state.
7. The user returns to the menu and can rotate more faces or exit.

## Estimated Time
3-4 hours of focused work, including planning, implementation, testing, and documentation.