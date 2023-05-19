#include <iostream>
#include <sstream>
#include "equation.h"
#include "systemOfEquations.h"
#include "slesolver.h"

using namespace std;

int main() {
    cout << "Sisestage lineaarvõrrandid, eraldades need tähega ';':" << "\n";
    //3a - b + 14c = 7; 2a + 2b + 3c = 0; a - 12b - 18c = 33
    //2x + y = 15; 3x - y = 5
    string input;
    getline(cin, input, '\n');

    stringstream ss{input};
    string token;

    SystemOfEquations sle;

    while (getline(ss, token, ';')) {
        Equation equation(token);
        sle.addEquation(equation);
    }

    SLESolver solver(sle.getMEquations(), sle.getMConstants());
    solver.solveSLE();
//
//    cout << "Loodud lineaarvõrrandi süsteem" << "\n";
//    cout << "Võrrandid:" << "\n";
////    for (auto& el : sle.getMEquations()) {
////        cout << el.getMEquation() << '\n';
////    }
//
//    cout << "\n";
//    cout << "Muutujad:" << "\n";
//    for (auto& el : sle.getMVariables()) {
//        cout << el << '\n';
//    }
//
//    cout << "\n";
//    cout << "Koefitsiendid" << "\n";
//    for (auto& equation : sle.getMEquations()) {
//        for (auto& el : equation.getMCoefficients()) {
//            cout << el << " ";
//        }
//        cout << "\n";
//    }

//    string test1{"3a - b + 14c = 7"};
//    string test2{"2a + 2b + 3c = 0"};
//    string test3{"a - 12b - 18c = 33"};
//    Equation equation1(test1);
//    Equation equation2(test2);
//    Equation equation3(test3);
//    SystemOfEquations sle{equation1, equation2, equation3};

    // cout << equation.calculate_numberOfVariables() << endl;
//    for (int i = 0; i < equation.calculate_numberOfVariables(); ++i) {
//        cout << equation.getVariableNamesFromString().at(i) << endl;
//    }

    return 0;
}
