/*

Problem:
We are given two sentences A and B.  (A sentence is a string of space separated words.  
Each word consists only of lowercase letters.)
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Return a list of all uncommon words. 
You may return the list in any order.

Notes:
Originally I was gonna use a set but then 
the numeber of checks I would have to make to find
uncomon words in both A and B was inefficient in my mind.
So a simpler solution is the put all the words in a single
hashmap and update a words counter each time it is found in
A or B. Thus the ones I would want will have a counter of 1.
I forgot to account for the uncommon words specifically in B

Also could have optimized it by A + " "+ B then going through that single string.

According to LeetCode:
Runtime: 4 ms, faster than 84.64% of C++ online submissions for Uncommon Words from Two Sentences.
Memory Usage: 8.9 MB, less than 59.71% of C++ online submissions for Uncommon Words from Two Sentences.
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string,int> allWords;
        vector<string> uncommonWords;
       istringstream streamA(A);
        istringstream streamB(B);
        //To ignore the spaces we use a stringstream
        while(streamA)
        {
            string word;
            streamA>>word;
            if(allWords.find(word)==allWords.end())
            {
                allWords[word]=1;
            }
            else
            {
                //If the word appears more than once in a sentence then it
                //is not uncommon.
                allWords[word]++;
            }
        }
        while(streamB)
        {
            string word;
            streamB>>word;
            if( allWords.find(word)== allWords.end())
            {
                //Since we know the word already is uncommon we
                //can just add it to the vector
                allWords[word]=1;
            }
            else
            {
                allWords[word]++;
            }
        }
        //Now add any uncommon words from A
        for(const auto wordCount:allWords)
        {
            if(wordCount.second==1)
            {
                uncommonWords.push_back(wordCount.first);
            }
        }
        return uncommonWords;
    }
};
