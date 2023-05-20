#include "systemOfEquations.h"
#include <stdexcept>

void SystemOfEquations::addEquation(Equation &equation) {
    auto& variables = equation.getVariables();
    if (std::equal(variables.begin(), variables.end(), m_variables.begin(), m_variables.end())
        || m_variables.empty()) {
        if (m_variables.empty()) m_variables = variables; //teeb kopeerimist
        m_matrix.push_back(equation.getArguments());
    } else throw std::invalid_argument("Muutujate nimede komplekt (x, y, z, ...) peab olema igas võrrandis sama ja igal võrrandil peab olema sama muutujate jada!");
}

const std::vector<char> &SystemOfEquations::getVariables() const {
    return m_variables;
}

std::vector<std::vector<double>> &SystemOfEquations::getMatrix() {
    return m_matrix;
}
