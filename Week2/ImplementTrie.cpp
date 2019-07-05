/*
 Implement Trie (Prefix Tree)
 Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
Notes
Using a map instead of a array of 26 letters

According to LeetCode:
Runtime: 92 ms, faster than 41.82% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 36 MB, less than 83.43% of C++ online submissions for Implement Trie (Prefix Tree).

*/

class Trie {
public:
    /** Initialize your data structure here. */
    Trie(){
          
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* root=this;
          for(char letter: word)
        {
       
            if(root->children.find(letter)==(root->children.end()))
               {
                   root->children[letter]= new Trie;
               }  
               root=root->children[letter];
        
         }
        root->isWord=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
         Trie* root=this;
         for(char letter: word)
        {
      
            if(root->children.find(letter)==(root->children.end()))
               {
                   return false;
               }  
               root=root->children[letter];
         }
        return (root->isWord);
        
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
         Trie* root=this;
         for(char letter: prefix)
        {
      
            if(root->children.find(letter)==(root->children.end()))
               {
                   return false;
               }  
               root=root->children[letter];
         }
        return true;
        
    }
    //Variables
    unordered_map<char,Trie*> children;
          bool isWord=false;
};


