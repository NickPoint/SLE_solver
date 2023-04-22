#include <stdexcept>
#include "systemOfEquations.h"

void SystemOfEquations::addEquation(Equation &equation) {
    auto &variables = equation.getMVariables();
    if (std::equal(variables.begin(), variables.end(), m_variables.begin(), m_variables.end()))
        m_equations.push_back(equation);
    else throw std::invalid_argument("Muutujad ei tohi samas võrrandisüsteemis olla erinevad");
}