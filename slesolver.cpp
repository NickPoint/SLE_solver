#include "slesolver.h"
#include <cmath>
#include <iostream>

void SLESolver::solveSLE() {
    auto m_matrix = sle.getMEquations();
    int n = m_matrix.size();

    for (int i = 0; i < n; i++) {
        // Search for maximum in this column
        double maxEl = std::abs(m_matrix[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs(m_matrix[k][i]) > maxEl) {
                maxEl = std::abs(m_matrix[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k = i; k < n + 1; k++) {
            std::swap(m_matrix[maxRow][k], m_matrix[i][k]);
        }

        // Make all rows below this one 0 in current column
        for (int k = i + 1; k < n; k++) {
            double c = -m_matrix[k][i] / m_matrix[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    m_matrix[k][j] = 0;
                } else {
                    m_matrix[k][j] += c * m_matrix[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular m_matrix A
    std::vector<double> solutions(n);
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = m_matrix[i][n] / m_matrix[i][i];
        for (int k = i - 1; k >= 0; k--) {
            m_matrix[k][n] -= m_matrix[k][i] * solutions[i];
        }
    }

    // Print solutions
    std::cout << "Solution:\n";
    for (int i = 0; i < n; i++) {
        std::cout << sle.getMVariables().at(i) << ": " << solutions[i] << std::endl;
    }
}

SLESolver::SLESolver(const SystemOfEquations &sle) : sle(sle) {}

