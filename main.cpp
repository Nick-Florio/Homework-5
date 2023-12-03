//
//  main.cpp
//  Homework 5
//
//  Created by Nicholas Florio on 11/19/23.
//
// main.cpp

// main.cpp
#include <iostream>
#include "Dogs.hpp"

int main() {
    try {
        Dogs dogPopulation("/Users/nick/Desktop/STAC Fall 2023/CS 250/Homework 5/dogs.txt");
        
        int choice;
        do {
            std::cout << "\nDog Population Explorer Menu:\n";
            std::cout << "1. See the total number of dogs in the world\n";
            std::cout << "2. Input a country name to find out how many dogs are in that country\n";
            std::cout << "3. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    std::cout << "Total number of dogs in the world: " << dogPopulation.getTotalDogs() << std::endl;
                    break;
                    
                case 2: {
                    std::string country;
                    std::cout << "Enter the country name: ";
                    std::cin >> country;
                    
                    int dogsInCountry = dogPopulation.getDogsInCountry(country);
                    std::cout << "Number of dogs in " << country << ": " << dogsInCountry << std::endl;
                    break;
                }
                    
                case 3:
                    std::cout << "Exiting program.\n";
                    break;
                    
                default:
                    std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
