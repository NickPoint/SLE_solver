#include <iostream>
#include "equation.h"
#include "systemOfEquations.h"

using namespace std;

int main() {
    string test1{"3x + 4y - z = 5"};
    Equation equation(test1);

    // cout << equation.calculate_numberOfVariables() << endl;
//    for (int i = 0; i < equation.calculate_numberOfVariables(); ++i) {
//        cout << equation.getVariableNamesFromString().at(i) << endl;
//    }

    return 0;
}
