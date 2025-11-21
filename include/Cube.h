#pragma once
#include <array>
#include <string>

enum class Face { U = 0, D = 1, L = 2, R = 3, F = 4, B = 5 };

class Cube {
public:
    using FaceGrid = std::array<std::array<char,3>,3>;

private:
    std::array<FaceGrid,6> faces;  // U,D,L,R,F,B
    std::string name;

public:
    // Constructors
    Cube();
    explicit Cube(const std::string& cubeName);

    // Accessors
    const std::string& getName() const;
    char getColor(Face f, int row, int col) const;

    // Mutators
    void setName(const std::string& newName);
    bool setColor(Face f, int row, int col, char color);

    // Display cube to console
    void display() const;

    // Second feature: rotate one face of the cube
    // face: Which face to rotate (U, D, R, F, B)
    // clockwise: true = clockwise, false = counterclockwise
    void rotateFace(Face face, bool clockwise);

private:
    static char defaultColor(Face f);
};

