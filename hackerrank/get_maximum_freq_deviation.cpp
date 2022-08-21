#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'getMaxFreqDeviation' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool nonZero(int i) {
  
  return (i>0);  
}

int getMaxFreqDeviation(string s) {

  int deviation = 0;
  int length = s.size();
  
  // First find max deviation of whole string
  // Then check all possible substrings with length from s.size()-1 down to deviation+3
  while (length > deviation+2) {

    for (int start=0; start<s.size()-length+1; start++) {

      vector<int> freq(26);
      
      for (int i=start; i<start+length; i++)
        freq[s[i]-'a']++;
      
      int maxfreq = *max_element(freq.begin(),freq.end());
      if (maxfreq > deviation+1) {
        int minfreq = maxfreq;
        for (int i=0; i<26; i++)
          if (freq[i] && (freq[i]<minfreq))
            minfreq = freq[i];
        int thisdev = maxfreq-minfreq;
        deviation = max(deviation, thisdev);
      }
    }
    length--;
  }
  return deviation;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int result = getMaxFreqDeviation(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
