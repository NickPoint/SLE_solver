#include "equation.h"
#include "systemOfEquations.h"
#include "slesolver.h"
#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

int main() {
    // Testitud süsteemid:
    // 5x + 2y = 1; −3x + 3y = 5;
    // 3a - b + 14c = 7; 2a + 2b + 3c = 0; a - 12b - 18c = 33;
    // -9x - 2y + 9z + 7w = -128; 3x + 7y + 4z + w = -21; -8x + 6y - 2z + 8w = -106; -5x - 4y + 4z + 9w = -84;
    // -3x + 9y = -3; 5x - 6y = 14;
    // 3x - 2y - 6z = -13; -10x - 2y + 8z = 106; 2x + 5y - 8z = -7;

    cout << "Lineaarvõrrandisüsteemi lahendaja" << "\n";
    cout << "\n";
    cout << "Eeldused:" << "\n";
    cout << "1) Lineaarvõrrandeid tuleb sisestada järgmisel kujul:" << "\n";
    cout << "'3x - 2y - 6z = -13; -10x - 2y + 8z = 106; 2x + 5y - 8z = -7;'" << "\n";
    cout << "2) Muutujate arv igas võrrandis peab olema võrdne võrrandite arvuga süsteemis" << "\n";
    cout << "Ainult sellel korral tekkib ruutsüsteem mida oskab meie programm lahendada" << "\n";
    cout << "Vabad muutujad ei loe sellel korral ehk võrrandil '5x + 2y + 3z = 1;' on 3 (x, y, z) muutujaid" << "\n";
    cout << "3) Igas võrrandis muutujate nimede komplekt peab olema sama" << "\n";
    cout << "See tähendab, et süsteem '5x + 2y = 1; -3x + 3y = 5;' on õigel kujul," << "\n";
    cout << "aga süsteem '5x + 2y = 1; -3x + 3z = 5;' on valel kujul" << "\n";
    cout << "4) Igal võrrandil peab olema sama muutujate jada" << "\n";
    cout << "See tähendab, et süsteem '5x + 2y = 1; -3y + 3x = 5;' on valel kujul," << "\n";
    cout << "kuna esimeses võrrandis jada on x,y, aga teises on y,x" << "\n";
    cout << "5) Kõik võrrandid peavad olema lihtsustatud kujul 'muutuja, muutuja, ... = vaba muutuja'" << "\n";
    cout << "See tähendab, et võrrand '5x + 3x - 2y = 8;' on valel kujul," << "\n";
    cout << "aga võrrand '8x - 2y = 8;' on õigel kujul" << "\n";
    cout << "\n";
    cout << "Sisestage lineaarvõrrandid, eraldades need sümboliga ';'" << "\n";
    cout << "ning ära unusta inputi lõpus samamoodi panna sümboli ';' :" << "\n";

    string input;
    getline(cin, input, '\n');
    // Kontrollime, kas input on tühi
    if (input.empty()) {
        throw std::runtime_error("Input on tühi!");
    }
    // Kontrollime, kas input on sobival kujul
    std::regex systemRegex(R"(^(((\s*[+-]\s*)?(\d+(.\d+)?)?[A-Za-z])+\s*=\s*-?\d+;\s*)+$)");
    if (!std::regex_match(input, systemRegex)) {
        throw std::runtime_error("Input on valel kujul!");
    }

    stringstream ss{input};
    string token;

    SystemOfEquations sle;
    while (getline(ss, token, ';')) {
        Equation equation(token);
        sle.addEquation(equation);
    }

    // Kontrollime, kas muutujate arv igas võrrandis on võrdne võrrandite arvuga süsteemis
    vector<vector<double>> maatriks = sle.getMatrix();
    int ridadeArv = maatriks.size();
    for (vector<double> vorrand: maatriks) {
        if (vorrand.size() - 1 != ridadeArv) {
            throw std::runtime_error("Muutujate arv igas võrrandis peab olema võrdne võrrandite arvuga süsteemis!");
        }
    }

    SLESolver solver(sle);
    solver.solveSLE();

    return 0;
}
