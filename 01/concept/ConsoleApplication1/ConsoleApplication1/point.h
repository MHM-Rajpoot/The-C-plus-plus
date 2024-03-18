
#ifndef POINT_H
#define POINT_H

// Struct definition
struct Point {
    int x;  // Represents the x-coordinate of the point
    int y;  // Represents the y-coordinate of the point
};

// Function declarations

// Function to initialize a Point object with given coordinates
// Parameters:
// - point: A pointer to the Point object to be initialized
// - x: The x-coordinate value to assign to the Point object
// - y: The y-coordinate value to assign to the Point object
void initPoint(struct Point* point, int x, int y);

// Function to print the coordinates of a Point object
// Parameters:
// - point: A pointer to the Point object to be printed
void printPoint(struct Point* point);

// Function to perform cleanup for a Point object
// Parameters:
// - point: A pointer to the Point object to be printed
void cleanupPoint(struct Point* point);

#endif // POINT_H

// In this header file, we define a struct called Point, which represents a point in 2D space.
// We use initialization in the form of a constructor-like function (initPoint) to initialize
// the coordinates of a Point object with given values. This allows us to encapsulate the process
// of setting initial values for the object, improving code readability and maintainability.
// Additionally, we define a function (printPoint) that takes a Point object as a parameter
// and prints its coordinates. By passing objects and parameters to functions, we can operate
// on the data stored in the objects, making our code modular and reusable.
