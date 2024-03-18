#ifndef CAR_H
#define CAR_H

#include <string>

// Class definition
class Car {
private:
    std::string brand;  // Represents the brand of the car
    int year;           // Represents the manufacturing year of the car

public:
    // Constructor
    Car(std::string b, int y);

    // Destructor
    ~Car();

    // Member function to get the brand of the car
    // Returns:
    // - The brand of the car as a string
    std::string getBrand();

    // Member function to get the manufacturing year of the car
    // Returns:
    // - The manufacturing year of the car as an integer
    int getYear();

    // Member function to set the brand of the car
    // Parameters:
    // - b: The new brand of the car as a string
    void setBrand(std::string b);

    // Member function to set the manufacturing year of the car
    // Parameters:
    // - y: The new manufacturing year of the car as an integer
    void setYear(int y);
};

#endif // CAR_H

// In this header file, we define a class called Car, which represents a car object.
// The class encapsulates data about the brand and manufacturing year of the car.
// We provide a constructor to initialize the brand and year when creating a car object.
// Additionally, a destructor is provided to clean up resources when a car object is destroyed.
// Member functions getBrand() and getYear() allow users to retrieve information about the car.
// Access specifiers ensure that the brand and year data members are encapsulated and only accessible
// through the provided member functions, promoting data hiding and encapsulation principles.
