#include "Snare.h"
#include "Persona.h"
#include <iostream>

int main() {
    Snare snare(3, 3);
    Persona persona(2, 2);

    std::cout << "Persona Location: (" << std::get<0>(persona.getLoc()) << ", " << std::get<1>(persona.getLoc()) << ")" << std::endl;

    persona.shift(1, 1);
    std::cout << "Persona after shifting: (" << std::get<0>(persona.getLoc()) << ", " << std::get<1>(persona.getLoc()) << ")" << std::endl;

    snare.implement(persona);
    std::cout << "Persona's category after snare implementation: " << persona.getCategory() << std::endl;
    std::cout << "Is snare operative? " << (snare.isOperative() ? "Yes" : "No") << std::endl;

    return 0;
}
