# Tiny Project – C++ Implementation

**Course Project – Programming 2**  

Student name: Nguyen Lam Minh Hoa

Student ID: 10422030

Date: May 2025  



## Project Overview

This project implements a small C++ linear algebra library with support for:

- Vector and Matrix operations
- Solving linear systems (general, positive definite, non-square)
- Linear regression using the least squares method
- Testing using real-world CPU performance dataset (UCI)

The implementation is split into **8 development stages**, each with its own Git branch.



##  Project Structure

tiny_project_programming-2_10422030-main/

> include/ # Header files
> 
> src/ # Implementation (.cpp) files
> 
> test/ # Test files for each stage
> 
> data/ # Dataset (machine.data from UCI)
> 
> main.cpp # Quick demo (not used for grading)
> 
> CMakeLists.txt # Build configuration
> 
> README.md # Project description

## Testing & Demo

### All core functionalities are tested in files under `test/`:

| Stage | Feature                     | Test File                       |
|-------|-----------------------------|----------------------------------|
| 2     | Vector class                | `test_vector.cpp`               |
| 3     | Matrix class                | `test_matrix.cpp`               |
| 4     | Linear system (Ax = b)      | `test_linear_system.cpp`        |
| 5     | Positive definite system    | `test_pos_sym_lin_system.cpp`   |
| 6     | Non-square system           | `test_non_square_system.cpp`    |
| 7     | Linear Regression (UCI)     | `test_regression_real_data.cpp` |

**Note**: `main.cpp` is a quick demo only. Use test files in `test/` for full evaluation.



##  Build Instructions

###  Requirements:

- CMake
- g++ / clang++
- Linux or WSL (Windows Subsystem for Linux)

###  Build and Run:

```bash
# Navigate to project root
cd tiny_project_programming-2_10422030-main

# Create build directory
mkdir build
cd build

# Configure and build
cmake ..
make

▶ Run Tests:

./test_vector
./test_matrix
./test_linear_system
./test_pos_sym_lin_system
./test_non_square_system
./test_regression_real_data

    Important: Run test executables from the build/ directory
    Ensure the dataset file data/machine.data is present.

 Dataset – Linear Regression (Part B)

     Dataset: UCI CPU Performance Dataset

     File: data/machine.data

     Target: Predict PRP (published relative performance)

     Method: Least squares regression

     Evaluation: RMSE on test set (80% train / 20% test)

Sample result:

Fitted weight vector:
-0.0323 0.0161 0.0034 0.527  -1.768  2.037
RMSE on test set: 73.29

 **Cleanup (Final Review)**

1. All classes are well-separated by header/source files.
1. Tests for each stage are complete and passing.

 **Final Notes**

    This project follows the assignment specification exactly.

    All functionality was tested on Linux (Ubuntu) using CMake and g++.

    For any missing tests, refer to the test/ folder as primary source of correctness.

    Thanks for reviewing this submission!