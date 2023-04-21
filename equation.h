//
// Created by nikit on 18.04.2023.
//

#ifndef PROJECT_EQUATION_H
#define PROJECT_EQUATION_H

#include <vector>
#include <iostream>
#include <regex>
#include <string>
#include <set>

using namespace std;

class Equation {
private:
    string m_equation;
    unsigned int m_numberOfVariables;
    vector<char> m_variablesNames; //TODO: add some vector for numbers without variables
    vector<double> m_coefficients;
    double constant;

public:
    explicit Equation(string mEquation);
//    void calculate_numberOfVariables();
    void getCoefficients();
    void getVariableNames();
};

Equation::Equation(string mEquation) {
    mEquation.erase(remove_if(mEquation.begin(), mEquation.end(), [](char c) {return isspace(c);}),mEquation.end());
    m_equation = mEquation;
    getVariableNames();
    m_numberOfVariables = static_cast<unsigned int>(m_variablesNames.size());
    getCoefficients();
    constant = stod(m_equation.substr(m_equation.find('=') + 1, m_equation.size()));
}

//void Equation::calculate_numberOfVariables() {

//    regex re("[a-zA-Z]");
//    sregex_iterator it(m_equation.begin(), m_equation.end(), re);
//    sregex_iterator end;
//
//    set<string> variables;  // Set to store variables that have already been encountered
//    while (it != end) {
//        string variable = it->str();  // Extract the variable
//        if (variables.find(variable) == variables.end()) {
//            variables.insert(variable);  // Add the variable to the set
//        }
//        ++it;
//    }
//    return variables.size();
//}

void Equation::getCoefficients() {
    stringstream ss(m_equation);
    string term;
    while (getline(ss, term, '+') || getline(ss, term, '-')) {
        m_coefficients.push_back(stod(term.substr(0,term.size()-1)));
    }
}

void Equation::getVariableNames() {
    for (auto& variable : m_equation) {
        if (isalpha(variable)) //Checks if the given character is an alphabetic character as classified by the currently installed C locale
            m_variablesNames.push_back(variable);
    }
//    regex re("[a-zA-Z]");
//    sregex_iterator it(m_equation.begin(), m_equation.end(), re);
//    sregex_iterator end;
//
//    set<string> variables;  // Set to store variables that have already been encountered
//    while (it != end) {
//        string variable = it->str();  // Extract the variable
//        if (variables.find(variable) == variables.end()) {
//            variables.insert(variable);  // Add the variable to the set
//        }
//        ++it;
//    }
//    vector<char> variables_v;
//    for (string element : variables) {
//        char el = element[0];
//        variables_v.push_back(el);
//    }
//    return variables_v;
}


#endif //PROJECT_EQUATION_H
