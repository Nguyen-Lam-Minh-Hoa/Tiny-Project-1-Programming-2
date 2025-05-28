#include "Vector.h"
#include <cassert>

using namespace std;

// Default constructor: creates an empty vector
Vector::Vector() : m_size(0), m_data(nullptr) {}

// Constructor: creates a vector with given size, all elements initialized to 0
Vector::Vector(int size) : m_size(size) {
    m_data = new double[m_size];
    for (int i = 0; i < m_size; ++i)
        m_data[i] = 0.0;
}

// Copy constructor: deep copy
Vector::Vector(const Vector& other) : m_size(other.m_size) {
    m_data = new double[m_size];
    for (int i = 0; i < m_size; ++i)
        m_data[i] = other.m_data[i];
}

// Destructor: release dynamic memory
Vector::~Vector() {
    delete[] m_data;
}

// Assignment operator: deep copy assignment
Vector& Vector::operator=(const Vector& other) {
    if (this == &other)
        return *this;

    delete[] m_data;

    m_size = other.m_size;
    m_data = new double[m_size];
    for (int i = 0; i < m_size; ++i)
        m_data[i] = other.m_data[i];

    return *this;
}

// Addition operator: element-wise addition
Vector Vector::operator+(const Vector& other) const {
    assert(m_size == other.m_size);
    Vector result(m_size);
    for (int i = 0; i < m_size; ++i)
        result.m_data[i] = m_data[i] + other.m_data[i];
    return result;
}

// Subtraction operator: element-wise subtraction
Vector Vector::operator-(const Vector& other) const {
    assert(m_size == other.m_size);
    Vector result(m_size);
    for (int i = 0; i < m_size; ++i)
        result.m_data[i] = m_data[i] - other.m_data[i];
    return result;
}

// Scalar multiplication
Vector Vector::operator*(double scalar) const {
    Vector result(m_size);
    for (int i = 0; i < m_size; ++i)
        result.m_data[i] = m_data[i] * scalar;
    return result;
}

// Non-const access by index (0-based)
double& Vector::operator[](int index) {
    assert(index >= 0 && index < m_size);
    return m_data[index];
}

// Const access by index (0-based) – for read-only operations
double Vector::operator[](int index) const {
    assert(index >= 0 && index < m_size);
    return m_data[index];
}

// 1-based read-only access (used in Matrix class)
double Vector::operator()(int index) const {
    assert(index >= 1 && index <= m_size);
    return m_data[index - 1];
}

// Get vector size
int Vector::size() const {
    return m_size;
}

// Print vector contents
void Vector::print() const {
    for (int i = 0; i < m_size; ++i)
        cout << m_data[i] << " ";
    cout << endl;
}
