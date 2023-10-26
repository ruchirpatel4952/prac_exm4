#ifndef SNARE_H
#define SNARE_H
#include "Spot.h"
#include "Influence.h"

class Snare : public Spot, public Influence {
private:
    bool operative = true;

public:
    Snare(int x, int y) : Spot(x, y, 'S') {}

    bool isOperative() const { return operative; }
    
    void implement(Spot& spot) override {
        spot.setCategory('S');
        operative = false;
    }
};

#endif 
