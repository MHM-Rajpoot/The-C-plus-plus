
#ifndef KNN_H
#define KNN_H

#include "model.h"
#include <vector>
#include <string>

class KNN : public Model {
private:
    int k; // Number of neighbors to consider
    std::vector<std::vector<float>> X;
    std::vector<float> y;

public:
    // Constructor to initialize KNN model with the number of neighbors (k)
    KNN(int neighbors);

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

    // Function to calculate the distance between two data points
    // Parameters:
    // - point1: First data point
    // - point2: Second data point
    // Returns:
    // - The Euclidean distance between the two points
    float distance(const std::vector<float>& point1, const std::vector<float>& point2) const;

    // Function to find the indices of the k nearest neighbors
    // Parameters:
    // - X: Vector of feature values for a single data point
    // - training_data: Matrix of feature values for training data
    // Returns:
    // - Vector of indices of the k nearest neighbors
    std::vector<int> findNearestNeighbors(const std::vector<float>& X, const std::vector<std::vector<float>>& training_data) const;
};

#endif // KNN_H
