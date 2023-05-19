#include <stdexcept>
#include "systemOfEquations.h"

void SystemOfEquations::addEquation(Equation &equation) {
    auto& variables = equation.getMVariables();
    if (std::equal(variables.begin(), variables.end(), m_variables.begin(), m_variables.end())
        || m_variables.empty()) {
        if (m_variables.empty()) m_variables = variables; //teeb kopeerimist
        m_equations.push_back(equation.getMCoefficients());
    } else throw std::invalid_argument("Muutujad ei tohi samas võrrandisüsteemis olla erinevad");
}

const std::vector<char> &SystemOfEquations::getMVariables() const {
    return m_variables;
}

const std::vector<std::vector<double>> &SystemOfEquations::getMEquations() const {
    return m_equations;
}
