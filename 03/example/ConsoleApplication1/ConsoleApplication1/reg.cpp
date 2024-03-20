
#include "reg.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

// Constructor for LinearRegression class
LinearRegression::LinearRegression(float alpha, int numIterations)
    : learningRate(alpha), iterations(numIterations), bias(0) {}

// Fit function to train the linear regression model
void LinearRegression::fit(std::vector<std::vector<float>> X, std::vector<float> y) {
    int m = X.size(); // Number of training examples
    int n = X[0].size(); // Number of features
    theta = std::vector<float>(n, 0); // Initialize parameters to zeros

    // Iterating through the specified number of iterations
    for (int iter = 0; iter < iterations; ++iter) {
        std::vector<float> theta_updated(n, 0); // Temporary storage for updated parameters
        float bias_updated = 0; // Temporary storage for updated bias

        // Update parameters simultaneously
        for (int j = 0; j < n; ++j) {
            float gradient = 0; // Gradient for parameter theta[j]
            for (int i = 0; i < m; ++i) {
                float predicted = bias; // Update prediction with bias
                for (int k = 0; k < n; ++k) {
                    predicted += theta[k] * X[i][k]; // Predicted value for training example i
                }
                gradient += (predicted - y[i]) * X[i][j]; // Accumulate gradient
            }
            theta_updated[j] = theta[j] - (learningRate * gradient) / m; // Update parameter theta[j]
        }

        // Update bias (y-intercept)
        float gradient_bias = 0; // Gradient for bias
        for (int i = 0; i < m; ++i) {
            float predicted = bias; // Update prediction with bias
            for (int k = 0; k < n; ++k) {
                predicted += theta[k] * X[i][k]; // Predicted value for training example i
            }
            gradient_bias += (predicted - y[i]); // Accumulate gradient for bias
        }
        bias_updated = bias - (learningRate * gradient_bias) / m; // Update bias

        // Update parameters and bias for the next iteration
        theta = theta_updated;
        bias = bias_updated;
    }
}

// Function to predict output for input data
float LinearRegression::predict(const std::vector<float>& input) const {
    if (input.size() != theta.size()) {
        throw std::invalid_argument("Input size does not match the number of features");
    }
    float predicted = bias; // Initialize prediction with bias
    for (size_t i = 0; i < input.size(); ++i) {
        predicted += theta[i] * input[i]; // Add contribution of each feature to the prediction
    }
    return predicted;
}

// Function to print the learned parameters (coefficients and intercept)
void LinearRegression::printParameters() const {
    std::cout << "Coefficients: ";
    for (float param : theta) {
        std::cout << param << " "; // Print each coefficient
    }
    std::cout << "\nIntercept: " << bias << std::endl; // Print intercept
}
