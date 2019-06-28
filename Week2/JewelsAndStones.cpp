/*
Problem:

You're given strings J representing the types of stones that are jewels,
and S representing the stones you have.  Each character in S is a type of stone you have.  
You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters.
Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example:
Input: J = "aA", S = "aAAbbbb"
Output: 3

S and J will consist of letters and have length at most 50.
The characters in J are distinct.

Notes:
This was a straighforward question. I was worried that there was a test case I hadn't accounted for but my solution
worked

According to LeetCode on 6/28/2019:

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.6 MB, less than 38.37% of C++ online submissions for Jewels and Stones.
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.empty() || S.empty()){return 0;}

        unordered_set<char> jewelSet;
        int ownedJewels=0;
        for (char jewel: J)
        {
            jewelSet.insert(jewel);
        }        
        for (char stone: S)
        {
            //Since we wont use the element in any way
            //we say use set.count insted of set.find as we dont need an itereator
            if(jewelSet.count(stone)!=0)
            {
                ownedJewels++;
            }
        }
        return ownedJewels;
        
    }
};
