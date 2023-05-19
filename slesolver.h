#ifndef PROJECT_SLESOLVER_H
#define PROJECT_SLESOLVER_H

#include <vector>
#include "systemOfEquations.h"

using namespace std;

class SLESolver {
private:
//    vector<vector<double>> m_matrix;
    SystemOfEquations sle;
public:
    explicit SLESolver(const SystemOfEquations &sle);
    void solveSLE();
};


#endif //PROJECT_SLESOLVER_H