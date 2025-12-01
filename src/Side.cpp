#include "Side.h"

void Side::attach(Face f, Grid* grid) {
    face    = f;
    gridPtr = grid;
}

Face Side::getFace() const {
    return face;
}

Side::Grid& Side::getGrid() {
    return *gridPtr;
}

const Side::Grid& Side::getGrid() const {
    return *gridPtr;
}
