
#include <iostream>
#include <stdexcept>
#include "list.h"

// Initialize the static member variable size
template<class T>
int list<T>::size = 0;

// Constructor
template<class T>
list<T>::list() : list_head(nullptr), list_tail(nullptr) {}

// Copy constructor
template<class T>
list<T>::list(const list<T>& other) : list_head(nullptr), list_tail(nullptr) {
    Node<T>* current = other.Head();
    while (current != nullptr) {
        push_back(current->retrieve());
        current = current->next();
    }
}

// Destructor
template<class T>
list<T>::~list() {
    while (!empty()) {
        pop_front();
    }
}

// Function to return the head of the list
template<class T>
Node<T>* list<T>::Head() const {
    return list_head;
}

// Function to return the tail of the list
template<class T>
Node<T>* list<T>::Tail() const {
    return list_tail;
}

// Function to return the first element of the list
template<class T>
T list<T>::front() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return list_head->retrieve();
}

// Function to add an element to the end of the list
template<class T>
void list<T>::push_front(T val) {
    Node<T>* newNode = new Node<T>(val, list_head, nullptr);
    if (list_tail == nullptr) {
        list_tail = newNode;
    }
    else {
        list_head->setprev(newNode);
    }
    list_head = newNode;
    size++;
}

// Function to remove the first element of the list
template<class T>
void list<T>::pop_front() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    Node<T>* temp = list_head;
    list_head = list_head->next();
    if (list_head != nullptr) {
        list_head->setprev(nullptr);
    }
    else {
        list_tail = nullptr;
    }
    delete temp;
    size--;
}

// Function to return the last element of the list
template<class T>
T list<T>::back() const {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    return list_tail->retrieve();
}

// Function to add an element to the beginning of the list
template<class T>
void list<T>::push_back(T val) {
    Node<T>* newNode = new Node<T>(val, nullptr, list_tail);
    if (list_head == nullptr) {
        list_head = newNode;
    }
    else {
        list_tail->setnext(newNode);
    }
    list_tail = newNode;
    size++;
}

// Function to remove the last element of the list
template<class T>
void list<T>::pop_back() {
    if (empty()) {
        throw std::out_of_range("List is empty");
    }
    Node<T>* temp = list_tail;
    list_tail = list_tail->prev();
    if (list_tail != nullptr) {
        list_tail->setnext(nullptr);
    }
    else {
        list_head = nullptr;
    }
    delete temp;
    size--;
}

// Function to check if the list is empty
template<class T>
bool list<T>::empty() const {
    return list_head == nullptr;
}

// Function to return the size of the list
template<class T>
int list<T>::_size() const {
    return size;
}

// Function to access an element of the list by index
template<class T>
T list<T>::at(int index) const {
    return (*this)[index]; // Call the operator[] function to access the element
}

// Function to get input values from user and store them in the list
template<class T>
void list<T>::getInputValues() {
    std::cout << "Enter values (enter -1 to stop):" << std::endl;
    int value;
    while (true) {
        std::cin >> value;
        if (value == -1) {
            break;
        }
        push_back(value); // Use push_back to add input value to the list
    }
}

// Overloaded subscript operator to access elements by index
template<class T>
T list<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    Node<T>* current;
    if (index < size / 2) { // Start from head if index is closer to the head
        current = list_head;
        for (int i = 0; i < index; ++i) {
            current = current->next();
        }
    }
    else { // Start from tail if index is closer to the tail
        current = list_tail;
        for (int i = size - 1; i > index; --i) {
            current = current->prev();
        }
    }
    return current->retrieve();
}