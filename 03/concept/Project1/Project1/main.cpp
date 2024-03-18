
#include <iostream>
#include "set.h"
#include "rgtree.h"

using namespace std;

int main() {
    
    /*
    // Create the Red Black Trees
    rgtree rbTree1;
    rgtree rbTree2;

    // Insert values into the first Red Black Tree
    cout << "Inserting values into the first Red Black Tree:" << endl;
    rbTree1.insertValue(5);
    rbTree1.insertValue(3);
    rbTree1.insertValue(8);
    rbTree1.insertValue(2);
    rbTree1.insertValue(4);
    rbTree1.insertValue(6);
    rbTree1.insertValue(9);
    rbTree1.insertValue(1);
    rbTree1.insertValue(7);
    cout << "Inorder traversal of the first Red Black Tree:" << endl;
    rbTree1.inorder();
    cout << endl;
    cout << "Preorder traversal of the first Red Black Tree:" << endl;
    rbTree1.preorder();
    cout << endl;

    // Insert values into the second Red Black Tree
    cout << "\nInserting values into the second Red Black Tree:" << endl;
    rbTree2.insertValue(12);
    rbTree2.insertValue(10);
    rbTree2.insertValue(14);
    rbTree2.insertValue(11);
    rbTree2.insertValue(13);
    cout << "Inorder traversal of the second Red Black Tree:" << endl;
    rbTree2.inorder();
    cout << endl;
    cout << "Preorder traversal of the second Red Black Tree:" << endl;
    rbTree2.preorder();
    cout << endl;

    // Search for a specific value in the first Red Black Tree
    int valueToSearch = FP_INFINITE;
    cout << "\nSearching for value " << valueToSearch << " in the first Red Black Tree:" << endl;
    if (rbTree1.searchValue(valueToSearch))
        cout << "Value " << valueToSearch << " found in the first Red Black Tree." << endl;
    else
        cout << "Value " << valueToSearch << " not found in the first Red Black Tree." << endl;

    // Merge the second Red Black Tree into the first Red Black Tree
    cout << "\nMerging the second Red Black Tree into the first Red Black Tree:" << endl;
    rbTree1.merge(rbTree2);
    cout << "Inorder traversal of the merged Red Black Tree:" << endl;
    rbTree1.inorder();
    cout << endl;
    cout << "Preorder traversal of the merged Red Black Tree:" << endl;
    rbTree1.preorder();
    cout << endl;
    */

    // Create sets
    set set1, set2;

    // Insert elements into set1
    set1.insert(1);
    set1.insert(2);
    set1.insert(3);

    // Insert elements into set2
    set2.insert(2);
    set2.insert(3);
    set2.insert(4);

    // Print sets
    std::cout << "Set 1: ";
    set1.print();
    std::cout << std::endl;

    std::cout << "Set 2: ";
    set2.print();
    std::cout << std::endl;

    // Perform union
    set unionSet = set1 + set2;
    std::cout << "Union: ";
    unionSet.print();
    std::cout << std::endl;

    // Perform intersection
    set intersectionSet = set1 % set2;
    std::cout << "Intersection: ";
    intersectionSet.print();
    std::cout << std::endl;

    // Perform difference
    set differenceSet = set1 - set2;
    std::cout << "Difference: ";
    differenceSet.print();
    std::cout << std::endl;


    return 0;
}
