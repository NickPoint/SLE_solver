#ifndef PROJECT_SLESOLVER_H
#define PROJECT_SLESOLVER_H

#include <vector>

using namespace std;

class SLESolver {
private:
    vector<vector<double>> matrix;
    vector<double> m_constants;

public:
    SLESolver(const vector<vector<double>> &mMatrix, const vector<double> &mConstants);

    void solveSLE();
    double getSolution(int index) const;
};


#endif //PROJECT_SLESOLVER_H