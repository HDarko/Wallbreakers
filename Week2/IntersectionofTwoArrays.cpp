/*
Problem:

Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

    Each element in the result must be unique.
    The result can be in any order.
    
Notes:
I was trying to decide wheter just iteration throught the arrays or using the hash set is a more effecive version.
I went with hashmap

LeetCode said on 6/30/2019

Runtime: 4 ms, faster than 99.59% of C++ online submissions for Intersection of Two Arrays.
Memory Usage: 9.4 MB, less than 55.95% of C++ online submissions for Intersection of Two Arrays.

*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        bool firstSmaller=(nums1.size()<nums2.size())? true: false;
        unordered_set<int> smallerArray;
        vector<int> results;
        if(firstSmaller)
        {
            for(int num: nums1)
            {
                smallerArray.insert(num);
            }
            for (int num: nums2)
            {
                //if num is part of intersection
                if(smallerArray.find(num)!=smallerArray.end())
                {
                    //if the num isnt already in results vector
                    if((find(results.begin(),results.end(), num))==results.end())
                    {
                        results.push_back(num);
                    }
                }
            }
        }
        else
        {
            for(int num: nums2)
            {
                smallerArray.insert(num);
            }
             for (int num: nums1)
            {
                if(smallerArray.find(num)!=smallerArray.end())
                {
                    if((find(results.begin(),results.end(), num)) ==results.end())
                    {
                        results.push_back(num);
                    }
                }
            }
        }
        return results;
}
};
