#ifndef PROJECT_SLESOLVER_H
#define PROJECT_SLESOLVER_H

#include <vector>

using namespace std;

class SLESolver {
    vector<vector<double>> m_matrix;
    vector<double> m_constants;

    void solveSLE();
};


#endif //PROJECT_SLESOLVER_H