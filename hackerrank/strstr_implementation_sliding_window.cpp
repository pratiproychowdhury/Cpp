#include <iostream>
#include <cstring>

const char* my_strstr(const char* text, const char* pattern) {
    if (!*pattern) return text;

    int tlen = std::strlen(text);
    int plen = std::strlen(pattern);

    if (plen > tlen) return nullptr;

    for (int i = 0; i <= tlen - plen; ++i) {
        int j = 0;
        while (j < plen && text[i + j] == pattern[j]) {
            ++j;
        }
        if (j == plen) return text + i;
    }

    return nullptr;
}

int main() {
    const char* text = "hello beautiful world";
    const char* pattern = "beautiful";

    const char* found = my_strstr(text, pattern);
    if (found)
        std::cout << "Found at: " << found << "\n";
    else
        std::cout << "Not found.\n";

    return 0;
}
