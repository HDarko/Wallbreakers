/*
Given an integer array with even length,
where different numbers in this array represent different kinds of candies.
Each number means one candy of the corresponding kind.
You need to distribute these candies equally in number to brother and sister. 
Return the maximum number of kinds of candies the sister could gain.

Example :

Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation:
There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 

Example 2:

Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 

The length of the given array is in range [2, 10,000], and will be even.
The number in given array is in range [-100,000, 100,000].

Notes:
So when I first saw this question I was thiking of permutations but
I was sure thye must have been a simpler method.Eventually after thinking it thorugh I realised:
In the best case scenraio where every candy was of a different kind. The sister will have
at most half of the sweets.
Any other scenario would mean she would have the same number of different kinds as possible. 
For example if there are four sweets 3 reds and one blue then at most the sister can have a max number of 2.
Thus the sister will either have the exact number of different kinds of sweets or she will have 
half then number of sweets. Whichever is smaller.

According to LeetCode:
Runtime: 288 ms, faster than 73.75% of C++ online submissions for Distribute Candies.
Memory Usage: 50.8 MB, less than 60.84% of C++ online submissions for Distribute Candies.

*/

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        if(candies.size()==0){return 0;}
        unordered_set<int> uniqueKinds;
        for(int &candy: candies)
        {
            uniqueKinds.insert(candy);
        }
        return ((candies.size()/2<=uniqueKinds.size())? candies.size()/2: uniqueKinds.size());
    }
};
