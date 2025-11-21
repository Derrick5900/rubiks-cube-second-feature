# Checkpoint 2: Test Cases

## Test 1: Normal rotation
- **Purpose:** Verify that rotating the front face clockwise updates the cube.
- **Setup:** Start program -> option 1 to create cube -> option 2 -> face `F`, direction `C`.
- **Expected Result:** `F` face characters move to new positions (rotated) and cube prints with no errors.

## Test 2: Invalid face
- **Purpose:** Handle invalid face input.
- **Setup:** Create cube with option 1, then option 2 -> face `X`, direction `C`.
- **Expected Result:** Error message about invalid face; cube is not changed and program continues.

## Test 3 Integration with feature 1
- **Purpose:** Ensure feature 2 works after feature 1.
- **Setup:** Option 1 (create/display cube), then option 2 -> face `R`, direction `A`.
- **Expected Result:** Program prints solved cube first, then rotated cube; no crash.