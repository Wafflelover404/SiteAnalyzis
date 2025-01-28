#include <iostream>
#include <ctime> 

const char* timeGet() {
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime); 
}
// Usage - std::cout << timeGet(); 

int main() {
    
}
