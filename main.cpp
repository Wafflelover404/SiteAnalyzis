#include <iostream>
#include <string>
#include <ctime>
#include "curlClient.cpp" // for site curl 
#include "writeToFile.cpp" // for working with file

char* timeGet() {
    time_t rawtime;
    time(&rawtime);
    return ctime(&rawtime); 
}
// Usage - std::cout << timeGet(); 

enum responseCodes {
    Fine,
    Internet,
    Typo
};

std::string errorCodeTranslation[] = {
    "Response recieved",
    "Couldn't connect. Check you internet connection",
    "Invalid input. Please try again"
};

class response {
    public:
        std::string getCode () {return errorCodeTranslation[responseCode];}
        void setCode (responseCodes code) {responseCode = code;}

        void setTime () {this->lastEntryTime = timeGet();}
        char* getEntryTime () {return this->lastEntryTime;}

        response (responseCodes respCode, std::string message, std::string filepath) {
            responseCode = respCode;
            lastEntryTime = timeGet();
            this->responseContent = message;
            this->filepath = filepath;
        }

        void loadFromFile () {
            readFromFile(this->filepath);
        }

        void saveToFile () {
            writeToFile(this->responseContent, this->filepath);
        }

    private:
        responseCodes responseCode;
        char* lastEntryTime;
        std::string responseContent;
        std::string filepath;
};



int32_t main() {
    std::cout << "Enter URL to parse ~> ";
    std::string url;
    std::cin >> url;
    std::string content = parseData(url);

    responseCodes code = content.empty() ? Internet : Fine;
    response resp(code, content, "response.txt");

    std::cout << resp.getCode() << std::endl;
    if (resp.getCode() != "Response recieved") return 0; 
    std::cout << "Last entry time: " << resp.getEntryTime() << std::endl;
    resp.saveToFile();
    
    return 0;
}