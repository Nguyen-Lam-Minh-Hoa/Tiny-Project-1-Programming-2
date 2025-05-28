#ifndef NON_SQUARE_SYSTEM_H
#define NON_SQUARE_SYSTEM_H

#include "Linear_system.h"

class Non_square_system : public Linear_system {
public:
    Non_square_system(const Matrix& A, const Vector& b);

    // Override solve function: use pseudo-inverse
    Vector solve() const override;
};

#endif
