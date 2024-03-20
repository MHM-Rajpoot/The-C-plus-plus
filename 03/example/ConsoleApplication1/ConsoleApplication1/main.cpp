
#include "reg.h" // Include header file for Linear Regression model
#include "knn.h" // Include header file for KNN model
#include "utilities.h" // Include header file for utility functions
#include <iostream>

int main() {

    // Example usage of Linear Regression model
    try {
        // Initialize LinearRegression model with specific parameters
        LinearRegression model(0.01, 10000); // Learning rate = 0.01, iterations = 10000

        // Load data from CSV file for Linear Regression
        std::vector<std::vector<float>> X; // Input features
        std::vector<float> y; // Target variable
        utility::loadData("linear_regression_data.csv", X, y);

        // Perform gradient descent to train the model
        model.fit(X, y);

        // Print parameters of the trained model
        std::cout << "\n\tRegression \nModel parameters:\n";
        model.printParameters();

        // Compute and print training Mean Squared Error (MSE)
        float training_mse = utility::computeMSE(X, y, model);
        std::cout << "Training MSE: " << training_mse << std::endl;

        // Example prediction for custom input using Linear Regression model
        std::vector<float> input = { 6, 7, 7, 8, 1 }; // Example input (excluding target variable)
        float prediction = model.predict(input);
        std::cout << "Custom input prediction: " << prediction << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Handle any exceptions and print error message
        return 1; // Return error code
    }

    // Example usage of KNN model
    try {
        // Initialize KNN model with k=3
        KNN knn(3);

        // Load data from CSV file for KNN
        std::vector<std::vector<float>> X; // Input features
        std::vector<float> y; // Target variable
        utility::loadData("KNN.csv", X, y);

        // Fit the KNN model with the training data
        knn.fit(X, y);

        // Make prediction for a random input with KNN model
        std::vector<float> input = { 2.0871777745558413,3.7717905512136674 }; // Last Fourth 1 Output 
        float prediction = knn.predict(input);
        std::cout << "\n\tKNN \nPrediction for random input: " << prediction << std::endl;

        // Make prediction for another random input with KNN model
        input = { 2.240893199201458,-1.180632184122412 }; // First Fourth 0 Output 
        prediction = knn.predict(input);
        std::cout << "Prediction for random input: " << prediction << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Handle any exceptions and print error message
        return 1; // Return error code
    }

    return 0; // Return success
}
