/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]

Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Explanation:

There is no string in strs that can be rearranged to form "bat".
The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.
Example 2:

Input: strs = [""]

Output: [[""]]

Example 3:

Input: strs = ["a"]

Output: [["a"]]

 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<multiset<char>, vector<string>> catalog;

        for (auto word : strs) {
            multiset<char> x;
            for (char a : word) {
                x.emplace(a);
            }

            auto ptr = catalog.find(x);
            if (ptr == catalog.end())
                catalog.emplace(x, vector<string>(1,word));
            else {
                vector<string> temp = ptr->second;
                temp.emplace_back(word);
                catalog.erase(x);
                catalog.emplace(x, temp);
            }
        }

        vector<vector<string>> answer;
        for (auto entry : catalog)
            answer.emplace_back(entry.second);

        return answer;
    }
};
