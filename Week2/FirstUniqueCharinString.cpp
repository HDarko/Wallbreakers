//Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1. 
//Runtime: 72 ms, faster than 28.87% of C++ online submissions for First Unique Character in a String.
//Memory Usage: 13 MB, less than 38.83% of C++ online submissions for First Unique Character in a String.
class Solution {
public:
    int firstUniqChar(string s) {
        //word is wordFrequency
        if(s==""){return (-1);}
        unordered_map<char,int> word;
            for(char letter: s )
            {
                if(word.find(letter)!=word.end())
                {
                    word[letter]++;
                }
                else
                {
                    word.insert(pair<int,int> (letter, 1));
                }
            }
            for(int index=0;index<s.length();index++)
            {
               
                if((word[s[index]])==1)
                {
                    return index;
                }
            }
        return (-1);
        
    }
};
