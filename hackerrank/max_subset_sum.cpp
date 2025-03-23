/*
Given an array of integers, find the subset of non-adjacent elements with the maximum sum. Calculate the sum of that subset. It is possible that the maximum sum is , the case when all elements are negative.

Example

The following subsets with more than  element exist. These exclude the empty subset and single element subsets which are also valid.

Subset      Sum
[-2, 3, 5]   6
[-2, 3]      1
[-2, -4]    -6
[-2, 5]      3
[1, -4]     -3
[1, 5]       6
[3, 5]       8
The maximum subset sum is . Note that any individual element is a subset as well.


In this case, it is best to choose no element: return .

Function Description

Complete the  function in the editor below.

maxSubsetSum has the following parameter(s):

int arr[n]: an array of integers
Returns
- int: the maximum subset sum

Input Format

The first line contains an integer, .
The second line contains  space-separated integers .

Constraints

Sample Input 0

5
3 7 4 6 5
Sample Output 0

13
Explanation 0

Our possible subsets are  and . The largest subset sum is  from subset 

Sample Input 1

5
2 1 5 8 4
Sample Output 1

11
Explanation 1

Our subsets are  and . The maximum subset sum is  from the first subset listed.

Sample Input 2

5
3 5 -7 8 10
Sample Output 2

15
Explanation 2

Our subsets are  and . The maximum subset sum is  from the fifth subset listed.
*/

/*
 * Complete the 'maxSubsetSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int maxSubsetSum(vector<int> arr) {
    vector<int> total(arr.size(), 0);
    total[0] = max(arr[0], 0);
    total[1] = max(arr[0], arr[1]);
    for (size_t x=2; x<arr.size(); x++)
        total[x] = max(max(total[x-1], total[x-2]+arr[x]), arr[x]);

    return total.back();
}
