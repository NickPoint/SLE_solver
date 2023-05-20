#include "equation.h"
#include "systemOfEquations.h"
#include "slesolver.h"
#include <iostream>
#include <sstream>

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

    SLESolver solver(sle);
    solver.solveSLE();

    return 0;
}
