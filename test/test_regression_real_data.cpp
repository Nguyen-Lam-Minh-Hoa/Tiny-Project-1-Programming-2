#include <iostream>
#include "Data_loader.h"
#include "Linear_regression.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm> // fix bug 7 part B s7 (24/05/2025)

using namespace std;

int main() {
    cout << "Linear Regression on Real Dataset (Part B)" << endl;

    Matrix X;
    Vector y;

    if (!load_cpu_dataset("../data/machine.data", X, y)) {
        return 1;
    }

    int n = y.size();
    int train_size = int(n * 0.8);

    srand(time(0));

    // Shuffle indices
    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;

    random_shuffle(indices.begin(), indices.end());

    Matrix X_train(train_size, 6);
    Vector y_train(train_size);
    Matrix X_test(n - train_size, 6);
    Vector y_test(n - train_size);

    for (int i = 0; i < train_size; ++i) {
        int idx = indices[i];
        for (int j = 1; j <= 6; ++j)
            X_train(i + 1, j) = X(idx + 1, j);
        y_train[i] = y[idx];
    }

    for (int i = train_size; i < n; ++i) {
        int idx = indices[i];
        for (int j = 1; j <= 6; ++j)
            X_test(i - train_size + 1, j) = X(idx + 1, j);
        y_test[i - train_size] = y[idx];
    }

    Linear_regression lr(X_train, y_train);
    Vector w = lr.fit();

    cout << "Fitted weight vector:" << endl;
    w.print();

    // Predict and evaluate RMSE
    double mse = 0;
    for (int i = 0; i < y_test.size(); ++i) {
        Vector x_row(6);
        for (int j = 0; j < 6; ++j)
            x_row[j] = X_test(i + 1, j + 1);
        double pred = lr.predict(x_row, w);
        double error = pred - y_test[i];
        mse += error * error;
    }

    double rmse = sqrt(mse / y_test.size());
    cout << "RMSE on test set: " << rmse << endl;

    return 0;
}
