#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'numberOfItems' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER_ARRAY startIndices
 *  3. INTEGER_ARRAY endIndices
 */

vector<int> numberOfItems(string s, vector<int> startIndices, vector<int> endIndices) {
    
    vector<int> results;
    results.reserve(startIndices.size());
    //vector<char> svec(s.begin(), s.end());
    for (int x=0; x<startIndices.size(); x++) {
        int enclosed = 0;
        int counting = 0;
        bool closed = false;
        for (int pos=startIndices[x]-1; pos<endIndices[x]; pos++) {
            if (s[pos] == '*') {
                if (closed)
                    counting++;
            }
            // it is a '|'
            else {
                if (!closed)
                    closed = true;
                else {
                    enclosed += counting;
                    counting = 0;
                }
            }
        }
        results.emplace_back(enclosed);    
    }
    
    return results;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string startIndices_count_temp;
    getline(cin, startIndices_count_temp);

    int startIndices_count = stoi(ltrim(rtrim(startIndices_count_temp)));

    vector<int> startIndices(startIndices_count);

    for (int i = 0; i < startIndices_count; i++) {
        string startIndices_item_temp;
        getline(cin, startIndices_item_temp);

        int startIndices_item = stoi(ltrim(rtrim(startIndices_item_temp)));

        startIndices[i] = startIndices_item;
    }

    string endIndices_count_temp;
    getline(cin, endIndices_count_temp);

    int endIndices_count = stoi(ltrim(rtrim(endIndices_count_temp)));

    vector<int> endIndices(endIndices_count);

    for (int i = 0; i < endIndices_count; i++) {
        string endIndices_item_temp;
        getline(cin, endIndices_item_temp);

        int endIndices_item = stoi(ltrim(rtrim(endIndices_item_temp)));

        endIndices[i] = endIndices_item;
    }

    vector<int> result = numberOfItems(s, startIndices, endIndices);

    for (int i = 0; i < result.size(); i++) {
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
