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

  set<int> remainingpeople;
  int groups = 0;
  
  for (unsigned int i=0; i<related.size(); i++)
    remainingpeople.insert(i);
  
  while (!remainingpeople.empty()) {
    set<int>::iterator person = remainingpeople.begin();
    remainingpeople.erase(person);
    groups++;
    vector<int> friends(1, *person);
    while (!friends.empty()) {
      int thisfriend = friends.back();
      friends.pop_back();
      string hisfriends = related[thisfriend];
      for (unsigned int i=0; i<related.size(); i++) {  
        if ( (hisfriends[i]=='1') && (remainingpeople.find(i)!=remainingpeople.end()) ) {
          remainingpeople.erase(i);
          friends.push_back(i);
        }
      } 
    }  
  }
  return groups;
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
