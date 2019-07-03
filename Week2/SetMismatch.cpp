/*
Problem:

Notes:
 The set S originally contains numbers from 1 to n. But unfortunately, 
 due to the data error, one of the numbers in the set got duplicated to another number in the set, 
 which results in repetition of one number and loss of another number.

Given an array nums representing the data status of this set after the error.
Your task is to firstly find the number occurs twice and then find the number that is missing. 
Return them in the form of an array.

Example 1:

Input: nums = [1,2,2,4]
Output: [2,3]

Note:

    The given array size will in the range [2, 10000].
    The given array's numbers won't have any order.


A clever 'way to sort this is to sort the array then check for the side by side dupilcates'
Then while going through check if the next element is = previous element+1 to find missing ele
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        multiset<int> numbers;
        int missingNum{0};
        int doubleOccuringNum{0};
        vector<int> result;
        for(int num:nums)
        {
            numbers.insert(num);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(numbers.count(i)==0)
            {
                missingNum=i;
            }
            else
            if(numbers.count(i)==2)
            {
                doubleOccuringNum=i;
            }
    }
         result.push_back(doubleOccuringNum);
        result.push_back(missingNum);
        return result;
}
};
