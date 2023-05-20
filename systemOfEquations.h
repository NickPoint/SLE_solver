#ifndef PROJECT_SYSTEMOFEQUATIONS_H
#define PROJECT_SYSTEMOFEQUATIONS_H

#include "equation.h"
#include "vector"

class SystemOfEquations {
private:
    std::vector<std::vector<double>> m_matrix;
    std::vector<char> m_variables;
public:

    [[nodiscard]] std::vector<std::vector<double>> &getMatrix();
    [[nodiscard]] const std::vector<char> &getVariables() const;

    void addEquation(Equation &equation);
};

#endif //PROJECT_SYSTEMOFEQUATIONS_H
