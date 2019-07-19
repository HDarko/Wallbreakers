/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

Note:

    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
    Could you do it in-place with O(1) extra space?
    
    According to LeetCode:
    Runtime: 220 ms, faster than 13.34% of C++ online submissions for Rotate Array.
Memory Usage: 9.8 MB, less than 6.49% of C++ online submissions for Rotate Array.

*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> numQueue;
        
        while(k>0 && (!nums.empty()))
        {
            numQueue.push(nums.back());
            nums.pop_back();
            k--;
        }
        while(!numQueue.empty())
        {
            nums.insert(nums.begin(), numQueue.front());
            numQueue.pop();
        }
        if (k>0)
        {
            rotate(nums,k);
        }
    }
};
