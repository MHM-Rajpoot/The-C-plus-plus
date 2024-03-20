
#ifndef RED_BLACK_TREE_RBTREE_H
#define RED_BLACK_TREE_RBTREE_H

// Enum to represent node colors
enum Color { RED, BLACK, DOUBLE_BLACK };

// Node structure for Red Black Tree
struct Node
{
    int data;           // Data stored in the node
    int color;          // Color of the node
    Node* left, * right, * parent; // Pointers to left child, right child, and parent node

    explicit Node(int); // Constructor for node with data value
};

// Red Black Tree class
class rgtree
{
private:
    Node* root; // Root node of the Red Black Tree

protected:
    // Rotate the subtree rooted at the given node to the left
    void rotateLeft(Node*&);

    // Rotate the subtree rooted at the given node to the right
    void rotateRight(Node*&);

    // Fix the Red Black Tree properties after insertion
    void fixInsertRBTree(Node*&);

    // Fix the Red Black Tree properties after deletion
    void fixDeleteRBTree(Node*&);

    // Perform inorder traversal of the Red Black Tree rooted at the given node
    void inorderBST(Node*&);

    // Perform preorder traversal of the Red Black Tree rooted at the given node
    void preorderBST(Node*&);

    // Get the color of the given node
    int getColor(Node*&);

    // Set the color of the given node
    void setColor(Node*&, int);

    // Find the node with the minimum value in the subtree rooted at the given node
    Node* minValueNode(Node*&);

    // Find the node with the maximum value in the subtree rooted at the given node
    Node* maxValueNode(Node*&);

    // Insert a node into the Binary Search Tree rooted at the given node
    Node* insertBST(Node*&, Node*&);

    // Delete a node with the given value from the Binary Search Tree rooted at the given node
    Node* deleteBST(Node*&, int);

    // Get the black height of the Red Black Tree rooted at the given node
    int getBlackHeight(Node*);

public:
    // Friend declaration for Unorder_set class to access protected members
    friend class set;

    // Constructor for rgtree class
    rgtree();

    // Insert a value into the Red Black Tree
    // Parameters:
    // - value: The integer value to be inserted
    void insertValue(int value);

    // Delete a value from the Red Black Tree
    // Parameters:
    // - value: The integer value to be deleted
    void deleteValue(int value);

    // Merge the current Red Black Tree with another Red Black Tree
    // Parameters:
    // - otherTree: The Red Black Tree to be merged with the current tree
    void merge(rgtree otherTree);

    // Search for a value in the Red Black Tree
    // Parameters:
    // - value: The integer value to search for
    // Returns:
    // - true if the value is found, false otherwise
    bool searchValue(int value);

    // Perform an inorder traversal of the Red Black Tree and print the values
    void inorder();

    // Perform a preorder traversal of the Red Black Tree and print the values
    void preorder();
};

#endif //RED_BLACK_TREE_RBTREE_H
