/*

Problem:
Given two strings s and t , write a function to determine if t is an anagram of s.

Notes:
This solution doesnt seem very effective or fast but it is straigtforward.
Still not my best so will research on other more effective solutions.

Runtime: 700 ms, faster than 6.16% of C++ online submissions for Valid Anagram.
Memory Usage: 9.5 MB, less than 39.94% of C++ online submissions for Valid Anagram.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        int start=0;
        int count=0;
        for (int i=0;i<s.size();i++)
        {
             auto match= t.find(s[i],start);
            if (match!=string::npos)
            {
                count++;
                start++;
            }
        }
        return (t.empty());
    }
};

/*
A more effective solution shown in LeetCode discussions is done as follows
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sCharToCountMap, tCharToCountMap;
        for (const auto& ch : s)    sCharToCountMap[ch]++;
        for (const auto& ch : t)    tCharToCountMap[ch]++;
        
        for (const auto& elem : sCharToCountMap)
            if (elem.second != tCharToCountMap[elem.first])     return false;
        
        for (const auto& elem : tCharToCountMap)
            if (elem.second != sCharToCountMap[elem.first])     return false;
        
        return true;
    }
};
*?
