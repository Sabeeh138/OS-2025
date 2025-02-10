#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <algorithm>

int findMissingElement(const std::vector<int>& series) {
    int n = series.size() + 1;  // The number of elements should be n+1 (including the missing one)
    
    // Find the sum of the first n natural numbers using the formula: n * (n + 1) / 2
    int expectedSum = n * (n + 1) / 2;
    
    // Calculate the sum of the provided series
    int actualSum = 0;
    for (int num : series) {
        actualSum += num;
    }
    
    // The missing element is the difference between the expected and actual sums
    return expectedSum - actualSum;
}

int main() {
    // Open the file containing the series of integers
    std::ifstream inFile("input_series.txt");
    if (!inFile) {
        std::cerr << "Error: Could not open the file for reading." << std::endl;
        return 1;
    }

    // Create a vector to hold the integers
    std::vector<int> series;
    int num;
    
    // Read integers from the file and store them in the series vector
    while (inFile >> num) {
        series.push_back(num);
    }

    inFile.close(); // Close the input file

    // Sort the series (if not already sorted)
    std::sort(series.begin(), series.end());

    // Compute the missing element
    int missingElement = findMissingElement(series);

    // Output the missing element to a new file
    std::ofstream outFile("missing_element.txt");
    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return 1;
    }

    outFile << "The missing element is: " << missingElement << std::endl;
    outFile.close();  // Close the output file

    std::cout << "The missing element has been written to 'missing_element.txt'." << std::endl;

    return 0;
}
