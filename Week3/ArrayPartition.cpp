/*
Problem:

 Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.

Example 1:

Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).

    n is a positive integer, which is in the range of [1, 10000].
    All the integers in the array will be in the range of [-10000, 10000].
    
 According to LeetCode:
  Runtime: 68 ms, faster than 91.35% of C++ online submissions for Array Partition I.
  Memory Usage: 11.3 MB, less than 25.39% of C++ online submissions for Array Partition I.

*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //Sort the array from smallerst to highest then add
        //every even index value to the sum
        if(nums.size()==0)
        {
            return 0;
        }
        if(nums.size()==2)
        {
            return (min(nums[0],nums[1]));
        }
        sort(nums.begin(), nums.end());
        int sum{0};
        for(int index=0;index<nums.size();index+=2)
        {
             sum+=  nums[index]; 
        }
        return sum;
            
            
        
    }
};