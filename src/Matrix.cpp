#include "Matrix.h"
#include <cassert>

using namespace std;

// Constructor: creates a rows x cols matrix with all elements = 0
Matrix::Matrix(int rows, int cols) : m_num_rows(rows), m_num_cols(cols) {
    m_data = new double*[m_num_rows];
    for (int i = 0; i < m_num_rows; ++i) {
        m_data[i] = new double[m_num_cols];
        for (int j = 0; j < m_num_cols; ++j)
            m_data[i][j] = 0.0;
    }
}

// Copy constructor: copies contents from another matrix
Matrix::Matrix(const Matrix& other) : m_num_rows(other.m_num_rows), m_num_cols(other.m_num_cols) {
    m_data = new double*[m_num_rows];
    for (int i = 0; i < m_num_rows; ++i) {
        m_data[i] = new double[m_num_cols];
        for (int j = 0; j < m_num_cols; ++j)
            m_data[i][j] = other.m_data[i][j];
    }
}

// Destructor: frees memory
Matrix::~Matrix() {
    for (int i = 0; i < m_num_rows; ++i)
        delete[] m_data[i];
    delete[] m_data;
}

// Getter row and column numbers
int Matrix::num_rows() const { return m_num_rows; }
int Matrix::num_cols() const { return m_num_cols; }

// Access element (i, j), index from 1
double& Matrix::operator()(int i, int j) {
    assert(i >= 1 && i <= m_num_rows && j >= 1 && j <= m_num_cols);
    return m_data[i - 1][j - 1];
}

double Matrix::operator()(int i, int j) const {
    assert(i >= 1 && i <= m_num_rows && j >= 1 && j <= m_num_cols);
    return m_data[i - 1][j - 1];
}

// Assignment Operator
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    // Delete old data
    for (int i = 0; i < m_num_rows; ++i)
        delete[] m_data[i];
    delete[] m_data;

    // Allocate and copy new data
    m_num_rows = other.m_num_rows;
    m_num_cols = other.m_num_cols;
    m_data = new double*[m_num_rows];
    for (int i = 0; i < m_num_rows; ++i) {
        m_data[i] = new double[m_num_cols];
        for (int j = 0; j < m_num_cols; ++j)
            m_data[i][j] = other.m_data[i][j];
    }

    return *this;
}

// Add 2 matrices
Matrix Matrix::operator+(const Matrix& other) const {
    assert(m_num_rows == other.m_num_rows && m_num_cols == other.m_num_cols);
    Matrix result(m_num_rows, m_num_cols);
    for (int i = 0; i < m_num_rows; ++i)
        for (int j = 0; j < m_num_cols; ++j)
            result.m_data[i][j] = m_data[i][j] + other.m_data[i][j];
    return result;
}

// Subtract 2 matrices
Matrix Matrix::operator-(const Matrix& other) const {
    assert(m_num_rows == other.m_num_rows && m_num_cols == other.m_num_cols);
    Matrix result(m_num_rows, m_num_cols);
    for (int i = 0; i < m_num_rows; ++i)
        for (int j = 0; j < m_num_cols; ++j)
            result.m_data[i][j] = m_data[i][j] - other.m_data[i][j];
    return result;
}

// Multiply matrix by real number
Matrix Matrix::operator*(double scalar) const {
    Matrix result(m_num_rows, m_num_cols);
    for (int i = 0; i < m_num_rows; ++i)
        for (int j = 0; j < m_num_cols; ++j)
            result.m_data[i][j] = m_data[i][j] * scalar;
    return result;
}

// Matrix with other Matrix 21/05/2025 (s3)
// Matrix multiplication: result = this * other
// Precondition: number of columns of this == number of rows of other
Matrix Matrix::operator*(const Matrix& other) const {
    // Ensure dimensions are compatible for multiplication
    assert(m_num_cols == other.m_num_rows);

    // Resulting matrix has dimension (this.rows x other.cols)
    Matrix result(m_num_rows, other.m_num_cols);

    // Perform standard matrix multiplication
    for (int i = 0; i < m_num_rows; ++i) {
        for (int j = 0; j < other.m_num_cols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < m_num_cols; ++k) {
                sum += m_data[i][k] * other.m_data[k][j];
            }
            result(i + 1, j + 1) = sum; // use 1-based indexing
        }
    }

    return result;
}

//Matrix with Vector 21/05/2025 (s3)
// Matrix-vector multiplication: result = this * vec
// Precondition: number of columns of this == size of vector
Vector Matrix::operator*(const Vector& vec) const {
    // Ensure the vector size matches the number of columns
    assert(m_num_cols == vec.size());

    // Resulting vector will have the same number of rows as the matrix
    Vector result(m_num_rows);

    // Perform matrix-vector multiplication
    for (int i = 0; i < m_num_rows; ++i) {
        double sum = 0.0;
        for (int j = 0; j < m_num_cols; ++j) {
            sum += m_data[i][j] * vec[j]; // use 0-based vector indexing
        }
        result[i] = sum;
    }

    return result;
}

