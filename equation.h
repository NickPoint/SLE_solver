#ifndef PROJECT_EQUATION_H
#define PROJECT_EQUATION_H

#include <vector>
#include <string>

class Equation {
private:
    std::string m_equation;
    std::vector<char> m_variables;
    std::vector<double> m_arguments;

public:
    explicit Equation(std::string equation);

    void getArgumentsFromString();
    void getVariableNamesFromString();

    [[nodiscard]] const std::vector<char>& getVariables() const;
    [[nodiscard]] const std::vector<double>& getArguments() const;
};

#endif //PROJECT_EQUATION_H