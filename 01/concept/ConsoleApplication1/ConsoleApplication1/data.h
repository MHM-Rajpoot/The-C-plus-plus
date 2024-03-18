
#ifndef DATA_H
#define DATA_H

// Union definition
union Data {
    int intValue;
    float floatValue;
    char stringValue[20];
};

#endif // DATA_H

// This header file defines a union called Data, which is a special type that allows different data types
// to be stored in the same memory location. We use this union to represent different types of data (integer,
// floating-point, or string). The union is useful when we want to store different types of data in a single
// variable depending on the context, saving memory by sharing the same memory space.


#ifndef ENUMS_H
#define ENUMS_H

// Enum definition
enum DataType {
    INT_TYPE,
    FLOAT_TYPE,
    STRING_TYPE
};

#endif // ENUMS_H

// This header file defines an enum called DataType, which provides symbolic names for different types of data.
// We use this enum to indicate the type of data stored in the union (e.g., INT_TYPE for integer, FLOAT_TYPE
// for floating-point, STRING_TYPE for string). Enums help improve code readability by providing meaningful
// names for integral constants, making the code more understandable and maintainable.
