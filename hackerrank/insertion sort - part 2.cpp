/*
In Insertion Sort Part 1, you inserted one element into an array at its correct sorted position. Using the same approach repeatedly, can you sort an entire array?

Guideline: You already can place an element into a sorted array. How can you use that code to build up a sorted array, one element at a time? Note that in the first step, when you consider an array with just the first element, it is already sorted since there's nothing to compare it to.

In this challenge, print the array after each iteration of the insertion sort, i.e., whenever the next element has been inserted at its correct position. Since the array composed of just the first element is already sorted, begin printing after placing the second element.

Example.



Working from left to right, we get the following output:

3 4 7 5 6 2 1
3 4 7 5 6 2 1
3 4 5 7 6 2 1
3 4 5 6 7 2 1
2 3 4 5 6 7 1
1 2 3 4 5 6 7
Function Description

Complete the insertionSort2 function in the editor below.

insertionSort2 has the following parameter(s):

int n: the length of 
int arr[n]: an array of integers
Prints

At each iteration, print the array as space-separated integers on its own line.

Input Format

The first line contains an integer, , the size of .
The next line contains  space-separated integers .

Constraints



Output Format

Print the entire array on a new line at every iteration.

Sample Input

STDIN           Function
-----           --------
6               n = 6
1 4 3 5 6 2     arr = [1, 4, 3, 5, 6, 2]
Sample Output

1 4 3 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 3 4 5 6 2 
1 2 3 4 5 6 
Explanation

Skip testing  against itself at position . It is sorted.
Test position  against position : , no more to check, no change.
Print 
Test position  against positions  and :

, new position may be . Keep checking.
, so insert  at position  and move others to the right.
Print 
Test position  against positions  (as necessary): no change.
Print 
Test position  against positions : no change.
Print 
Test position  against positions , insert  at position  and move others to the right.
Print 
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void prt(int number) {
    cout << number << ' ';
}

// Complete the insertionSort2 function below.
void insertionSort2(int n, vector<int> arr) {

    for (vector<int>::iterator i=arr.begin()+1; i<arr.end(); i++) {
        for (vector<int>::iterator a=arr.begin(); a<i; a++)
            if (*a>*i) {
                int data = *i;
                arr.erase(i);           
                arr.insert(a, 1, data);
            }
        for_each(arr.begin(), arr.end(), prt);
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort2(n, arr);

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
