
#include "mystring.h"
#include <iostream>

using namespace mystringwrapper;

int main() {

    // Shallow copy
    MyString shallowCopy1("Shallow");
    MyString shallowCopy2 = shallowCopy1; // Shallow copy constructor invoked
    std::cout << "Shallow copy 1: " << shallowCopy1 << std::endl;
    std::cout << "Shallow copy 2: " << shallowCopy2 << std::endl;

    // Modifying shallowCopy2 using the replace method will perform a shallow copy
    // This means that shallowCopy2 will share the same underlying data with shallowCopy1
    shallowCopy2.replace(MyString("Shallow"), MyString("Copy")); // Shallow copy in replace method
    std::cout << "After shallow modification:" << std::endl;
    std::cout << "Shallow copy 1: " << shallowCopy1 << std::endl;
    std::cout << "Shallow copy 2: " << shallowCopy2 << std::endl;

    // Deep copy
    // When creating deepCopy1, the deepCopy parameter is set to true
    // This causes the constructor to perform a deep copy, creating a separate copy of the underlying data
    MyString deepCopy1("Deep", true); // Deep copy invoked
    MyString deepCopy2 = deepCopy1;
    std::cout << "Deep copy 1: " << deepCopy1 << std::endl;
    std::cout << "Deep copy 2: " << deepCopy2 << std::endl;

    // Modifying deepCopy2 using the replace method will still perform a shallow copy
    // However, since deepCopy1 was created with deep copying, they do not share the same underlying data
    deepCopy2.replace(MyString("Deep"), MyString("Copy")); // Shallow copy in replace method
    std::cout << "After deep modification:" << std::endl;
    std::cout << "Deep copy 1: " << deepCopy1 << std::endl;
    std::cout << "Deep copy 2: " << deepCopy2 << std::endl;

    // Create MyString objects
    MyString str1("Hello");
    MyString str2(" ");
    MyString str3("world");

    // Concatenate strings using + operator

    MyString concatenatedString(str1);
    concatenatedString.concat(str2);
    concatenatedString = concatenatedString + str3;

    // Print the concatenated string
    std::cout << "Concatenated string: " << concatenatedString << std::endl;

    // Assignment operator
    MyString str4 = concatenatedString;
    // Print the concatenated string
    std::cout << "After Assignment: " << str4 << std::endl;

    // Find substring
    MyString substr("world");
    size_t foundPos = concatenatedString.find(substr);
    if (foundPos != MyString::npos) {
        std::cout << "Substring found at position: " << foundPos << std::endl;
    }
    else {
        std::cout << "Substring not found." << std::endl;
    }

    // Replace substring
    MyString oldStr("world");
    MyString newStr("everyone");
    concatenatedString.replace(oldStr, newStr);

    // Print the modified string
    std::cout << "Modified string: " << concatenatedString << std::endl;

    // Split string
    std::vector<MyString> tokens = concatenatedString.split(' ');
    std::cout << "Split string tokens:" << std::endl;
    for (const auto& token : tokens) {
        std::cout << token << std::endl;
    }

    return 0;
}
