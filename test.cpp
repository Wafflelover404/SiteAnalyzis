#include "curlClient.cpp"
#include <string>

int32_t main() {
    std::string url;
    std::cin >> url;
    std::cout << parseData(url);
}