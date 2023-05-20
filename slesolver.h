#ifndef PROJECT_SLESOLVER_H
#define PROJECT_SLESOLVER_H

#include "systemOfEquations.h"
#include <vector>

class SLESolver {
private:
    SystemOfEquations m_sle;
public:
    explicit SLESolver(SystemOfEquations &sle);
    void solveSLE();
};

#endif //PROJECT_SLESOLVER_H