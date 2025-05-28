cmake_minimum_required(VERSION 3.10)
project(TinyProject)

set(CMAKE_CXX_STANDARD 17)

# Include headers
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Main executable
add_executable(main main.cpp ${SOURCES})

# Build test_vector program (for testing Vector class)
add_executable(test_vector test/test_vector.cpp ${SOURCES})

# Build test_matrix program (for testing Matrix class)
add_executable(test_matrix test/test_matrix.cpp ${SOURCES})

# Build test_linear_system program (for testing linear_system) s4
add_executable(test_linear_system test/test_linear_system.cpp ${SOURCES})

# Build test_pos_sym_lin_system program (for testing pos_sym_lin_system) s5
add_executable(test_pos_sym_lin_system test/test_pos_sym_lin_system.cpp ${SOURCES})

# Build test_non_square_system program (for testing non_square_system) s6 24/05/2025
add_executable(test_non_square_system test/test_non_square_system.cpp ${SOURCES})

# Build test_regression_real_data program (for test_regression_real_data) s7 (Part B)
add_executable(test_regression_real_data test/test_regression_real_data.cpp src/Data_loader.cpp ${SOURCES}) # fix bug 5 Part B





