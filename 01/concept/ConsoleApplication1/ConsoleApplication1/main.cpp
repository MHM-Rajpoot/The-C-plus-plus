
#include <iostream>
#include <string>
#include <cstring> // C String -> strcpy_s()
#include "point.h"
#include "data.h"
#include "car.h"

int main() {
    // Size of Struct Point: 8 bytes
    // Explanation: The Point struct contains two integer members (int x and int y).
    // On many systems, int is typically 4 bytes in size. The size of the struct
    // is padded to the nearest multiple of the largest member size, resulting in 8 bytes.
    std::cout << "Size of Struct Point: " << sizeof(Point) << " bytes\n";

    // Size of Union Data: 20 bytes
    // Explanation: The Data union contains three members: intValue (int), floatValue (float),
    // and stringValue (a fixed-size char array of 20 characters). The size of the union
    // is determined by the largest member, which is the stringValue array.
    std::cout << "Size of Union Data: " << sizeof(Data) << " bytes\n";

    // Size of Class Car: 48 bytes
    // Explanation: The Car class has two data members: std::string brand and int year.
    // The total size includes the size of the string data, the size of the integer, and
    // any padding added by the compiler for alignment purposes.
    std::cout << "Size of Class Car: " << sizeof(Car) << " bytes\n";

    // Enum usage
    DataType type = INT_TYPE;

    // Union usage with enum
    Data data;
    switch (type) {
    case INT_TYPE:
        data.intValue = 42;
        std::cout << "Union - Int Value: " << data.intValue << std::endl;
        std::cout << "Size of Union Data: " << sizeof(Data) << " bytes\n";
        break;
    case FLOAT_TYPE:
        data.floatValue = 3.14f;
        std::cout << "Union - Float Value: " << data.floatValue << std::endl;
        std::cout << "Size of Union Data: " << sizeof(Data) << " bytes\n";
        break;
    case STRING_TYPE:
        strcpy_s(data.stringValue, "Hello, Union!");
        std::cout << "Union - String Value: " << data.stringValue << std::endl;
        std::cout << "Size of Union Data: " << sizeof(Data) << " bytes\n";
        break;
    }

    // Class and object usage
    Car myCar("Toyota", 2020);
    std::cout << "Class - Car Brand: " << myCar.getBrand() << ", Year: " << myCar.getYear() << std::endl;

    return 0;
}
