
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace mystringwrapper {

    class MyString : public std::string {
    public:
        // Constructor
        // Constructs a MyString object with the provided string
        // Parameters:
        // - str: A pointer to a null-terminated C-style string (default is an empty string)
        MyString(const char* str = "");

        // Constructor
        // Constructs a MyString object with the provided string
        // Parameters:
        // - str: A pointer to a null-terminated C-style string (default is an empty string)
        MyString(const char str) : std::string(&str) {}
        
        // Shallow copy constructor
        MyString(const MyString& other) : std::string(other) {}


        // Constructor for deep copy
        // Constructs a MyString object with the provided string and performs deep copying if specified
        // Parameters:
        // - str: A pointer to a null-terminated C-style string (default is an empty string)
        // - deepCopy: A boolean value indicating whether to perform deep copying (default is false)
        MyString(const char* str, bool deepCopy) : std::string(deepCopy ? str : "") {}

        // Deep copy constructor
        MyString(const MyString& other, bool deepCopy) : std::string(deepCopy ? other : "") {}

        // Find function
        // Searches the string for the first occurrence of the substring 'substr'
        // Parameters:
        // - substr: The substring to search for
        // Returns:
        // - The position of the first character of the found substring
        // - If not found, returns std::string::npos
        size_t find(const MyString& substr) const;

        // Replace function
        // Replaces occurrences of 'oldStr' with 'newStr' in the string
        // Parameters:
        // - oldStr: The substring to be replaced
        // - newStr: The substring to replace occurrences of 'oldStr' with
        // Returns:
        // - Reference to the modified MyString object
        MyString& replace(const MyString& oldStr, const MyString& newStr);

        // Split function
        // Splits the string into tokens based on a delimiter
        // Parameters:
        // - delimiter: The character used as a delimiter to split the string
        // Returns:
        // - A vector containing the tokens as MyString objects
        std::vector<MyString> split(char delimiter) const;

        // Concatenate function
        // Appends the given string 'str' to the end of the string
        // Parameters:
        // - str: The string to be appended
        // Returns:
        // - Reference to the modified MyString object
        MyString& concat(const MyString& str);

        // Convert string to float
        // Converts the string to a floating-point number
        // Returns:
        // - The floating-point number represented by the string
        float toFloat() const;

        // Convert string to int
        // Converts the string to an integer
        // Returns:
        // - The integer represented by the string
        int toInt() const;

        // Overloads the + operator to concatenate two MyString objects
        // Parameters:
        // - lhs: The left-hand side MyString object
        // - rhs: The right-hand side MyString object
        // Returns:
        // - A new MyString object containing the concatenated string
        MyString operator+(const MyString& obj);
        
        // Assignment operator
        // Assigns the contents of another MyString object to this MyString object
        // Parameters:
        // - other: The MyString object to copy
        // Returns:
        // - Reference to the modified MyString object
        MyString& operator=(const MyString& other);
    };
};
#endif /* MYSTRING_H */
