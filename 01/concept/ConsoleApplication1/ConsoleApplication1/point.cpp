
#include "point.h"
#include <stdio.h>  // Standard Input Output -> printf()
#include <stdlib.h> // Standard Librray C -> free()

// Function to initialize a Point object with given coordinates
void initPoint(struct Point* point, int x, int y) {
    point->x = x;
    point->y = y;
}

// Function to print the coordinates of a Point object
void printPoint(struct Point* point) {
    printf("Point: (%d, %d)\n", point->x, point->y);
}

// Function to perform cleanup for a Point object
void cleanupPoint(struct Point* point) {
    // Free dynamically allocated memory for the Point object
    // In this example, we assume the Point object was dynamically allocated
    free(point);
}
