#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getHeaviestPackage' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY packageWeights as parameter.
 */

long getHeaviestPackage(vector<int> packageWeights) {

  vector<long> newpacks;
  newpacks.push_back(packageWeights.back());
  for (int package=packageWeights.size()-2; package>-1; package--) {
    if (packageWeights[package] < newpacks.back()) {
      long mergedpack = packageWeights[package] + newpacks.back();
      newpacks.pop_back();  
      newpacks.push_back(mergedpack);
    }
    else {
      newpacks.push_back(packageWeights[package]);
    }
  }
  return *max_element(newpacks.begin(), newpacks.end());
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string packageWeights_count_temp;
    getline(cin, packageWeights_count_temp);

    int packageWeights_count = stoi(ltrim(rtrim(packageWeights_count_temp)));

    vector<int> packageWeights(packageWeights_count);

    for (int i = 0; i < packageWeights_count; i++) {
        string packageWeights_item_temp;
        getline(cin, packageWeights_item_temp);

        int packageWeights_item = stoi(ltrim(rtrim(packageWeights_item_temp)));

        packageWeights[i] = packageWeights_item;
    }

    long result = getHeaviestPackage(packageWeights);

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
