/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        auto start = s.begin();

        while (start != s.end()) {
            set<char> letters;      
            auto ptr = start;
            int presentlen = 0;

            auto ret = letters.emplace(*ptr);
            while ((ret.second) && (ptr != s.end())) {
                presentlen++;
                ptr++;
                ret = letters.emplace(*ptr);
            }

            maxlen = max(maxlen, presentlen);
            start++;
        }
        return maxlen;
    }
};
