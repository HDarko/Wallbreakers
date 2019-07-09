/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Notes:
Sort the array by the first value in a pair then,  similiar to the minumum number of arrows question done this week.
as long as the start point of a interval is smaller than the end point of our current interval then we merge the two. 

Accordingt to LeetCode for my solution:

Runtime: 12 ms, faster than 99.36% of C++ online submissions for Merge Intervals.
Memory Usage: 12.2 MB, less than 50.33% of C++ online submissions for Merge Intervals.
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         vector<vector<int>>  mergedIntervals;
        if(intervals.empty()){return mergedIntervals;}
        //Sort by the stars of the intervals in ascending order
        sort(intervals.begin(), intervals.end(), [](auto & left, auto& right){ return left[0]< right[0];});
        //Start with the lowest interval 
        auto currentInterval=intervals[0];
        for(int index=1; index<intervals.size(); index++)
        {
            //If the start of next interval is less or equal than current interval endpoint
            //we merge the two
            if(intervals[index][0]<=currentInterval[1])
            {
                currentInterval[1]=max(intervals[index][1], currentInterval[1]);
            }
            else
                //since we have sorted the array by start points we are done merging for current interval
            {
               mergedIntervals.push_back(currentInterval);
                currentInterval=intervals[index];
            }
        }
        //Need to push back the last interval into the vector
        mergedIntervals.push_back(currentInterval);
        return mergedIntervals; 
    }
};
