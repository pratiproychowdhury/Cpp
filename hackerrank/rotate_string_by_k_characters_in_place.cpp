/*
Reverse the entire string
Reverse the first k characters
Reverse the remaining n - k characters
*/

#include <iostream>
#include <string>
#include <algorithm>

void rotate_right(std::string& str, int k) {
    int n = str.size();
    if (n == 0) return;

    k = k % n;  // In case k > n

    std::reverse(str.begin(), str.end());

    std::reverse(str.begin(), str.begin() + k);

    std::reverse(str.begin() + k, str.end());
}

int main() {
    std::string s = "abcdef";
    int k = 2;

    rotate_right(s, k);
    std::cout << "Rotated string: " << s << std::endl;

    return 0;
}
