/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/

class Solution {
public:
    int stairs(int n, int pos, vector<int>& temp) {
        if (pos > n)
            return 0;
        else if (temp[n-pos] > -1)
            return temp[n-pos];        

        temp[n-pos] = stairs(n, pos+2, temp) + stairs(n, pos+1, temp);
        return temp[n-pos];
    }

    int climbStairs(int n) {
        vector<int> temp(n+1, -1);
        temp[0] = 1;
        temp[1] = 1;
        return stairs(n, 0, temp);
    }
};
