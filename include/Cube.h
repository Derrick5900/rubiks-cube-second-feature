#pragma once
#include <array>
#include <string>
#include "Side.h"

// Cube represents a standard 3x3 Rubik's Cube
class Cube {
public:
    using FaceGrid = std::array<std::array<char, 3>, 3>;

    explicit Cube(const std::string& name = "Untitled");

    // ---- Feature 1: name + display ----
    std::string getName() const;
    void setName(const std::string& n);

    char getColor(Face f, int r, int c) const;
    bool setColor(Face f, int r, int c, char color);

    void display() const;

    // ----- side pointers (Feature 3) ------
    Side*         getSide(Face f);
    const Side*   getSide(Face f) const;

    // ----- rotation APIs (Feature 2) -------
    void rotateFace(Face f, bool clockwise);
    void rotateFaceClockwise(Face f) { rotateFace(f, true); }
    void rotateFaceCounter(Face f)   { rotateFace(f, false); }



private:
    std::string name;

    // Actual color data for each face
    std::array<FaceGrid, 6> faces{};

    // We store 6 Side objects
    std::array<Side, 6> sideStorage{};

    // And we keep pointers to them:
    std::array<Side*, 6> sides{};

    // helpers functions
    static bool inRange(int r, int c);
    static char defaultColor(Face f);

    void initFaces();
    void initSides();
    void rotateFaceGridOnly(Face f, bool clockwise);
};