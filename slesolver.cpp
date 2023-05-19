#include "slesolver.h"
#include <cmath>
#include <iostream>

void SLESolver::solveSLE() {
    std::vector<std::vector<double>> matrix = {{2, 1, 15}, {3, -1, 5}};
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        // Search for maximum in this column
        double maxEl = std::abs(matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(matrix[k][i]) > maxEl) {
                maxEl = std::abs(matrix[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < n + 1; k++) {
            std::swap(matrix[maxRow][k], matrix[i][k]);
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++) {
            double c = -matrix[k][i] / matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    matrix[k][j] = 0;
                } else {
                    matrix[k][j] += c * matrix[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    std::vector<double> solutions(n);
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = matrix[i][n] / matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            matrix[k][n] -= matrix[k][i] * solutions[i];
        }
    }

    // Print solutions
    std::cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "x[" << i << "] = " << solutions[i] << std::endl;
    }
}

double SLESolver::getSolution(int index) const {
    return matrix[index][m_constants.size()];
}

SLESolver::SLESolver(const vector<vector<double>> &mMatrix, const vector<double> &mConstants) : matrix(mMatrix),
                                                                                                m_constants(
                                                                                                        mConstants) {}
