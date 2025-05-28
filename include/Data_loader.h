#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include "Matrix.h"
#include "Vector.h"
#include <string>
#include <vector>

bool load_cpu_dataset(const std::string& path, Matrix& X, Vector& y);

#endif
