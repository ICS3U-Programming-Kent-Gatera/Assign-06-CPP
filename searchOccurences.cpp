// Copyright (c) 2022 Kent Gatera All rights reserved.
// .
// Created by: Kent Gatera
// Date: Dec 20, 2022
// This program searches for a user query within a list
// and displays its position.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> getVectorFromUserUsingSplit() {
    // A vector is a dynamic array of sorts.
    std::vector<std::string> result;

    std::cout << "Enter a list of strings separated by commas: ";
    // Getting input.
    std::string input;
    std::getline(std::cin, input);

    std::string currentString;
    for (char c : input) {
        if (c == ',') {
        // If the for in loop finds a comma.
        // It is gonna assign whatever it found upto that point to a vector.
            result.push_back(currentString);
            currentString.clear();
        // If the character is not a comma, you add it a string.
        } else {
            currentString += c;
        }
    }
    // This is in case there is a word in the userInput,
    // but no comma to trigger the assignment to the list.
    if (!currentString.empty()) {
        result.push_back(currentString);
    }

    return result;
}

std::vector<int> findOccurrences
(const std::vector<std::string>& inputVector, const std::string& searchQuery) {
    std::vector<int> result;
    // Stripping / trimming all of the empty spaces
    // Putting it all in the same case for comparison.
    for (int i = 0; i < inputVector.size(); i++) {
        std::string currentString = inputVector[i];
        currentString.erase(std::remove_if(currentString.begin(),
        currentString.end(), isspace), currentString.end());
        std::transform(currentString.begin(), currentString.end(),
        currentString.begin(), ::tolower);
        // Making a copy since we're passing by reference.
        std::string searchQueryCopy = searchQuery;
        searchQueryCopy.erase(std::remove_if(searchQueryCopy.begin(),
        searchQueryCopy.end(), isspace), searchQueryCopy.end());
        std::transform(searchQueryCopy.begin(), searchQueryCopy.end(),
        searchQueryCopy.begin(), ::tolower);
        // Getting finding out how big the list of occurrences is.
        if (currentString == searchQueryCopy) {
            result.push_back(i);
        }
    }

    return result;
}


int main() {
    std::vector<std::string> userInput = getVectorFromUserUsingSplit();

    std::string userSearchQuery;
    std::cout << "Enter a search query: ";
    std::cin >> userSearchQuery;

    std::vector<int> indices = findOccurrences(userInput, userSearchQuery);
    // Since I passed by reference, I don't need
    if (indices.empty()) {
        std::cout << "The search query '" <<
        userSearchQuery << "' was not found in the input vector." << std::endl;
    } else {
        std::cout << "The search query '" <<
        userSearchQuery << "' was found " <<
        indices.size() <<
        " time(s) in the input vector at the following indices: " << std::endl;

        for (int index : indices) {
            std::cout << index << " ";
        }

        std::cout << std::endl;
    }
}
