//
// Created by nikit on 18.04.2023.
//

#ifndef PROJECT_SYSTEMOFEQUATIONS_H
#define PROJECT_SYSTEMOFEQUATIONS_H

class SystemOfEquations {
private:
    vector<Equation> m_equations;
public:

    void addEquation(Equation &equation);

};

void SystemOfEquations::addEquation(Equation &equation) {
    m_equations.push_back(equation);
}


#endif //PROJECT_SYSTEMOFEQUATIONS_H
