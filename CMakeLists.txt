cmake_minimum_required(VERSION 3.10) 
project(curlTest)                 

# Find the cURL package
find_package(CURL REQUIRED)

# Add the executable target
add_executable(curl_papser main.cpp)    

# Link the cURL library to your executable
target_link_libraries(curl_parser PRIVATE CURL::libcurl)
