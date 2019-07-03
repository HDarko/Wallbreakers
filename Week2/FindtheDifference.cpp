/*
Problem:
* Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.


*Notes:
Well Lucky me!
I solved a similiar question using bitwise in WeekOne.
That being the SingleNum

According to LeetCode:
Runtime: 4 ms, faster than 90.54% of C++ online submissions for Find the Difference.
Memory Usage: 8.9 MB, less than 73.72% of C++ online submissions for Find the Difference.
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        char singleChar=' ';
        for(int index=0;index<s.length();index++)
        {
            singleChar^=s[index];
            singleChar^=t[index];
        }
        singleChar^=t[t.length()-1];
        
        return tolower(singleChar);
    }
};