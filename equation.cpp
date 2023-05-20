#include "equation.h"
#include <algorithm>
#include <regex>

Equation::Equation(std::string equation) {
    equation.erase(std::remove_if(equation.begin(), equation.end(), [](char c) { return std::isspace(c); }), equation.end());
    m_equation = equation;
    getVariableNamesFromString();
    getArgumentsFromString();
    m_arguments.push_back(std::stod(m_equation.substr(m_equation.find('=') + 1, m_equation.size())));
}

void Equation::getArgumentsFromString() {
    std::regex pattern(R"((-?\s*)(\d+(.\d+)?)?[A-Za-z])");
    auto words_begin = std::sregex_iterator(m_equation.begin(), m_equation.end(), pattern);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator& i = words_begin; i != words_end; ++i) {
        if ((*i).str().find('-') != std::string::npos) {
            if ((*i).str().size() > 2) {
                m_arguments.push_back(std::stod((*i).str()));
            }
            else m_arguments.push_back(-1);
        }
        else {
            if ((*i).str().size() > 1) {
                m_arguments.push_back(std::stod((*i).str()));
            }
            else m_arguments.push_back(1);
        }
    }
}

void Equation::getVariableNamesFromString() {
    for (auto& variable : m_equation) {
        if (std::isalpha(variable)) m_variables.push_back(variable);
    }
}

const std::vector<char>& Equation::getVariables() const {
    return m_variables;
}

const std::vector<double> &Equation::getArguments() const {
    return m_arguments;
}
