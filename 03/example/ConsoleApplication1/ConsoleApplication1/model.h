
#ifndef MODEL_H
#define MODEL_H

#include <vector>

class Model {
public:
    // Pure virtual function for fitting the model with training data
    // Parameters:
    // - X: Matrix of feature values
    // - y: Vector of target values
    virtual void fit(std::vector<std::vector<float>> X, std::vector<float> y) = 0;

    // Pure virtual function for making predictions on new data
    // Parameters:
    // - X: Vector of feature values for a single data point
    // Returns:
    // - The predicted target value
    virtual float predict(const std::vector<float>& X) const = 0;
};

#endif // MODEL_H
