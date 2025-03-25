/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

class Solution {
public:
    unordered_map<char,std::string> numtoletter;
        
    void combinator(string digits, string prefix, vector<string>& combinations) {
        
        if (digits.length() == 1) {
            string letters = numtoletter[digits.at(0)];
            for (auto& letter : letters) {
                combinations.push_back(prefix+letter);     
            }
            return;
        }
        else {
            string newdigits = digits.substr(1);
            string letters = numtoletter[digits.at(0)];
            for (auto& letter : letters) {
                string newprefix = prefix+letter;
                combinator(newdigits, newprefix, combinations);     
            }            
        }
    }
    
    
    vector<string> letterCombinations(string digits) {
        this->numtoletter =
        {{'2',"abc"},
         {'3',"def"},
         {'4',"ghi"},
         {'5',"jkl"},
         {'6',"mno"},
         {'7',"pqrs"},
         {'8',"tuv"},
         {'9',"wxyz"}};
        
        vector<string> combinations;
        string empty;
        
        if (!digits.length())
            return combinations;
        
        combinator(digits, string(), combinations);
        return combinations;
    }
};
