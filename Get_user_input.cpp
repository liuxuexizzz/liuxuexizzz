#include "Get_user_input.h"
#include <iostream>
#include <limits>



// Function to get a double input from the user
double getDoubleInput() {
    double input;
    std::cin >> input;

    // Validate the input
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input. Please enter a valid double value.\n";
        return getDoubleInput(); // Recursively call until valid input
    }
    return input;
}



// Function to get an integer input from the user
int getIntInput() {
    int input;
    std::cin >> input;

    // Validate the input
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
        std::cout << "Invalid input. Please enter a valid integer.\n";
        return getIntInput(); // Recursively call until valid input
    }
    return input;
}



// Function to get a string input from the user
std::string getStringInput() {
    std::string input;

    // Clear the buffer if it's already in an error state
    if (std::cin.fail()) {
        std::cin.clear(); // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore invalid input
    }

    std::cout << "Please enter a string: ";
    std::getline(std::cin, input); // Read the entire line

    // Validate empty input
    if (input.empty()) {
        std::cout << "Input cannot be empty. Please try again.\n";
        return getStringInput(); // Recursively call until valid input
    }

    return input;
}



// Function to get a single character input from the user
char getCharInput() {
    char input;
    std::cin >> input; // Read a single character
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer
    return input;
}