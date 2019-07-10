/*
Problem:
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

Notes:: Both solutions fail with a test case of 1000 a's for p and 2100 a's for s

*/

//Solution Number 1:

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length())
        {
            return {};
        }
        string curWindow="";
        vector<int> anagramIndices;
        sort(p.begin(),p.end());
       
        for(int index=0; index<s.size(); index++)
        {
            int indexForWind{index};
            //Check if an anagram starting from this index
            //is within s
            if(( index+ p.length()-1)< s.length())
            {
                
                while(curWindow.length()<p.length()) 
                {

                    curWindow+=s[indexForWind++];
                }
                sort(curWindow.begin(), curWindow.end());
                if(curWindow==p)
                {
                    anagramIndices.push_back(index);
                }
                curWindow="";
             }
        }
        return anagramIndices;   
        
    }
};
//"cbaebabacd" p: "abc"
//aaabbbccd  abc

//Solution Number 2:

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.length()>s.length())
        {
            return {};
        }
        
        vector<char> curWindow(p.length(),'0');
        vector<char> pArray(p.begin(),p.end());
        vector<int> anagramIndices;
        sort(pArray.begin(),pArray.end());
        char firstCharacter;
        bool first=true;
        int lastIndex=0;
       
        for(int index=0; index<s.size(); index++)
        {
            int indexForWind{index};
            //Check if an anagram starting from this index
            //is within s
            if(( index+ p.length()-1)< s.length())
            {
               
                firstCharacter=s[index];
                if(first==true)
                {
                         while(indexForWind<p.length())
                    {

                        curWindow[indexForWind]=s[indexForWind];
                             indexForWind++;
                            
                    }
                     lastIndex=indexForWind-1;
                     first=false;
                     sort(curWindow.begin(), curWindow.end());
                    
                }
               
                else 
                {
                       while(curWindow.size()<p.length())
                    {
                           int curIndex=indexForWind+lastIndex;
             
                          SortedInsert(curWindow,s[curIndex]);
                          for(auto charr: curWindow)
                          {
                              cout<<charr;
                          }
                           indexForWind++;
                           cout<<"\n";
                    } 
                    lastIndex=lastIndex;
                } 
                  
               
                //cout<<curWindow.size()<<"\n";
                //cancel out
               
             
                if(curWindow==pArray)
                {
                    anagramIndices.push_back(index);
                }
                auto it =find(curWindow.begin(), curWindow.end(),firstCharacter);
               // cout<<curWindow[distance(curWindow.begin(),it)];
                
                curWindow.erase(it);
                //cout<<"sa";
                 //cout<<curWindow<<"\n";
                //curWindow="";
             }
        }
        return anagramIndices;   
        
    }
       void SortedInsert(vector<char> &word , char letter)
        {
           int index=word.size()-1;
          
            for(; (index>=0);index--)
            {
                if((word[index]>letter))
                {
                    continue;
                }
                else{
                    break;
                }
                  
            }
           word.insert(word.begin()+index+1,1,letter);
            //word[index+1]=letter;
            
                                    
        }
                                
                                
};
//"cbaebabacd" p: "abc"
//aaabbbccd  abc
//cba
//abe

