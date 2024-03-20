
#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>
#include <string>
#include "reg.h"

namespace utility {
    // Function to load data from a file into vectors
    // Parameters:
    // - filename: The name of the file to load
    // - X_out: Vector of vectors to store feature values
    // - y_out: Vector to store target values
    void loadData(const std::string& filename, std::vector<std::vector<float>>& X_out, std::vector<float>& y_out);

    // Function to compute Mean Squared Error (MSE)
    // Parameters:
    // - X: Matrix of feature values
    // - y: Vector of target values
    // - model: Linear regression model used for prediction
    // Returns:
    // - The computed Mean Squared Error
    float computeMSE(std::vector<std::vector<float>>& X, std::vector<float>& y, LinearRegression& model);
}

#endif // UTILITIES_H
