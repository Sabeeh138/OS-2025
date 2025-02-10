#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>  // For atoi()

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
        return 1;
    }

    std::vector<int> numbers;

    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);  // Convert string to integer
        numbers.push_back(num);
    }

    std::sort(numbers.begin(), numbers.end());

    std::cout << "Sorted integers: ";
    for (const int& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
