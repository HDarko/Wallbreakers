/*

Problem:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Notes:

num[x] +num[y]= target
thus num [y] -target =num[x]
Best way to do this is to use a hash map
keys are the values and values are indexes

Runtime: 8 ms, faster than 96.73% of C++ online submissions for Two Sum.
Memory Usage: 10.7 MB, less than 6.25% of C++ online submissions for Two Sum.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //Using num [y]-target =num[x] as core technique
        //instead of num[x] +num[y]= target
        vector<int> result;
        map<int,int> valToIndex;
        valToIndex.clear();
        // set the hashMap[values]=index;
        for(int index=0; index<nums.size(); index++)
        {
            valToIndex[nums[index]]=index;
        }
        for(int index=0; index<nums.size(); index++)
        {
            //for each index or x
            //see if you can find target- num[x] && num[x] and num[y] are
            //  not x==y
            auto curVal=valToIndex.find(target-nums[index]) ;
            if((curVal!= valToIndex.end()) &&
                (curVal->second!=index))
            {
                result.push_back(index);
                result.push_back(curVal->second);
                break;
            }
        }
          return result;       
    }
};
