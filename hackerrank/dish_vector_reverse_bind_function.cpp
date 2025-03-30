/*
You are a waiter at a party. There is a pile of numbered plates. Create an empty  array. At each iteration, , remove each plate from the top of the stack in order. Determine if the number on the plate is evenly divisible by the  prime number. If it is, stack it in pile . Otherwise, stack it in stack . Store the values in  from top to bottom in . In the next iteration, do the same with the values in stack . Once the required number of iterations is complete, store the remaining values in  in , again from top to bottom. Return the  array.

Example



An abbreviated list of primes is . Stack the plates in reverse order.



Begin iterations. On the first iteration, check if items are divisible by .


Move  elements to .


On the second iteration, test if  elements are divisible by .


Move  elmements to .


And on the third iteration, test if  elements are divisible by .


Move  elmements to .


All iterations are complete, so move the remaining elements in , from top to bottom, to .

. Return this list.

Function Description

Complete the waiter function in the editor below.

waiter has the following parameters:

int number[n]: the numbers on the plates
int q: the number of iterations
Returns

int[n]: the numbers on the plates after processing
Input Format

The first line contains two space separated integers,  and .
The next line contains  space separated integers representing the initial pile of plates, i.e., .

Constraints




Sample Input 0

5 1
3 4 7 6 5
Sample Output 0

4
6
3
7
5
Explanation 0

Initially:

 = [3, 4, 7, 6, 5]<-TOP

After 1 iteration (divide by 2, the 1st prime number):

 = [5, 7, 3]<-TOP

 = [6, 4]<-TOP

Move  elements to .


All iterations are complete, so move  elements to .

.

Sample Input 1

5 2
3 3 4 4 9
Sample Output 1

4
4
9
3
3
Explanation 1

Initially:

 = [3, 3, 4, 4, 9]<-TOP

After  iteration (divide by 2):

 = [9, 3, 3]<-TOP

 = [4, 4]<-TOP

Move  to .


After  iteration (divide by 3):

 = []<- TOP

 = [3, 3, 9]<-TOP

Move  elements to .


There are no values remaining in .
*/

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

bool check_prime(int n) {
  bool is_prime = true;
  if (n == 0 || n == 1) {
    is_prime = false;
  }

  for (int i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      is_prime = false;
      break;
    }
  }
  return is_prime;
}

bool IsDivisible (int d, int i) {
  return ((i%d)==0);
}

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> waiter(vector<int> number, int q) {

    int prime = 2;
    vector<int> answers;
    vector<int> b;
    for (int round=0; round<q; round++) {
        while (!check_prime(prime))
            prime++;

        function<bool(int)> divtest = bind(IsDivisible, prime, placeholders::_1);
     
        for (auto i : number) {
            if (divtest(i))
                answers.emplace_back(i);
            else b.emplace_back(i);
        }
        
        reverse(b.begin(), b.end());
        number = b;
        b = vector<int>();
        prime++;
    }
       
    reverse(number.begin(), number.end());
    for (auto i : number) 
        answers.emplace_back(i);
    
    return answers;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
