
#include "mystring.h"

namespace mystringwrapper {

    // Constructor
    MyString::MyString(const char* str) : std::string(str) {}

    // Find function
    size_t MyString::find(const MyString& substr) const {
        return this->std::string::find(substr);
    }

    // Replace function
    MyString& MyString::replace(const MyString& oldStr, const MyString& newStr) {
        // Using this pointer to access the member function find() of the current object
        size_t startPos = this->std::string::find(oldStr);
        if (startPos != std::string::npos) {
            // Using this pointer to access the member function replace() of the current object
            this->std::string::replace(startPos, oldStr.length(), newStr);
        }
        return *this; // Returning the current object by dereferencing this pointer
    }

    // Split function
    std::vector<MyString> MyString::split(char delimiter) const {
        std::vector<MyString> tokens;
        size_t startPos = 0;
        size_t endPos;
        while ((endPos = this->std::string::find(delimiter, startPos)) != std::string::npos) {
            // Using this pointer to access the member function substr() of the current object
            tokens.push_back(MyString(this->substr(startPos, endPos - startPos).c_str())); // Convert std::string to const char*
            startPos = endPos + 1;
        }
        // Using this pointer to access the member function substr() of the current object
        tokens.push_back(MyString(this->substr(startPos).c_str())); // Convert std::string to const char*
        return tokens;
    }

    // Concatenate function
    MyString& MyString::concat(const MyString& str) {
        // Using this pointer to access the member function append() of the current object
        this->std::string::append(str);
        return *this; // Returning the current object by dereferencing this pointer
    }

    // Convert string to float
    float MyString::toFloat() const {
        // Using this pointer to construct std::stringstream object with the current object
        std::stringstream ss(*this);
        float f;
        ss >> f;
        return f;
    }

    // Convert string to int
    int MyString::toInt() const {
        // Using this pointer to construct std::stringstream object with the current object
        std::stringstream ss(*this);
        int i;
        ss >> i;
        return i;
    }

    // Overloading the + operator for concatenating MyString objects
    MyString MyString::operator+(const MyString& obj) {
        MyString result = *this;
        result.concat(obj);
        return result;
    }

    // Assignment operator implementation
    MyString& MyString::operator=(const MyString& other) {
        if (this != &other) {
            // Call base class assignment operator to copy the string
            static_cast<std::string&>(*this) = other;
        }
        return *this;
    }

        // Definition of the overloaded operator<<
    std::ostream& operator<<(std::ostream& os, const MyString& str) {
        os << static_cast<const std::string&>(str); // Convert MyString to std::string and output
        return os;
    }

}