//determinant 21/05/2025 (s3)
// Helper function to create a submatrix by removing row 'row_to_remove' and column 'col_to_remove'
Matrix get_submatrix(const Matrix& mat, int row_to_remove, int col_to_remove) {
    int n = mat.num_rows();
    Matrix submat(n - 1, n - 1);

    int r = 1; // row index for submatrix
    for (int i = 1; i <= n; ++i) {
        if (i == row_to_remove) continue;

        int c = 1; // column index for submatrix
        for (int j = 1; j <= n; ++j) {
            if (j == col_to_remove) continue;

            submat(r, c) = mat(i, j);
            c++;
        }
        r++;
    }

    return submat;
}

//calculate determinant 21/05/2025 (s3)
// Calculate the determinant of a square matrix using recursion (Laplace expansion)
double Matrix::determinant() const {
    // Only square matrices have determinants
    assert(m_num_rows == m_num_cols);

    int n = m_num_rows;

    // Base case: 1x1 matrix
    if (n == 1) {
        return m_data[0][0];
    }

    // Base case: 2x2 matrix
    if (n == 2) {
        return m_data[0][0] * m_data[1][1] - m_data[0][1] * m_data[1][0];
    }

    // Recursive case: use Laplace expansion along the first row
    double det = 0.0;

    for (int j = 1; j <= n; ++j) {
        // Sign alternates: + - + - ...
        double sign = ((j % 2 == 0) ? -1.0 : 1.0);

        // Get submatrix excluding row 1 and column j
        Matrix submat = get_submatrix(*this, 1, j);

        // Add current term to determinant
        det += sign * (*this)(1, j) * submat.determinant();
    }

    return det;
}

//inverse matrix 21/05/2025 (s3)
// Compute the inverse of a square matrix using Gauss-Jordan elimination
Matrix Matrix::inverse() const {
    // Ensure the matrix is square
    assert(m_num_rows == m_num_cols);
    int n = m_num_rows;

    // Step 1: Create augmented matrix [A | I]
    Matrix aug(n, 2 * n);

    // Fill in [A | I]
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            aug(i, j) = (*this)(i, j); // Left part = A
        }
        for (int j = n + 1; j <= 2 * n; ++j) {
            aug(i, j) = (i == (j - n)) ? 1.0 : 0.0; // Right part = I
        }
    }

    // Step 2: Apply Gauss-Jordan elimination
    for (int i = 1; i <= n; ++i) {
        // Find pivot
        double pivot = aug(i, i);
        assert(pivot != 0); // Matrix is not invertible if pivot is 0

        // Normalize the pivot row
        for (int j = 1; j <= 2 * n; ++j) {
            aug(i, j) /= pivot;
        }

        // Eliminate other rows
        for (int k = 1; k <= n; ++k) {
            if (k == i) continue;
            double factor = aug(k, i);
            for (int j = 1; j <= 2 * n; ++j) {
                aug(k, j) -= factor * aug(i, j);
            }
        }
    }

    // Step 3: Extract the right half → inverse matrix
    Matrix inv(n, n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            inv(i, j) = aug(i, j + n);

    return inv;
}

// inverse matrix using Moore-Penrose (final-s3) 21/05/2025
// Compute Moore–Penrose pseudo-inverse of the matrix
Matrix Matrix::pseudo_inverse() const {
    int m = m_num_rows;
    int n = m_num_cols;

    //step 1: Compute A^T (transpose of current matrix)
    Matrix A_T(n, m);
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            A_T(j, i) = (*this)(i, j);

    // fix bug 1 21/05/2025
    Matrix result(n, m);  // default: (n x m) for m >= n

    if (m >= n) {
        // case:more rows than columns → use formula (A^T A)^-1 A^T

        Matrix AtA = A_T * (*this);
        Matrix AtA_inv = AtA.inverse();
        result = AtA_inv * A_T;

    } 
    else {
        // Case: more columns than rows → use formula A^T (A A^T)^-1

        Matrix AAt = (*this) * A_T;
        Matrix AAt_inv = AAt.inverse();
        result = A_T * AAt_inv;
    }

    return result;
}

// Return the transpose of the matrix to fix bug 6 s7 Part B (24/05/2025)
Matrix Matrix::transpose() const {
    Matrix result(m_num_cols, m_num_rows);
    for (int i = 1; i <= m_num_rows; ++i) {
        for (int j = 1; j <= m_num_cols; ++j) {
            result(j, i) = m_data[i - 1][j - 1];
        }
    }
    return result;
}

//fix bug 7, part B s7 (24/05/2025)
Matrix::Matrix() : m_num_rows(0), m_num_cols(0) {} 

// Print matrix to console
void Matrix::print() const {
    for (int i = 0; i < m_num_rows; ++i) {
        for (int j = 0; j < m_num_cols; ++j)
            cout << m_data[i][j] << " ";
        cout << endl;
    }
}

