#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'countGroups' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING_ARRAY related as parameter.
 */

int countGroups(vector<string> related) {

    int groups = (*related.begin()).length();
    int ones = 0;

    for (auto str : related) {
        ones += count(str.begin(), str.end(), '1');
    }
    return groups - ((ones-groups)/2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string related_count_temp;
    getline(cin, related_count_temp);

    int related_count = stoi(ltrim(rtrim(related_count_temp)));

    vector<string> related(related_count);

    for (int i = 0; i < related_count; i++) {
        string related_item;
        getline(cin, related_item);

        related[i] = related_item;
    }

    int result = countGroups(related);

    fout << result << "\n";

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
