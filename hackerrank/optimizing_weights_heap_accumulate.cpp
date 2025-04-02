#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <queue>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minimalHeaviestSetA' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

vector<int> minimalHeaviestSetA(vector<int> arr) {

    priority_queue<int> items (arr.begin(), arr.end());
    long halfweight = accumulate(arr.begin(), arr.end(), 0) / 2;
    long totala = 0;
    vector<int> a;
    
    while (totala < halfweight) {
        int x = items.top();
        totala += x;
        a.emplace_back(x);
        items.pop();
    }
    
    reverse(a.begin(), a.end());
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    vector<int> result = minimalHeaviestSetA(arr);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
