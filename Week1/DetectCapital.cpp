
/*
Problem:
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Otherwise, we define that this word doesn't use capitals in a right way. 

Notes:  
 Another option could have been using the Ascii code and checking if the number falls within
  the range for Capital letters

According to LeetCode
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
Memory Usage: 8.2 MB, less than 52.81% of C++ online submissions for Detect Capital.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first=false;
        int numOfCaps=0;
        for(int i=0;i<word.size();i++)
        {
            if(i==0)
               {
                   if(isupper(word[0]))
                   {
                       first=true;
                      numOfCaps++;
                   }
               
               }
            else{
                 if (isupper(word[i]))
                 {
                     
                    numOfCaps++;
                 }
            }
        }
        cout<<numOfCaps;
        if((numOfCaps==0) || (numOfCaps==word.size()))
        {
              return true;
        }
        
        if((numOfCaps==1) && first)
        {
            return true;
        }
        return false;
    }
};
