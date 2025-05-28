#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
    cout << "Test Vector." << endl;

    Vector v1(3);
    v1[0] = 1;
    v1[1] = 2;
    v1[2] = 3;

    Vector v2(3);
    v2[0] = 4;
    v2[1] = 5;
    v2[2] = 6;

    Vector sum = v1 + v2;
    cout << "v1 + v2 = ";
    sum.print();

    Vector diff = v2 - v1;
    cout << "v2 - v1 = ";
    diff.print();

    Vector scaled = v1 * 2.0;
    cout << "v1 * 2 = ";
    scaled.print();

    cout << "v1(2) = " << v1(2) << endl;

    return 0;
}
