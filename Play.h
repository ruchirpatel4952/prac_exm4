#ifndef PLAY_H
#define PLAY_H
#include "Spot.h"
#include "Persona.h"
#include "Snare.h"
#include "Assists.h"
#include <vector>
#include <iostream>

class Play {
private:
    std::vector<Spot*> matrix;

public:
    Play() {}

    std::vector<Spot*>& getMatrix() { return matrix; }

    void initPlay(int numPersonas, int numSnares, int matrixWidth, int matrixHeight) {
        matrix.clear();

        for (int i = 0; i < numPersonas; i++) {
            std::tuple<int, int> loc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            matrix.push_back(new Persona(std::get<0>(loc), std::get<1>(loc)));
        }

        for (int i = 0; i < numSnares; i++) {
            std::tuple<int, int> loc = Assists::createRandomLoc(matrixWidth, matrixHeight);
            matrix.push_back(new Snare(std::get<0>(loc), std::get<1>(loc)));
        }
    }

    void playCycle(int maxCycles, double snareTriggerDistance) {
        for (int i = 0; i < maxCycles; i++) {
            // Shift all Persona objects
            for (auto& spot : matrix) {
                Persona* persona = dynamic_cast<Persona*>(spot);
                if (persona) {
                    persona->shift(1, 0);
                    // Check if Persona stepped outside of the matrix
                    if (std::get<0>(persona->getLoc()) >= static_cast<int>(matrix.size())) {
                        std::cout << "Persona has won the game!" << std::endl;
                        return;
                    }
                }
            }

            // Check for snares near each Persona
            for (auto& spot1 : matrix) {
                Persona* persona = dynamic_cast<Persona*>(spot1);
                if (persona) {
                    for (auto& spot2 : matrix) {
                        Snare* snare = dynamic_cast<Snare*>(spot2);
                        if (snare && snare->isOperative()) {
                            if (Assists::evaluateDistance(persona->getLoc(), snare->getLoc()) <= snareTriggerDistance) {
                                snare->implement(*persona);
                            }
                        }
                    }
                }
            }
        }

        std::cout << "Maximum number of cycles reached. Game over." << std::endl;
    }
};

#endif // PLAY_H
