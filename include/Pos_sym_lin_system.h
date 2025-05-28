#ifndef POS_SYM_LIN_SYSTEM_H
#define POS_SYM_LIN_SYSTEM_H

#include "Linear_system.h"

class Pos_sym_lin_system : public Linear_system {
public:
    // Constructor
    Pos_sym_lin_system(const Matrix& A, const Vector& b);

    // Override solve function to check for positive definite
    Vector solve() const override;

private:
    bool is_symmetric() const;
    bool is_positive_definite() const;
};

#endif
