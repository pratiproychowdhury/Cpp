/*
You can perform the following operations on the string, :

Capitalize zero or more of 's lowercase letters.
Delete all of the remaining lowercase letters in .
Given two strings,  and , determine if it's possible to make  equal to  as described. If so, print YES on a new line. Otherwise, print NO.

For example, given  and , in  we can convert  and delete  to match . If  and , matching is not possible because letters may only be capitalized or discarded, not changed.

Function Description

Complete the function  in the editor below. It must return either  or .

abbreviation has the following parameter(s):

a: the string to modify
b: the string to match
Input Format

The first line contains a single integer , the number of queries.

Each of the next  pairs of lines is as follows:
- The first line of each query contains a single string, .
- The second line of each query contains a single string, .

Constraints

String  consists only of uppercase and lowercase English letters, ascii[A-Za-z].
String  consists only of uppercase English letters, ascii[A-Z].
Output Format

For each query, print YES on a new line if it's possible to make string  equal to string . Otherwise, print NO.

Sample Input

1
daBcd
ABC
Sample Output

YES
Explanation

image

We have  daBcd and  ABC. We perform the following operation:

Capitalize the letters a and c in  so that  dABCd.
Delete all the remaining lowercase letters in  so that  ABC.
Because we were able to successfully convert  to , we print YES on a new line.
*/

/*
 * Complete the 'abbreviation' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING a
 *  2. STRING b
 */

string abbreviation(string a, string b) {

    auto lettertomatch = b.begin();
    auto letterptr = a.begin();
    while ( (lettertomatch != b.end()) && (letterptr != a.end()) ) {
        cout << "Comparing " << *letterptr << " to " << *lettertomatch << endl;
        if ( (*lettertomatch == *letterptr) || (*lettertomatch == toupper(*letterptr)) ) {
            lettertomatch++;
            letterptr++;
            cout << "Match" << endl;
        }
        else if (islower(*letterptr)) {
            letterptr++;
            cout << "Discarding" << endl;
        }
        else {
            cout << "Failed" << endl;
            return "NO";
        }
        
        if ( (letterptr == a.end()) && (lettertomatch != b.end()) )
            return "NO";
    }

    cout << "Out of the loop" << endl;
    if (lettertomatch == b.end()) {
        cout << "Eating rest of a" << endl;
        while (letterptr != a.end()) {
            if (islower(*letterptr))
                letterptr++;
            else return "NO";
        }
        if ((letterptr == a.end()))
            return "YES";
    }
        
    return "NO";
}
