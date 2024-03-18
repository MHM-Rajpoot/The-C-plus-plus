
#include "MyString.h"
#include <iostream>
#include <cstring>

// Constructor
MyString::MyString(const char* str) {
    size_t length = strlen(str);
    buffer = new char[length + 1];
    strcpy_s(buffer, length + 1, str);
}

// Destructor
MyString::~MyString() {
    delete[] buffer;
}

// Getter for the string value
const char* MyString::getValue() const {
    return buffer;
}

// Setter for the string value
void MyString::setValue(const char* str) {
    size_t length = strlen(str);
    delete[] buffer; // Free previously allocated memory
    buffer = new char[length + 1];
    strcpy_s(buffer, length + 1, str);
}

// Method to display the string
void MyString::display() const {
    std::cout << "String: " << buffer << std::endl;
}

// Method to convert each character to ASCII and return sum of values in range 48 to 57
int MyString::convertToInt() const {
    int sum = 0;
    bool hasNumeric = false; // Flag to check if any numeric character found
    bool isNegative = false; // Flag to check if the number is negative

    // Skip leading non-numeric characters
    size_t i = 0;
    while (buffer[i] != '\0' && !isdigit(buffer[i])) {
        if (buffer[i] == '-') {
            isNegative = true;
        }
        ++i;
    }

    // Parse integer part
    for (; buffer[i] != '\0' && isdigit(buffer[i]); ++i) {
        sum = sum * 10 + (buffer[i] - '0'); // Convert ASCII digit to integer
        hasNumeric = true;
    }

    return hasNumeric ? (isNegative ? -sum : sum) : -1; // Return -1 if no numeric characters found
}

// Method to convert the string to a float
float MyString::convertToFloat() const {
    float result = 0.0;
    bool hasNumeric = false; // Flag to check if any numeric character found
    bool isNegative = false; // Flag to check if the number is negative
    bool hasDecimal = false; // Flag to check if the number has a decimal point

    // Skip leading non-numeric characters
    size_t i = 0;
    while (buffer[i] != '\0' && !isdigit(buffer[i])) {
        if (buffer[i] == '-') {
            isNegative = true;
        }
        ++i;
    }

    // Parse integer part
    for (; buffer[i] != '\0' && isdigit(buffer[i]); ++i) {
        result = result * 10 + (buffer[i] - '0'); // Convert ASCII digit to float
        hasNumeric = true;
    }

    // Parse fractional part
    if (buffer[i] == '.') {
        hasDecimal = true;
        float fraction = 0.1;
        ++i;
        for (; buffer[i] != '\0' && isdigit(buffer[i]); ++i) {
            result += (buffer[i] - '0') * fraction;
            fraction *= 0.1;
        }
    }

    if (isNegative) {
        result = -result;
    }

    return hasNumeric ? result : -1.0; // Return -1.0 if no numeric characters found
}
