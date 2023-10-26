#include "Play.h"
#include <iostream>

int main() {
    Play game;

    game.initPlay(3, 5, 10, 10);
    game.playCycle(15, 1.5);

    return 0;
}
