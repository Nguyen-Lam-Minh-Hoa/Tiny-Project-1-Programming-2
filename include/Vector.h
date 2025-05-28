#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

class Vector {
private:
    int m_size;
    double* m_data;

public:
    Vector(); // default constructor 
    Vector(int size);
    Vector(const Vector& other);
    ~Vector();

    Vector& operator=(const Vector& other);
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;

    double& operator[](int index);        // index from 0
    double operator[](int index) const;   // const version for read-only access, fix bug 1 21/05/2025
    double operator()(int index) const;   // 1-based indexing for reading (used in Matrix.cpp), fix bug 2 21/05/2025

    int size() const;

    void print() const;
};

#endif
