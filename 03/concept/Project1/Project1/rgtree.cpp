
#include <iostream>
#include "rgtree.h"

using namespace std;

// Constructor for Node class
Node::Node(int data) {
    this->data = data;
    color = RED;
    left = right = parent = nullptr;
}

// Constructor for rgtree class
rgtree::rgtree() {
    root = nullptr;
}

// Function to get color of a node
int rgtree::getColor(Node*& node) {
    if (node == nullptr)
        return BLACK;

    return node->color;
}

// Function to set color of a node
void rgtree::setColor(Node*& node, int color) {
    if (node == nullptr)
        return;

    node->color = color;
}

// Function to perform BST insert
Node* rgtree::insertBST(Node*& root, Node*& ptr) {
    if (root == nullptr)
        return ptr;

    if (ptr->data < root->data) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    }
    else if (ptr->data > root->data) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}

// Function to insert a value into the Red Black Tree
void rgtree::insertValue(int n) {
    Node* node = new Node(n);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

// Function to perform left rotation
void rgtree::rotateLeft(Node*& ptr) {
    Node* right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

// Function to perform right rotation
void rgtree::rotateRight(Node*& ptr) {
    Node* left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

// Function to fix the Red Black Tree after insertion
void rgtree::fixInsertRBTree(Node*& ptr) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->parent) == RED) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
        else {
            Node* uncle = grandparent->left;
            if (getColor(uncle) == RED) {
                setColor(uncle, BLACK);
                setColor(parent, BLACK);
                setColor(grandparent, RED);
                ptr = grandparent;
            }
            else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, BLACK);
}

