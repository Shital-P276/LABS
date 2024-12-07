#include <iostream>
#include <fstream>
#include <string>

struct Data {
    int id;
    char name[50];
};

void writeBinaryFile(const std::string& filename) {
    std::ofstream outFile(filename, std::ios::binary);
    if (outFile.is_open()) {
        Data data = {1, "John Doe"};
        outFile.write(reinterpret_cast<char*>(&data), sizeof(data));
        std::cout << "Data written to binary file successfully.\n";
        outFile.close();
    } else {
        std::cerr << "Error: Unable to open the binary file for writing.\n";
    }
}

void readBinaryFile(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (inFile.is_open()) {
        Data data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(data));
        if (inFile) {
            std::cout << "Data read from binary file:\n";
            std::cout << "ID: " << data.id << "\n";
            std::cout << "Name: " << data.name << "\n";
        } else {
            std::cerr << "Error: Could not read the binary file completely.\n";
        }
        inFile.close();
    } else {
        std::cerr << "Error: Unable to open the binary file for reading.\n";
    }
}

int main() {
    std::string filename = "data.bin";

    // Writing to a binary file
    writeBinaryFile(filename);

    // Reading from the binary file
    readBinaryFile(filename);

    return 0;
}
