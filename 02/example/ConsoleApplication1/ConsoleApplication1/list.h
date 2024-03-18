
#ifndef LIST_H
#define LIST_H

#include "node.h"

template <class T>
class list {
private:
    Node<T>* list_head;
    Node<T>* list_tail;
    static int size;

public:
    // Constructor
    // Constructs an empty list
    list();

    // Copy constructor
    // Constructs a list by copying elements from another list
    // Parameters:
    // - other: The list to be copied
    list(const list<T>& other);

    // Destructor
    // Destroys the list, freeing all allocated memory
    ~list();

    // Function to return the head of the list
    Node<T>* Head() const;

    // Function to return the tail of the list
    Node<T>* Tail() const;

    // Function to return the first element of the list
    T front() const;

    // Function to add an element to the end of the list
    void push_back(T val);

    // Function to remove the first element of the list
    void pop_front();

    // Function to return the last element of the list
    T back() const;

    // Function to add an element to the beginning of the list
    void push_front(T val);

    // Function to remove the last element of the list
    void pop_back();

    // Function to check if the list is empty
    bool empty() const;

    // Function to return the size of the list
    int _size() const;

    // Function to access an element of the list by index
    T at(int index) const;

    // Function to get input values from user and store them in the list
    void getInputValues();

    // Overloaded subscript operator to access elements by index
    T operator[](int index) const;
};

#endif // LIST_H
