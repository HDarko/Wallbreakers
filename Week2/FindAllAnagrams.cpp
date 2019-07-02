/*
Problem
  Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Notes: Took a bit thinking but the question is solved. Had to recal the sliding window
concept from Networks course.

According to LeetCode:
Runtime: 32 ms, faster than 80.08% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 10.3 MB, less than 48.27% of C++ online submissions for Find All Anagrams in a String.

*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //first we need to have the lengths of both p and s
        int sSize=s.length();
        int pSize=p.length();
        //Now we need vectors to act as our tables
        // instead of map[char]=frequency of char
        //we can use vector['a'-char]=frequency
        //Since we need to update the ['a'=char] we shall
        //add 26 elements to each vector initilaized to 0
        
        vector<int> sWordFreq(26,0);
        vector<int> pWordFreq(26,0);
        vector<int> result;
        for(char letter:p)
        {
            pWordFreq[letter-'a']++;
        }
        // sWordFreq acts as a window and stores the frequencies it currenctly
        //sees as it moves through s
        for(int index=0; index<sSize; index++)
        {
            //As we iterate though s if we pass the length of p
            if(index>=pSize)
            {
                //Decrese the frequecy of the first letter,
                //increase frequency of last letter
                sWordFreq[s[index-pSize]-'a']--;
                sWordFreq[s[index]-'a']++;
            }
            else
            {
             sWordFreq[s[index]-'a']++;
            }
                
                //If this current sWordFreq and pWordFreq are same in frequencies
            //then we have an anagram match
                if(sWordFreq==pWordFreq)
                {
                    result.push_back(index-pSize+1);
                }
            }
            
        return result;   
        
    }
};
