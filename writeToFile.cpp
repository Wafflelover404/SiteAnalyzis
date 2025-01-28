#include <fstream>
#include <string>

void writeToFile(std::string content, std::string filepath) {
    std::ofstream file(filepath, std::ios::out);
    if (file.is_open()) {
        file << content;
    }
}

std::string readFromFile (std::string filepath) {
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::string content;
        std::getline(file, content);
        return content;
    }
    return "Wrong filepath or file not found.";
}


// #include <iostream>
// int32_t main () {
//     std::cout << readFromFile("write.txt");
// }