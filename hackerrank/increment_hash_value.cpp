// https://stackoverflow.com/questions/261963/how-can-i-iterate-over-an-enum


#include <iostream>
#include <unordered_map>

int main()
{
	std::unordered_map<char,int> freq;
	std::string s = "ABCBADCA";

	for (const char &c: s) {
		freq[c]++;	// if this key does not exist, this creates and inserts with value zero
	}

	for (auto &e: freq) {
		std::cout << '{' << e.first << ", " << e.second << '}' << '\n';
	}

	return 0;
}
