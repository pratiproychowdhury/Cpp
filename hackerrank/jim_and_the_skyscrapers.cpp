/*
Jim has invented a new flying object called HZ42. HZ42 is like a broom and can only fly horizontally, independent of the environment. One day, Jim started his flight from Dubai's highest skyscraper, traveled some distance and landed on another skyscraper of same height! So much fun! But unfortunately, new skyscrapers have been built recently.

Let us describe the problem in one dimensional space. We have in total  skyscrapers aligned from left to right. The th skyscraper has a height of . A flying route can be described as  with , which means, Jim starts his HZ42 at the top of the skyscraper  and lands on the skyscraper . Since HZ42 can only fly horizontally, Jim will remain at the height  only. Thus the path  can be valid, only if each of the skyscrapers  is not strictly greater than  and if the height of the skyscraper he starts from and arrives on have the same height. Formally,  is valid iff  and .

Help Jim in counting the number of valid paths represented by ordered pairs .

Input Format

The first line contains , the number of skyscrapers. The next line contains  space separated integers representing the heights of the skyscrapers.

Output Format

Print an integer that denotes the number of valid routes.

Constraints

 and no skyscraper will have height greater than  and less than .

Sample Input #00

6
3 2 1 2 3 3
Sample Output #00

8
Sample Input #01

3
1 1000 1
Sample Output #01

0
Explanation

First testcase: (1, 5), (1, 6) (5, 6) and (2, 4) and the routes in the opposite directions are the only valid routes.

Second testcase: (1, 3) and (3, 1) could have been valid, if there wasn't a big skyscraper with height 1000 between them.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int solve(vector<int> arr) {

    int paths=0;
    int vecsiz = arr.size();

    for (int i=0; i<vecsiz; i++) {
        int j = i+1;
        int height = arr[i];
        while ((j<vecsiz) && (arr[j]<=height)) {
            if (arr[j]==height)
                paths++;
            j++;
        }
    }

    return paths*2;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
        int arr_item = stoi(arr_temp[arr_itr]);

        arr[arr_itr] = arr_item;
    }

    int result = solve(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
