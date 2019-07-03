/*
Given a paragraph and a list of banned words, return the most frequent word that is not in the list of banned words.  
It is guaranteed there is at least one word that isn't banned, and that the answer is unique.

Words in the list of banned words are given in lowercase, and free of punctuation.
Words in the paragraph are not case sensitive.  The answer is in lowercase.

 

Example:

Input: 
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit."
banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.


    1 <= paragraph.length <= 1000.
    0 <= banned.length <= 100.
    1 <= banned[i].length <= 10.
    The answer is unique, and written in lowercase (even if its occurrences in paragraph may have uppercase symbols, and even if it is a proper noun.)
    paragraph only consists of letters, spaces, or the punctuation symbols !?',;.
    There are no hyphens or hyphenated words.
    Words only consist of letters, never apostrophes or other punctuation symbols.
   Notes:
   Used a multiset for this question as instructed.
   

According to LeetCode:
Runtime: 8 ms, faster than 76.84% of C++ online submissions for Most Common Word.
Memory Usage: 10.3 MB, less than 9.82% of C++ online submissions for Most Common Word.

*/
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_multiset<string> words;
        //First go through each character in string
        string word="";
        string commonWord;
        int wordCount=0;
        for(int i=0;i<paragraph.length();i++)
        {
            if(isalpha(paragraph[i]))
            {
                //Add lowercase version to wprd
                word+=tolower(paragraph[i]);
                    
            }
            else{
                  //put word in set
                if(word!="")
                {
                     words.insert(word);
               
                    word="";
                }
               
                
                }
            }
        
         //Assuming that we reach end of string but no punctation
            //then add word to set
         if(word!="")
              {
                   words.insert(word);
              }
              
            //Now delete any banned words from set
         for(string &bannedWord:banned)
         {
             if(words.find(bannedWord)!=words.end())
             {
                 words.erase(bannedWord);
             }
         }
        for(auto &word:words)
        {

            if(words.count(word)>wordCount)
            {
                commonWord=word;
                wordCount=words.count(word);
            }
        }
        
        return commonWord;
        }
        
    };
