#ifndef PROJECT_SLESOLVER_H
#define PROJECT_SLESOLVER_H

#include <vector>

using namespace std;

class SLESolver {
private:
    vector<vector<double>> m_matrix;

public:
    explicit SLESolver(const vector<vector<double>> &mMatrix);
    void solveSLE();
};


#endif //PROJECT_SLESOLVER_H