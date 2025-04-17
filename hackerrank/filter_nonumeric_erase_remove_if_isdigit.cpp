#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int main() {
    std::string input = "abc123!@#456xyz";
    
    input.erase(std::remove_if(input.begin(), input.end(),
                               [](char c) { return !std::isdigit(static_cast<unsigned char>(c)); }),
                input.end());

    std::cout << "Filtered string: " << input << std::endl;
    return 0;
}
