/*
Problem
Given a non-empty array of integers, every element appears twice except for one. Find that single one.



Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
In order to find the single non repeating num in a vector on intergers.

Note:
Here is a trick:
 If you XOR a bit and 0 then you get 1
but XOR the same two bits and you get 0
so we gonna xor all the bits in the vector plus 0.

According to LeetCode:
Runtime: 12 ms, faster than 97.04% of C++ online submissions for Single Number.
Memory Usage: 9.7 MB, less than 59.59% of C++ online submissions for Single Number.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int zero=0;
        for(int num:nums)
        {
            zero^=num;
        }
        return zero;
 
    }
};
