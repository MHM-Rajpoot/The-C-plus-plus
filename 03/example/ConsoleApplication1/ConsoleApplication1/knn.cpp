
#include "knn.h"
#include <cmath>
#include <algorithm>

// Constructor
KNN::KNN(int neighbors) : k(neighbors) {}

// Fit method to store training data
void KNN::fit(std::vector<std::vector<float>> X, std::vector<float> y) {
    // KNN doesn't require explicit training, it simply stores the training data
    this->X = std::move(X);
    this->y = std::move(y);
}

// Prediction method
float KNN::predict(const std::vector<float>& X_test) const {
    // Find the indices of the k nearest neighbors
    std::vector<int> nearest_indices = findNearestNeighbors(X_test, this->X);

    // Calculate the average of target values of the k nearest neighbors
    float sum = 0.0;
    for (int index : nearest_indices) {
        sum += y[index];
    }
    return sum / k;
}

// Calculate distance between two points
float KNN::distance(const std::vector<float>& point1, const std::vector<float>& point2) const {
    float sum = 0.0;
    // Euclidean distance calculation
    for (size_t i = 0; i < point1.size(); ++i) {
        sum += std::pow(point1[i] - point2[i], 2);
    }
    return std::sqrt(sum);
}

// Find indices of k nearest neighbors
std::vector<int> KNN::findNearestNeighbors(const std::vector<float>& X_test, const std::vector<std::vector<float>>& training_data) const {
    std::vector<std::pair<float, int>> distances_indices;

    // Calculate distances between X_test and each data point in training_data
    for (size_t i = 0; i < training_data.size(); ++i) {
        float dist = distance(X_test, training_data[i]);
        // Store distance along with index
        distances_indices.emplace_back(dist, i);
    }

    // Sort distances and select k nearest neighbors
    std::sort(distances_indices.begin(), distances_indices.end());

    std::vector<int> nearest_indices(k);
    for (int i = 0; i < k; ++i) {
        nearest_indices[i] = distances_indices[i].second;
    }

    return nearest_indices;
}
