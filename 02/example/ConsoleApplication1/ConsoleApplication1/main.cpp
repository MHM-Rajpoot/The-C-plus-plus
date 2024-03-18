
#include <iostream>
#include <stdexcept> // for out_of_range exception
#include "node.h"
#include "list.h"
#include "list.cpp"

using namespace std;

int main() {
    list<int> mylist;
    mylist.push_back(10);
    mylist.push_back(20);
    mylist.push_back(30);

    cout << "Front: " << mylist.front() << endl; // Should print 10
    cout << "Back: " << mylist.back() << endl; // Should print 30
    cout << "Size: " << mylist._size() << endl; // Should print 3

    mylist.getInputValues(); // Get input values from the user

    cout << "Elements: ";
    for (int i = 0; i < mylist._size(); ++i) {
        cout << mylist[i] << " ";
    }
    cout << endl;

    try {
        cout << "At index 1: " << mylist[1] << endl; // Should print 20
        cout << "At index 3: " << mylist[3] << endl; // Should throw out_of_range exception
    }
    catch (const out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }

    cout << "Elements: ";
    for (int i = 0; i < mylist._size(); ++i) {
        cout << mylist.at(i) << " ";
    }
    cout << endl;

    return 0;
}
