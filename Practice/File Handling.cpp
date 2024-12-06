#include <iostream>
#include <fstream> // For file handling

int main() {
    // Step 1: Writing to a file
    std::ofstream outFile("example.txt"); // Create and open a file
    if (outFile.is_open()) {
        outFile << "Hello, this is a sample text written to the file.\n";
        outFile << "C++ file handling is simple and efficient.\n";
        outFile.close(); // Close the file after writing
        std::cout << "Data written to the file successfully.\n";
    } else {
        std::cerr << "Error: Unable to open the file for writing.\n";
        return 1;
    }

    // Step 2: Reading from the file
    std::ifstream inFile("example.txt"); // Open the same file for reading
    if (inFile.is_open()) {
        std::string line;
        std::cout << "Contents of the file: \n";
        while (std::getline(inFile, line)) { // Read line by line
            std::cout << line << "\n";
        }
        inFile.close(); // Close the file after reading
    } else {
        std::cerr << "Error: Unable to open the file for reading.\n";
        return 1;
    }

    return 0;
}
