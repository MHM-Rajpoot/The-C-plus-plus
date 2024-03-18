
#include "car.h"

// Constructor
Car::Car(std::string b, int y) : brand(b), year(y) {}

// Destructor definition
Car::~Car() {
    // Add any necessary cleanup code here
}

// Member function to get brand
std::string Car::getBrand() {
    return brand;
}

// Member function to get year
int Car::getYear() {
    return year;
}

// Member function to set the brand of the car
void Car::setBrand(std::string b) {
    brand = b;
}

// Member function to set the manufacturing year of the car
void Car::setYear(int y) {
    year = y;
}
