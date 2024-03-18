
#include "set.h"
#include <iostream>
#include <functional> // Add this for std::function

using namespace std;

// Constructor
set::set() {
    rbTree = new rgtree(); // Initialize the Red Black Tree
}

// Destructor
set::~set() {
    delete rbTree; // Free the memory allocated for the Red Black Tree
}

// Insert a value into the set
// Parameters:
// - value: The value to be inserted
void set::insert(int value) {
    if (!contains(value)) { // Check if the value already exists in the set
        rbTree->insertValue(value); // Insert the value into the Red Black Tree
    }
}

// Remove a value from the set
// Parameters:
// - value: The value to be removed
void set::erase(int value) {
    rbTree->deleteValue(value); // Remove the value from the Red Black Tree
}

// Check if a value exists in the set
// Parameters:
// - value: The value to be checked
// Returns:
// True if the value exists in the set, false otherwise
bool set::contains(int value) const {
    return rbTree->searchValue(value); // Search for the value in the Red Black Tree
}

// Perform set union operation between the current set and another set
// Parameters:
// - other: The set to perform union operation with
// Returns:
// A new set containing elements from both the current set and the other set
set set::set_union(const set& other) const {
    set result;

    // Insert all elements from the current set
    Node* current = rbTree->root;
    std::function<void(Node*)> inorderTraversal = [&](Node* current) {
        if (current == nullptr)
            return;
        inorderTraversal(current->left);
        result.insert(current->data);
        inorderTraversal(current->right);
        };

    inorderTraversal(current);

    // Insert all elements from the other set
    current = other.rbTree->root;
    inorderTraversal(current);

    return result;
}

// Perform set intersection operation between the current set and another set
// Parameters:
// - other: The set to perform intersection operation with
// Returns:
// A new set containing elements common to both the current set and the other set
set set::set_intersection(const set& other) const {
    set result;
    intersectHelper(rbTree->root, other.rbTree, result);
    return result;
}

// Perform set difference operation between the current set and another set
// Parameters:
// - other: The set to perform difference operation with
// Returns:
// A new set containing elements that are present in the current set but not in the other set
set set::set_difference(const set& other) const {
    set result;
    differenceHelper(rbTree->root, other.rbTree, result);
    return result;
}

// Helper function for set intersection operation
void set::intersectHelper(Node* root, rgtree* otherTree, set& result) const {
    if (root == nullptr)
        return;

    intersectHelper(root->left, otherTree, result);
    if (otherTree->searchValue(root->data))
        result.insert(root->data);
    intersectHelper(root->right, otherTree, result);
}

// Helper function for set difference operation
void set::differenceHelper(Node* root, rgtree* otherTree, set& result) const {
    if (root == nullptr)
        return;

    differenceHelper(root->left, otherTree, result);
    if (!otherTree->searchValue(root->data))
        result.insert(root->data);
    differenceHelper(root->right, otherTree, result);
}

// Overloaded operator for set union (operator+)
set set::operator+(const set& other) const {
    return this->set_union(other);
}

// Overloaded operator for set intersection (operator%)
set set::operator%(const set& other) const {
    return this->set_intersection(other);
}

// Overloaded operator for set difference (operator-)
set set::operator-(const set& other) const {
    return this->set_difference(other);
}

// Print the elements of the set
void set::print() const {
    if (rbTree->root) {
        printHelper(rbTree->root);
    }
    std::cout << std::endl;
}

// Helper function for printing the elements of the set
void set::printHelper(Node* root) const {
    if (root == nullptr)
        return;

    printHelper(root->left);
    std::cout << root->data << " "; // Print the value of the node
    printHelper(root->right);
}
