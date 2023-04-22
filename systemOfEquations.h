#ifndef PROJECT_SYSTEMOFEQUATIONS_H
#define PROJECT_SYSTEMOFEQUATIONS_H

#include "equation.h"
#include "vector"

class SystemOfEquations {
private:
    std::vector<Equation> m_equations;
    std::vector<char> m_variables;
public:

    void addEquation(Equation &equation);

};


#endif //PROJECT_SYSTEMOFEQUATIONS_H
