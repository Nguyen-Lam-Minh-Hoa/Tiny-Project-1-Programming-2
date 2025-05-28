#include <iostream>
#include "Non_square_system.h"

using namespace std;

int main() {
    cout << "Test: Non-Square Linear System." << endl;

    // CASE 1: Overdetermined system (more equations than variables)
    Matrix A1(3, 2);
    A1(1,1) = 1; A1(1,2) = 1;
    A1(2,1) = 2; A1(2,2) = 1;
    A1(3,1) = 3; A1(3,2) = 1;

    Vector b1(3);
    b1[0] = 4;
    b1[1] = 7;
    b1[2] = 10;

    Non_square_system sys1(A1, b1);
    sys1.print();

    Vector x1 = sys1.solve();
    cout << "Approximate solution x (overdetermined):" << endl;
    x1.print();

    // CASE 2: Underdetermined system (more variables than equations)
    Matrix A2(2, 3);
    A2(1,1) = 1; A2(1,2) = 2; A2(1,3) = 3;
    A2(2,1) = 0; A2(2,2) = 1; A2(2,3) = 4;

    Vector b2(2);
    b2[0] = 6;
    b2[1] = 5;

    Non_square_system sys2(A2, b2);
    sys2.print();

    Vector x2 = sys2.solve();
    cout << "One possible solution x (underdetermined):" << endl;
    x2.print();

    return 0;
}
