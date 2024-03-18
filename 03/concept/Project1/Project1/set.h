
#ifndef SET_H
#define SET_H

#include <iostream>
#include "rgtree.h" // Assuming rgtree is defined in another header file

class set {
    rgtree* rbTree; // Pointer to Red Black Tree

public:
    // Constructor
    set();

    // Destructor
    ~set();

    // Insert a value into the set
    // Parameters:
    // - value: The value to be inserted
    void insert(int value);

    // Remove a value from the set
    // Parameters:
    // - value: The value to be removed
    void erase(int value);

    // Check if a value exists in the set
    // Parameters:
    // - value: The value to be checked
    // Returns:
    // True if the value exists in the set, false otherwise
    bool contains(int value) const;

    // Perform set union operation between the current set and another set
    // Parameters:
    // - other: The set to perform union operation with
    // Returns:
    // A new set containing elements from both the current set and the other set
    set set_union(const set& other) const;

    // Perform set intersection operation between the current set and another set
    // Parameters:
    // - other: The set to perform intersection operation with
    // Returns:
    // A new set containing elements common to both the current set and the other set
    set set_intersection(const set& other) const;

    // Perform set difference operation between the current set and another set
    // Parameters:
    // - other: The set to perform difference operation with
    // Returns:
    // A new set containing elements that are present in the current set but not in the other set
    set set_difference(const set& other) const;

    // Print the elements of the set
    void print() const;

    // Overloaded operator for set union (operator+)
    set operator+(const set& other) const;

    // Overloaded operator for set intersection (operator%)
    set operator%(const set& other) const;

    // Overloaded operator for set difference (operator-)
    set operator-(const set& other) const;

private:
    // Helper function for set intersection operation
    void intersectHelper(Node* root, rgtree* otherTree, set& result) const;

    // Helper function for set difference operation
    void differenceHelper(Node* root, rgtree* otherTree, set& result) const;

    // Helper function for printing the elements of the set
    void printHelper(Node* root) const;
};

#endif // SET_H
