#include <fstream>
#include <string>

void writeToFile(std::string content, std::string filepath) {
    std::ofstream file(filepath, std::ios::out);
    if (file.is_open()) {
        file << content;
    }
}

std::string readFromFile (std::string filepath) { // Fixed multiline input (actually most of them are) std::string
    std::ifstream file(filepath);
    if (file.is_open()) {
        std::string content = "";
        std::string line;
        while (std::getline(file, line)) content += line + "\n";
        return content;
    }
    return "Wrong filepath or file not found.";
}


// #include <iostream>
// int32_t main () {
//     std::cout << readFromFile("response.txt");
// }