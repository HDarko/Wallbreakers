/

*Problem:
 Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.

Notes:
//Check if the each member of the smaller string can be found in the larger string
        //in the same order
        
        According to LeetCode:
        Runtime: 64 ms, faster than 74.17% of C++ online submissions for Is Subsequence.
      Memory Usage: 16.9 MB, less than 85.34% of C++ online submissions for Is Subsequence.

*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        //Check if the each member of the smaller string can be found in the larger string
        //in the same order
         if(s.empty() && t.empty()) {return true;}
        if(s.empty()) {return true;}
        int charMatch{0};
        int subSeqIndex{0};
        for(char &letter: t)
        {
           
            if (letter == s[subSeqIndex])
            {
                subSeqIndex++;
            charMatch+=1;
            }    
        }
        return (charMatch==s.size());
        
    }
};
