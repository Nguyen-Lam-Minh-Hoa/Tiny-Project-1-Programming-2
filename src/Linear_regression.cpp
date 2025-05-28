#include "Linear_regression.h"
#include <iostream>
#include <cassert> //fix bug 6, s7 Part B (24/05/2025)

using namespace std;

// Constructor: store the feature matrix X and label vector y
Linear_regression::Linear_regression(const Matrix& X, const Vector& y)
    : m_X(X), m_y(y) {}

// Compute weight vector w = (X^T X)^-1 X^T y or use pseudo-inverse
Vector Linear_regression::fit() const {
    int rows = m_X.num_rows();
    int cols = m_X.num_cols();

    if (rows >= cols) {
        // Use normal equation if square (X^T X) is invertible
        Matrix Xt = m_X.transpose();
        Matrix XtX = Xt * m_X;

        // Use inverse if possible
        if (XtX.determinant() != 0) {
            Matrix XtX_inv = XtX.inverse();
            return XtX_inv * Xt * m_y;
        }
    }

    // Otherwise, use pseudo-inverse
    Matrix X_pinv = m_X.pseudo_inverse();
    return X_pinv * m_y;
}

// Predict a single output given input vector x and learned weights w
double Linear_regression::predict(const Vector& x, const Vector& w) const {
    assert(x.size() == w.size());

    double result = 0.0;
    for (int i = 0; i < x.size(); ++i)
        result += x[i] * w[i];

    return result;
}

// Print input data
void Linear_regression::print() const {
    cout << "Feature matrix X:" << endl;
    m_X.print();

    cout << "Label vector y:" << endl;
    m_y.print();
}