// Function to fix the Red Black Tree after deletion
void rgtree::fixDeleteRBTree(Node*& node) {
    if (node == nullptr)
        return;

    // Handling case where node is root
    if (node == root) {
        root = nullptr;
        return;
    }

    // Handling case where node, its left child, or its right child is red
    if (getColor(node) == RED || getColor(node->left) == RED || getColor(node->right) == RED) {
        Node* child = node->left != nullptr ? node->left : node->right;

        // If node is a left child
        if (node == node->parent->left) {
            node->parent->left = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
        else { // If node is a right child
            node->parent->right = child;
            if (child != nullptr)
                child->parent = node->parent;
            setColor(child, BLACK);
            delete (node);
        }
    }
    else {
        Node* sibling = nullptr;
        Node* parent = nullptr;
        Node* ptr = node;
        setColor(ptr, DOUBLE_BLACK);
        while (ptr != root && getColor(ptr) == DOUBLE_BLACK) {
            parent = ptr->parent;
            // If ptr is a left child
            if (ptr == parent->left) {
                sibling = parent->right;
                // Case where sibling is red
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                }
                else { // Case where sibling is black
                    // Case where both children of sibling are black
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        // If parent is red, set it to black; else set it to double black
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else { // Case where at least one child of sibling is red
                        // Case where right child of sibling is black
                        if (getColor(sibling->right) == BLACK) {
                            setColor(sibling->left, BLACK);
                            setColor(sibling, RED);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->right, BLACK);
                        rotateLeft(parent);
                        break;
                    }
                }
            }
            else { // If ptr is a right child
                sibling = parent->left;
                // Case where sibling is red
                if (getColor(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                }
                else { // Case where sibling is black
                    // Case where both children of sibling are black
                    if (getColor(sibling->left) == BLACK && getColor(sibling->right) == BLACK) {
                        setColor(sibling, RED);
                        // If parent is red, set it to black; else set it to double black
                        if (getColor(parent) == RED)
                            setColor(parent, BLACK);
                        else
                            setColor(parent, DOUBLE_BLACK);
                        ptr = parent;
                    }
                    else { // Case where at least one child of sibling is red
                        // Case where left child of sibling is black
                        if (getColor(sibling->left) == BLACK) {
                            setColor(sibling->right, BLACK);
                            setColor(sibling, RED);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, BLACK);
                        setColor(sibling->left, BLACK);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        // Update parent's reference to node
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        // Delete node
        delete(node);
        // Set root color to black
        setColor(root, BLACK);
    }
}

// Function to perform BST delete
Node* rgtree::deleteBST(Node*& root, int data) {
    if (root == nullptr)
        return root;

    if (data < root->data)
        return deleteBST(root->left, data);

    if (data > root->data)
        return deleteBST(root->right, data);

    if (root->left == nullptr || root->right == nullptr)
        return root;

    Node* temp = minValueNode(root->right);
    root->data = temp->data;
    return deleteBST(root->right, temp->data);
}

// Function to delete a value from the Red Black Tree
void rgtree::deleteValue(int data) {
    Node* node = deleteBST(root, data);
    fixDeleteRBTree(node);
}

// Function to perform inorder traversal of BST
void rgtree::inorderBST(Node*& ptr) {
    if (ptr == nullptr)
        return;

    inorderBST(ptr->left);
    cout << ptr->data << " " << ptr->color << endl;
    inorderBST(ptr->right);
}

// Function to perform inorder traversal of the Red Black Tree
void rgtree::inorder() {
    inorderBST(root);
}

// Function to perform preorder traversal of BST
void rgtree::preorderBST(Node*& ptr) {
    if (ptr == nullptr)
        return;

    cout << ptr->data << " " << ptr->color << endl;
    preorderBST(ptr->left);
    preorderBST(ptr->right);
}

// Function to perform preorder traversal of the Red Black Tree
void rgtree::preorder() {
    preorderBST(root);
    cout << "-------" << endl;
}

// Function to find the node with minimum value in a subtree
Node* rgtree::minValueNode(Node*& node) {
    Node* ptr = node;

    while (ptr->left != nullptr)
        ptr = ptr->left;

    return ptr;
}

// Function to find the node with maximum value in a subtree
Node* rgtree::maxValueNode(Node*& node) {
    Node* ptr = node;

    while (ptr->right != nullptr)
        ptr = ptr->right;

    return ptr;
}

// Function to get black height of a subtree
int rgtree::getBlackHeight(Node* node) {
    int blackheight = 0;
    while (node != nullptr) {
        if (getColor(node) == BLACK)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

// Function to merge two Red Black Trees
void rgtree::merge(rgtree rbTree2) {
    int temp;
    Node* c;
    Node* root1 = root;
    Node* root2 = rbTree2.root;
    int initialblackheight1 = getBlackHeight(root1);
    int initialblackheight2 = getBlackHeight(root2);

    // Balancing tree heights
    if (initialblackheight1 > initialblackheight2) {
        c = maxValueNode(root1);
        temp = c->data;
        deleteValue(c->data);
        root1 = root;
    }
    else if (initialblackheight2 > initialblackheight1) {
        c = minValueNode(root2);
        temp = c->data;
        rbTree2.deleteValue(c->data);
        root2 = rbTree2.root;
    }
    else {
        c = minValueNode(root2);
        temp = c->data;
        rbTree2.deleteValue(c->data);
        root2 = rbTree2.root;
        if (initialblackheight1 != getBlackHeight(root2)) {
            rbTree2.insertValue(c->data);
            root2 = rbTree2.root;
            c = maxValueNode(root1);
            temp = c->data;
            deleteValue(c->data);
            root1 = root;
        }
    }

    setColor(c, RED);
    int finalblackheight1 = getBlackHeight(root1);
    int finalblackheight2 = getBlackHeight(root2);

    // Merging trees
    if (finalblackheight1 == finalblackheight2) {
        c->left = root1;
        if (root1 != nullptr)
            root1->parent = c;
        c->right = root2;
        if (root2 != nullptr)
            root2->parent = c;
        setColor(c, BLACK);
        c->data = temp;
        root = c;
    }
    else if (finalblackheight2 > finalblackheight1) {
        Node* ptr = root2;
        Node* temp_ptr = nullptr;
        while (finalblackheight1 != getBlackHeight(ptr)) {
            temp_ptr = ptr;
            ptr = ptr->left;
        }
        Node* ptr_parent;
        if (ptr == nullptr)
            ptr_parent = temp_ptr;
        else
            ptr_parent = ptr->parent;

        c->left = root1;
        if (root1 != nullptr)
            root1->parent = c;
        c->right = ptr;
        if (ptr != nullptr)
            ptr->parent = c;
        ptr_parent->left = c;
        c->parent = ptr_parent;

        if (getColor(ptr_parent) == RED) {
            fixInsertRBTree(c);
        }
        else if (getColor(ptr) == RED) {
            fixInsertRBTree(ptr);
        }
        c->data = temp;
        root = root2;
    }
    else {
        Node* ptr = root1;
        while (finalblackheight2 != getBlackHeight(ptr)) {
            ptr = ptr->right;
        }
        Node* ptr_parent = ptr->parent;

        c->right = root2;
        if (root2 != nullptr)
            root2->parent = c;
        c->left = ptr;
        ptr->parent = c;
        ptr_parent->right = c;
        c->parent = ptr_parent;

        if (getColor(ptr_parent) == RED) {
            fixInsertRBTree(c);
        }
        else if (getColor(ptr) == RED) {
            fixInsertRBTree(ptr);
        }
        c->data = temp;
        root = root1;
    }
}

// Search for a value in the Red Black Tree
bool rgtree::searchValue(int value) {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == value)
            return true;
        else if (current->data < value)
            current = current->right;
        else
            current = current->left;
    }
    return false;
}
