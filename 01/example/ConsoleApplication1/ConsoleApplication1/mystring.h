#ifndef MYSTRING_H
#define MYSTRING_H

// Class definition for MyString
class MyString {
private:
    char* buffer;  // Pointer to the character buffer

public:
    // Constructor
    // Constructs a MyString object with the provided string
    // Parameters:
    // - str: A pointer to a null-terminated C-style string (default is an empty string)
    MyString(const char* str = "");

    // Destructor
    // Cleans up dynamically allocated memory for the buffer
    ~MyString();

    // Getter for the string value
    // Returns:
    // - A pointer to the internal character buffer
    const char* getValue() const; // Declared as const to indicate that this method does not modify the object's state

    // Setter for the string value
    // Updates the string value of the MyString object
    // Parameters:
    // - str: A pointer to a null-terminated C-style string
    void setValue(const char* str);

    // Method to display the string
    // Prints the string value of the MyString object to the standard output
    void display() const; // Declared as const to indicate that this method does not modify the object's state

    // Method to convert each character to ASCII and return sum of values in range 48 to 57
    // Returns:
    // - The sum of ASCII values of numeric characters found in the string, or -1 if no numeric characters are found
    int convertToInt() const; // Declared as const to indicate that this method does not modify the object's state

    // Method to convert the string to a float
    // Returns:
    // - The floating point representation of the string, or 0.0 if conversion fails
    float convertToFloat() const; // Declared as const to indicate that this method does not modify the object's state
};

#endif // MYSTRING_H
