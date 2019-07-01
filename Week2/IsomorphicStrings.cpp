/*
Problem:

    Given two strings s and t, determine if they are isomorphic.

    Two strings are isomorphic if the characters in s can be replaced to get t.

    All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

    Example 1:

    Input: s = "egg", t = "add"
    Output: true

    Example 2:

    Input: s = "foo", t = "bar"
    Output: false

    Example 3:

    Input: s = "paper", t = "title"
    Output: true
    You may assume both s and t have the same length.
    
    Note: I was worried that I was using a less efficient method to solve this problem but it seems relatively fast.
    
    According to LeetCode 7/1/2019
    Runtime: 8 ms, faster than 91.15% of C++ online submissions for Isomorphic Strings.
    Memory Usage: 9.3 MB, less than 24.47% of C++ online submissions for Isomorphic Strings.

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){return false;}
        unordered_map<char,char>sMapstoT;
        for(int index=0;index<s.length();index++)
        {
            //If the letter has been seen before in s
            //then the exacts postion in t must conatin the same
            //letter as previously mapped by letter in s
            if(sMapstoT.find(s[index])!=sMapstoT.end())
            {
                if((sMapstoT[s[index]]) != t[index])
                {
                    return false;
                }
            }
            else
            {
                //Now you need to make sure that t[index]
                //has not been mapped by another s[index]
                for (auto mapping : sMapstoT)
                {
                    if(mapping.second==t[index])
                    {
                        return false;
                    }
                }
                sMapstoT[s[index]]=t[index];
            }
        }
        
        return true;
    }
};
