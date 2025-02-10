#include <iostream>
#include <cstdlib>  // For atoi()

int main(int argc, char* argv[]) {
    // Check if at least one integer is provided
    if (argc < 2) {
        std::cerr << "Error: Please provide at least one integer as a command-line argument." << std::endl;
        return 1;
    }

    // Array to store the integers
    int* numbers = new int[argc - 1];

    // Convert command-line arguments to integers and store them in the array
    for (int i = 1; i < argc; ++i) {
        // Check if the argument is a valid integer
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            if (!isdigit(argv[i][j]) && !(j == 0 && argv[i][j] == '-')) {
                std::cerr << "Error: Invalid input. Argument " << argv[i] << " is not a valid integer." << std::endl;
                delete[] numbers;
                return 1;
            }
        }
        numbers[i - 1] = std::atoi(argv[i]);  // Convert string to integer
    }

    // Calculate the sum and average
    int sum = 0;
    for (int i = 0; i < argc - 1; ++i) {
        sum += numbers[i];
    }

    double average = static_cast<double>(sum) / (argc - 1);

    // Print the results
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Average: " << average << std::endl;

    // Free the allocated memory
    delete[] numbers;

    return 0;
}
