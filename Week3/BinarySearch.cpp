/*
Problem:
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.


Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1

 

    You may assume that all elements in nums are unique.
    n will be in the range [1, 10000].
    The value of each element in nums will be in the range [-9999, 9999].

According to LeetCode for my solution:
Runtime: 64 ms, faster than 14.04% of C++ online submissions for Binary Search.
Memory Usage: 10.8 MB, less than 84.73% of C++ online submissions for Binary Search.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if( nums.empty()){return -1;}
        //Initiall we start outside the actual indexs themselves
        int lowerBoundIndex=-1;
        int upperBoundIndex=nums.size();
        int middleIndex{0};
        int middleValue{0};
        //As long as there is an index inbetween lower and Uperbounds
        //we must still search
        while((lowerBoundIndex+1)!=upperBoundIndex)
        {
            //We find the index in the middle, we use integer division
            // mdiddleIndex is the difference added to the current lowerbound Index
            middleIndex= lowerBoundIndex+ ((upperBoundIndex-lowerBoundIndex)/2);
            //check if the value at the middle is greater, lesser or equal to our target
            middleValue= nums[middleIndex];
            if (middleValue==target)
            {
                return middleIndex;
            }
            //If middleValue is  smaller than our target then our target must be right
            //of this middle index so update lowerbound
            if(middleValue<target)
            {
                lowerBoundIndex=middleIndex;
            }
             //If middleValue is larger than our target then our target must be left
            //of this middle index so update upperbound
            else
            {
                upperBoundIndex=middleIndex;
            }
            
        }
        return -1;
        
    }
};
