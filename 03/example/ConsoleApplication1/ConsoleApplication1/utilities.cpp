
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "reg.h"

namespace utility {

    // Function to load data from a CSV file into X_out and y_out
    void loadData(const std::string& filename, std::vector<std::vector<float>>& X_out, std::vector<float>& y_out) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            throw std::runtime_error("Error opening file");
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::vector<float> row;
            std::string val;
            while (std::getline(iss, val, ',')) {
                row.push_back(std::stof(val)); // Use stof instead of stod for float values
            }
            X_out.push_back(row);
            y_out.push_back(row.back()); // Assuming the last column is the target variable
            X_out.back().pop_back(); // Remove the target variable from X
        }
        file.close();
    }

    // Function to compute Mean Squared Error (MSE) for the given data and linear regression model
    float computeMSE(std::vector<std::vector<float>>& X, std::vector<float>& y, LinearRegression& model) {
        float bias = model.getbias(); // Get bias from the model
        std::vector<float> theta = model.gettheata(); // Get theta (coefficients) from the model

        int m = X.size(); // Number of training examples
        float mse = 0;
        for (int i = 0; i < m; ++i) {
            float predicted = bias; // Initialize prediction with bias
            for (size_t j = 0; j < theta.size(); ++j) {
                predicted += theta[j] * X[i][j]; // Add contribution of each feature to the prediction
            }
            mse += (predicted - y[i]) * (predicted - y[i]); // Accumulate squared error
        }
        return mse / m; // Return mean squared error
    }

}
