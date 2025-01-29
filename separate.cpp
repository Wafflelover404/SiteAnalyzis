#include <iostream>
#include <string>
#include <vector>
#include "writeToFile.cpp"

std::vector <std::string> getTagStructure (std::string html) {
    if (html.empty ()) return {};
    std::vector <std::string> tagStructure;
    for (int32_t it = 0; it < html.length(); ++it) {
        if (html[it] == '<') {
            std::string tag = "";
            int32_t j = it;
            do {
                tag += html[j];
                j ++;
                if (html[j] == ' ') {tag+= '>'; break;}
            } while (html[j - 1] != '>');
            tagStructure.push_back(tag);
        }
    }
    return tagStructure;
} 

void printTagStructure (std::vector <std::string> tagStructure) {
    if (tagStructure.empty()) return;
    int32_t tabs = 0;
    for (std::string tag : tagStructure) {
        std::string currentTagName = "";
        if (tag[1] == '/') {
            for (int it = 2; tag[it] != '>'; ++it) {
                currentTagName += tag[it];
            }
        }
        else {
            for (int it = 1; tag[it] != '>'; ++it) {
                currentTagName += tag[it];
            }
        }

        if (tag.length() >= 2 && tag[1] == '/') {
            tabs -= 2;
        } else {
            tabs += 2;
        }

        for (int i = 0; i < tabs; ++i) {
            std::cout << ' ';
        }
        std::cout << tag << '\n';
    }
}

int32_t main () {
    std::string htmlExample = readFromFile("./response.txt");
    std::vector <std::string> tags = getTagStructure(htmlExample);
    // for (std::string tag : tags) {
    //     std::cout << tag << '\n';
    // }
    printTagStructure(tags);
}