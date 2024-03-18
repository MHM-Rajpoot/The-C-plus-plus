
#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "model.h"
#include <vector>
#include <string>

class LinearRegression : public Model {
private:
    std::vector<float> theta; // Parameters vector
    float learningRate;       // Learning rate for gradient descent
    int iterations;           // Number of iterations for gradient descent
    float bias;               // Bias term (intercept) for the linear regression model

public:
    // Constructor to initialize Linear Regression model with learning rate and number of iterations
    LinearRegression(float alpha, int numIterations);

    // Getter function to retrieve the bias term of the model
    float getbias() const { return bias; }

    // Getter function to retrieve the parameters (theta) vector of the model
    std::vector<float> gettheata() const { return theta; };

    // Overriding the pure virtual function for fitting the model with training data
    // Parameters:
    // - X: Matrix of feature values
    // - y: Vector of target values
    void fit(std::vector<std::vector<float>> X, std::vector<float> y) override;

    // Overriding the pure virtual function for making predictions on new data
    // Parameters:
    // - X: Vector of feature values for a single data point
    // Returns:
    // - The predicted target value
    float predict(const std::vector<float>& X) const override;

    // Function to print the parameters (theta) vector and the bias term of the model
    void printParameters() const;
};

#endif // LINEAR_REGRESSION_H
