#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "Matrix.h"
#include "Vector.h"

class Linear_regression {
private:
    Matrix m_X;  // Feature matrix
    Vector m_y;  // Target vector

public:
    // Constructor
    Linear_regression(const Matrix& X, const Vector& y);

    // Compute and return the weight vector
    Vector fit() const;

    // Predict value for new input vector x
    double predict(const Vector& x, const Vector& w) const;

    // Print the regression problem
    void print() const;
};

#endif
