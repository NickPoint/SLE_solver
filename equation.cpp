#include "equation.h"
#include <algorithm>
#include <regex>

Equation::Equation(std::string equation) {
    equation.erase(std::remove_if(equation.begin(), equation.end(), [](char c) { return std::isspace(c); }), equation.end());
    m_equation = equation;
    getVariableNamesFromString();
    m_numberOfVariables = static_cast<unsigned int>(m_variables.size());
    getCoefficientsFromString();
    constant = std::stod(m_equation.substr(m_equation.find('=') + 1, m_equation.size()));
}

void Equation::getCoefficientsFromString() {
    std::regex pattern("(\\d+(.\\d+)?)?[A-Za-z]");
    auto words_begin = std::sregex_iterator(m_equation.begin(), m_equation.end(), pattern);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator& i = words_begin; i != words_end; ++i) {
        if ((*i).str().size() > 1) m_coefficients.push_back(std::stod((*i).str()));
        else m_coefficients.push_back(1);
    }
}

void Equation::getVariableNamesFromString() {
    for (auto& variable : m_equation) {
        if (std::isalpha(variable)) m_variables.push_back(variable);
    }
}

const std::vector<char>& Equation::getMVariables() const {
    return m_variables;
}

const std::string &Equation::getMEquation() const {
    return m_equation;
}

const std::vector<double> &Equation::getMCoefficients() const {
    return m_coefficients;
}
