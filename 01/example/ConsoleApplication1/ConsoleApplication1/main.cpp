
#include "myString.h"
#include <iostream>

int main() {
    MyString str("Hello 123 World 890");

    std::cout << "Initial string:" << std::endl;
    str.display();

    // Convert each character to ASCII and return sum of values in range 48 to 57
    int num = str.convertToInt();
    if (num != -1)
        std::cout << "Numeric characters: " << num << std::endl;
    else
        std::cout << "No numeric characters found." << std::endl;

    str.setValue(" hello -123.890 Noice");

    // Convert string to float
    float floatValue = str.convertToFloat();
    std::cout << "Float value: " << floatValue << std::endl;

    return 0;
}
