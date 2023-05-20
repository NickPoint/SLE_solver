#include "slesolver.h"
#include <cmath>
#include <iostream>

void SLESolver::solveSLE() {
    auto m_matrix = &m_sle.getMatrix();
    int n = static_cast<int>(m_matrix->size());

    for (int i = 0; i < n; i++) {
        // Otsime maksimumi selles veerus
        double maxEl = std::abs((*m_matrix)[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (std::abs((*m_matrix)[k][i]) > maxEl) {
                maxEl = std::abs((*m_matrix)[k][i]);
                maxRow = k;
            }
        }

        // Vahetame maksimaalset rida praeguse reaga (veergude kaupa)
        for (int k = i; k < n + 1; k++) {
            std::swap(m_matrix->at(maxRow).at(k), m_matrix->at(maxRow).at(k));
        }

        // Teeme kõik sellest reast allpool olevaid ridu nulliks praeguses veerus
        for (int k = i + 1; k < n; k++) {
            double c = -(*m_matrix)[k][i] / (*m_matrix)[i][i];
            for (int j = i; j < n + 1; j++) {
                if (i == j) {
                    (*m_matrix)[k][j] = 0;
                } else {
                    (*m_matrix)[k][j] += c * (*m_matrix)[i][j];
                }
            }
        }
    }

    // Lahendame võrrandit Ax=b ülemkolmnurkse maatriksi jaoks
    std::vector<double> solutions(n);
    for (int i = n - 1; i >= 0; i--) {
        solutions[i] = (*m_matrix)[i][n] / (*m_matrix)[i][i];
        for (int k = i - 1; k >= 0; k--) {
            (*m_matrix)[k][n] -= (*m_matrix)[k][i] * solutions[i];
        }
    }

    // Tulemused
    std::cout << "\n";
    std::cout << "Lahendid:\n";
    for (int i = 0; i < n; i++) {
        std::cout << m_sle.getVariables()[i] <<  " = " << solutions[i] << "\n";
    }
}

SLESolver::SLESolver(SystemOfEquations &sle) : m_sle(sle) {}
