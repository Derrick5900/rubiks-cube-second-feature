#pragma once
#include <array>
#include <string>

// Forward declaration of Face enum.
// The full definition is in Cube.h
enum class Face : int {
    U = 0, // Up
    D = 1, // Down
    L = 2, // Left
    R = 3, // Right
    F = 4, // Front
    B = 5  // Back
};

// Side is a thin wrapper that points at one 3x3 face grid
class Side {
public:
    using Grid = std::array<std::array<char, 3>, 3>;

    Side() = default;

    // Attach this side to one of the Cube's 3x3 face grids
    void attach(Face f, Grid* grid);

    // Which face is this? (U, D, L, R, F, B)
    Face getFace() const;

    // Access underlying 3x3 grid
    Grid&       getGrid();
    const Grid& getGrid() const;

private:
    Face  face{Face::U};
    Grid* gridPtr{nullptr};
};