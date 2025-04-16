#include <algorithm> // std::swap

void reverseString(std::string& str) {
    size_t left = 0;
    size_t right = str.length() - 1;

    while (left < right) {
        std::swap(str[left], str[right]);
        ++left;
        --right;
    }
}
