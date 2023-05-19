#ifndef PROJECT_EQUATION_H
#define PROJECT_EQUATION_H

#include <vector>
#include <string>

//lisada classi malli tüüp
class Equation {
private:
    std::string m_equation;
    unsigned int m_numberOfVariables;
    std::vector<char> m_variables;
    std::vector<double> m_coefficients;
    double constant;

public:
    explicit Equation(std::string equation);

    void getCoefficientsFromString();
    void getVariableNamesFromString();

    [[nodiscard]] const std::string &getMEquation() const;
    [[nodiscard]] const std::vector<char>& getMVariables() const;
    [[nodiscard]] const std::vector<double> &getMCoefficients() const;
};

#endif //PROJECT_EQUATION_H