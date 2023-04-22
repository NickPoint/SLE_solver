#ifndef PROJECT_SYSTEMOFEQUATIONS_H
#define PROJECT_SYSTEMOFEQUATIONS_H

#include "equation.h"
#include "vector"

class SystemOfEquations {
private:
    std::vector<Equation> m_equations;
    std::vector<char> m_variables;
public:

    [[nodiscard]] const std::vector<Equation> &getMEquations() const;
    [[nodiscard]] const std::vector<char> &getMVariables() const;

    void addEquation(Equation &equation);

//    template<typename... Args>
//    void process_args(const Equation& eq, Args... args) {
//        m_equations.push_back(eq);
//        process_args(args...);
//    }
//
//public:
//    template<typename... Args>
//    explicit SystemOfEquations(Args... args) {
//        process_args(args...);
//    }
};


#endif //PROJECT_SYSTEMOFEQUATIONS_H
