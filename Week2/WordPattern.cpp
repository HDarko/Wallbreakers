/*
Problem:
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true

Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false

Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
You may assume pattern contains only lowercase letters, 
and str contains lowercase letters that may be separated by a single space.

Notes: Using stringstream was helptful to solve this question

According to LeetCode on 7/1/2019:

Runtime: 4 ms, faster than 71.98% of C++ online submissions for Word Pattern.
Memory Usage: 8.4 MB, less than 89.15% of C++ online submissions for Word Pattern.

*/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        istringstream wordStream(str);
        unordered_map<char,string> patternMap;
        for(int index=0;index<pattern.length(); index++)
        {
            //if the letter is pattern has been seen before
             if(patternMap.find(pattern[index])!=patternMap.end())
            {
                 string word;
                 wordStream>>word;
                if((patternMap[pattern[index]]) != (word))
                {
                    return false;
                }
            }
            else
            {
                // make sure that str[index]
                //has not been mapped by another pattern[index]
                 string word;
                 wordStream>>word;
                //If we run out of words then the pattern was too long.
                if(word==""){return false;}
                for (auto mapping : patternMap)
                {
                    if(mapping.second==word)
                    {
                        return false;
                    }
                }
                patternMap[pattern[index]]=word;
            }
           
    }
        //If wordStream is not empty then then str was longer than pattern
    if(wordStream.peek()!=decltype(wordStream)::traits_type::eof())
    {
        return false;
    }
    return true;
    }
};
