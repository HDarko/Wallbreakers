/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

You may assume the string contains only lowercase alphabets.
What if the inputs contain unicode characters? How would you adapt your solution to such case?

Notes: Solving the question with sorting
According to LeetCode:
Runtime: 24 ms, faster than 31.15% of C++ online submissions for Valid Anagram.
Memory Usage: 9.5 MB, less than 53.25% of C++ online submissions for Valid Anagram.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return(s==t);
    }
};
