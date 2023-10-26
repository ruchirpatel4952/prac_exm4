#ifndef PERSONA_H
#define PERSONA_H
#include "Spot.h"

class Persona : public Spot {
public:
    Persona(int x, int y) : Spot(x, y, 'P') {}

    void shift(int dx, int dy) {
        int x = std::get<0>(getLoc());
        int y = std::get<1>(getLoc());
        setLoc(x + dx, y + dy);
    }
};

#endif 
