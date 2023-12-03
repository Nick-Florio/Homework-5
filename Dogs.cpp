//
//  Dogs.cpp
//  Homework 5
//
//  Created by Nicholas Florio on 11/19/23.
//
// Dogs.cpp
#include "Dogs.hpp"
#include <fstream>
#include <stdexcept>

Dogs::Dogs(const std::string& dataFileName) {
    std::ifstream dataFile(dataFileName);
    if (!dataFile.is_open()) {
        throw std::runtime_error("Unable to open data file.");
    }
    
    std::string country;
    int population;
    totalDogs = 0;
    
    while (dataFile >> country >> population) {
        dogPopulation[country] = population;
        totalDogs += population;
    }
    
    dataFile.close();
}

int Dogs::getTotalDogs() const {
    return totalDogs;
}

int Dogs::getDogsInCountry(const std::string& country) const {
    auto it = dogPopulation.find(country);
    if (it != dogPopulation.end()) {
        return it->second;
    } else {
        throw std::runtime_error("Country not found in the data.");
    }
}
