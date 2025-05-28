#include "Data_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// Load CPU dataset from UCI file (machine.data)
// Extract only 6 predictive features: MYCT, MMIN, MMAX, CACH, CHMIN, CHMAX
// and target: PRP
bool load_cpu_dataset(const string& path, Matrix& X, Vector& y) {
    ifstream file(path);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << path << endl;
        return false;
    }

    vector<vector<double>> features;
    vector<double> targets;

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        vector<string> tokens;
        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() < 10) continue;

        vector<double> x_row(6);
        x_row[0] = stod(tokens[2]);  // MYCT
        x_row[1] = stod(tokens[3]);  // MMIN
        x_row[2] = stod(tokens[4]);  // MMAX
        x_row[3] = stod(tokens[5]);  // CACH
        x_row[4] = stod(tokens[6]);  // CHMIN
        x_row[5] = stod(tokens[7]);  // CHMAX
        features.push_back(x_row);

        double label = stod(tokens[8]); // PRP
        targets.push_back(label);
    }

    int n_samples = features.size();
    int n_features = 6;

    X = Matrix(n_samples, n_features);
    y = Vector(n_samples);

    for (int i = 0; i < n_samples; ++i) {
        for (int j = 0; j < n_features; ++j) {
            X(i + 1, j + 1) = features[i][j];
        }
        y[i] = targets[i];
    }

    return true;
}
