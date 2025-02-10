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

int main(int argc, char* argv[]) {
    // Check if there are any command-line arguments (at least one)
    if (argc < 2) {
        std::cerr << "Error: Please provide a series of integers as command-line arguments." << std::endl;
        return 1;
    }
    
    // Create a vector to hold the input integers
    std::vector<int> series;

    // Convert the command-line arguments to integers and store them in the series vector
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);  // Convert string to integer
        series.push_back(num);
    }

    // Ensure the series is sorted (it should be sorted for correct sum calculation)
    std::sort(series.begin(), series.end());

    // Compute the missing element
    int missingElement = findMissingElement(series);

    // Output the missing element to a file
    std::ofstream outFile("missing_element.txt");
    if (!outFile) {
        std::cerr << "Error: Could not open the file for writing." << std::endl;
        return 1;
    }

    outFile << "The missing element is: " << missingElement << std::endl;
    outFile.close();

    std::cout << "The missing element has been written to 'missing_element.txt'." << std::endl;

    return 0;
}
