/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

class Solution {
public:

    static bool srt_interval(vector<int> a, vector<int> b) {
        if (a[0] < b[0])
            return true;
        else
            return false;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int ptr = 0;
        int length = intervals.size();

        sort(intervals.begin(), intervals.end(), srt_interval);
        while (ptr < length-1) {
            if (intervals[ptr][1] >= intervals[ptr+1][0]) {
                intervals[ptr][0] = min(intervals[ptr][0], intervals[ptr+1][0]);
                intervals[ptr][1] = max(intervals[ptr][1], intervals[ptr+1][1]);
                vector<vector<int>>::iterator x = intervals.begin()+ptr+1;
                intervals.erase(x);
                length--;
            }
            else
                ptr++;
        }
        return intervals;
    }
};
