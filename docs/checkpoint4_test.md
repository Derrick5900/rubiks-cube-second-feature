# Checkpoint 4 Tests (Feature 4)

## Test 1: Load with no cubes
Steps:
1. Run program
2. Choose option 4

Expected:
- Program prints: "No cubes available."
- Program does not crash

## Test 2: Save then load restores cube
Steps:
1. Choose option 1 (create solved cube)
2. Choose option 2 (rotate a face) to change cube
3. Choose option 3 (save first cube to file)
4. Rotate again (option 2) so cube changes again
5. Choose option 4 (load first cube from file)
6. Display cube

Expected:
- Prints: "Cube loaded from 'cube_save.txt'."
- Cube matches the saved state (faces restored)

## Test 3: Load file message
Steps:
1. Run program with at least 1 cube created
2. Choose option 4

Expected:
- Prints confirmation message and returns to menu