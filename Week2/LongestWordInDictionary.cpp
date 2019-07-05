/*
Problem:
720. Longest Word in Dictionary
Easy

Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words. If there is more than one possible answer, return the longest word with the smallest lexicographical order.
If there is no answer, return the empty string.

Example 1:

Input: 
words = ["w","wo","wor","worl", "world"]
Output: "world"
Explanation: 
The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:

Input: 
words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output: "apple"
Explanation: 
Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

All the strings in the input will only contain lowercase letters.
The length of words will be in the range [1, 1000].
The length of words[i] will be in the range [1, 30].

Notes: Couldnt solve this question with trie. Main issue was determining the longest word that can be built up

*/

class Solution {
public:
    //This is a way to help differentiate words aside from length
    unordered_map<string,int>wordRank;
    string longestWord(vector<string>& words) {
        Trie* root= NewTrieNode();
        int i=0;
        for(string word:words)
        {
            insertString(root,word,i++);
        }
        //return FindLongestWord(root);
        return words[(DFS(root))];
    }
    
    //Trie Node
    struct Trie
    {
        //Is the node index of the Word in list;
        int index=-1;
        bool isRoot=false;
        int frequency=0;
        //A map of child nodes
        unordered_map<char,Trie*> children;
        
    };
    
    Trie* NewTrieNode()
    {
        Trie* newNode=new Trie;
        newNode->isRoot=true;
        return newNode;
    }
    
    void insertString(Trie* root, string word, int wordIndex)
    {   
        if(root==nullptr)
        {
            root=NewTrieNode();

        }
        for(char letter: word)
        {
            bool visited=true;
            //If the node doesnt exist the create a new one
            if(root->children.find(letter)==(root->children.end()))
               {
                   root->children[letter]=NewTrieNode();
                    visited=true;
               }  
               root=root->children[letter];
            if(visited)
            {
                root->frequency++;
            }
            
        }
        root->index=wordIndex;
    }
    
 int DFS(Trie* root)
        {
            string result="";
     if(root->children.empty())
     {
         return root->index;
     }

     int maxFreq=0;

     char best;
     for(auto trieNode: root->children)
            {
                if((trieNode.second->frequency>maxFreq) ||  ((trieNode.second->frequency==maxFreq) &&
                 trieNode.first<best ))
                {
                    //bestChild=trieNode.second;
                    best=trieNode.first;
                        maxFreq=trieNode.second->frequency;
                }
            
            }

     
     return (DFS(root->children[best]));
 }
     
/*  int CheckPrefixFreq(string prefix,vector<string>& words)
  {
      int sum=0;
    for(auto word: words)
    {
        if(word.find(prefix)!=string::npos)
        {
            sum++;
        }
    }
    return sum;
  }
    string DFS(Trie* root,vector<string>& words, string builtWord="")
        {
            string result="";
     if(root->children.empty())
     {
         return words[root->index];
     }
     string word="";
     if(root->index>=0)
     {
         builtWord= words[root->index];
     }
     int curWordFreq=CheckPrefixFreq(word,words);
     for(auto trieNode: root->children)
            {
                string posWord= DFS(trieNode.second,words,builtWord);
                cout<<posWord<<"vs"<<word<<"\n";
                if(((posWord.length()>word.length()) && (CheckPrefixFreq(posWord,words) > curWordFreq))||
                                                        ((posWord.length()== word.length()) &&
                  posWord<word))
                {
                    word=posWord;
                    curWordFreq=CheckPrefixFreq(posWord,words) ;
                }
         
            }
     return word;
 }*/
};
