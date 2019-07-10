/*
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

Notes:
//Ok so the question here is
is if two characters are not the same in the strings 
then try all three operations on word 1 and choose the one with the 
smallest number of operations
//Good thing we we dont have to actively change the word but can abstract the change
for example cat  and we wanner convert it to  act.
Insertion:
if we add a a to cat to make acat then we assume we can advance a to c in act so indexB+1
but since just added 'a' to the back of cat we still need to account for c in cat (now acat)
so that index doesnt change (also we didnt actually add anything).
Removal:
Removal of c from cat means we advance from c to a so indexA+1 while indexB stays the same
substitution:
Its a removal then and insertion so we advance both indexA and indexB
*/

//For Recursive Solution with also use memoization with the vector to kee track of hsitory of solved index combinations
//According to LeetCode for the Recursive Solution
//Runtime: 12 ms, faster than 78.43% of C++ online submissions for Edit Distance.
//Memory Usage: 11.7 MB, less than 9.57% of C++ online submissions for Edit Distance.

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        //Keey track of any index combinations we have seen before
        //like [0][0] or [2][3] etc. we need extra row cos of empty strings
        vector<vector<int>> indexABHistory(word1.length()+1,vector<int>(word2.length()+1,(-1)));
       //Note that we iterating backwards
        return (MinEditDistance(word1,word2, word1.size(),word2.size(),indexABHistory));
    }
    
   int MinEditDistance(string &wordA, string &wordB, int wordASize, int wordBSize, vector<vector<int>>& indexAB)
    {
       //If a value already exist the return it
       if( (indexAB[wordASize][wordBSize])>-1)
       {
           return indexAB[wordASize][wordBSize];
       }
       
          
         if(wordASize==0)
        {
            //since word1 is zero we have to add the letters from word2
             indexAB[wordASize][wordBSize]= wordBSize;
            return wordBSize;
        }
        if(wordBSize==0)
        {
            //we have to remove all the letters in word1
            indexAB[wordASize][wordBSize]= wordASize;
            return wordASize;
        }
    
        //since we using sizes then as we need to subract 1 to get the right index.
        if((wordA[wordASize-1]) == (wordB[wordBSize-1]))
           {
                //In this case the letters are the same so advance both indices
               indexAB[wordASize][wordBSize]= MinEditDistance(wordA,wordB,
                                                            wordASize-1, wordBSize-1, indexAB);
               return  indexAB[wordASize][wordBSize];
           }
       
               //In this case the letters are the different so try all operations
               indexAB[wordASize][wordBSize]= min({
                   //Insertion
                   1+ MinEditDistance(wordA,wordB, wordASize, wordBSize-1, indexAB),
                   //Deletion
                     1+ MinEditDistance(wordA,wordB, wordASize-1, wordBSize, indexAB),
                   //Substitution(2 cos it is deletert then insert)
                     1+ MinEditDistance(wordA,wordB, wordASize-1, wordBSize-1, indexAB)
               });
            return indexAB[wordASize][wordBSize];
           }
    };
