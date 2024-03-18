
#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
    T element;
    Node<T>* next_node;
    Node<T>* prev_node;

public:
    // Constructor
    // Constructs a node with the provided element and pointers to the next and previous nodes
    // Parameters:
    // - elem: The element stored in the node (default is the default value of type T)
    // - next: A pointer to the next node in the list (default is nullptr)
    // - prev: A pointer to the previous node in the list (default is nullptr)
    Node(T elem = T(), Node<T>* next = nullptr, Node<T>* prev = nullptr)
        : element(elem), next_node(next), prev_node(prev) {}

    // Function to retrieve the element stored in the node
    T retrieve() const {
        return element;
    }

    // Function to return a pointer to the next node
    Node<T>* next() const {
        return next_node;
    }

    // Function to return a pointer to the previous node
    Node<T>* prev() const {
        return prev_node;
    }

    // Function to set the next node
    void setnext(Node<T>* next) {
        next_node = next;
    }

    // Function to set the previous node
    void setprev(Node<T>* prev) {
        prev_node = prev;
    }
};

#endif // NODE_H
