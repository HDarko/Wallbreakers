/*
Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

Note:

    s could be empty and contains only lowercase letters a-z.
    p could be empty and contains only lowercase letters a-z, and characters like . or *.

Example 1:

Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:

Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:

Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".

Example 4:

Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".

Example 5:

Input:
s = "mississippi"
p = "mis*is*p*."
Output: false

Notes for Dynamic Programming Solution:
'*' means zero or more of the preceding character 
'.' mean  any character can be substitued for theposition . is in

best way is to think of it as a 2d array of bools
just solv for every possible combinition of indices/

Dynamically we cant go forward to access indexes we havent used 
yet so we can go backwards
The cases are thus
if 
1.If letters are the same (even if one is dot) then we need to carry any
previous True or False we had before.
2. if letters dont match
		 is p letter a *?
				 if yes then did prev pattern Letter match current  word letter
				 {account for if prev p letter iss ' . '}
						 if  true then either prev pattern letter and current letter match or
							 check if the next pattern letter after star matches the current  word letter

This question required me to watch a Youtube Vid before I understood the concepts
https://youtu.be/PGlYbdAwiNY
Though I think I took a different approach
Did not add a recursive solution because so far cant get it to work
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        //if p is "" then return if s is ""
        if(p.empty())
        {
            return s.empty();
        }
         vector<vector<bool>>indices (s.length()+1 , vector<bool>(p.length()+1,{} ) );;
        //represents that we passed the is one empty condition parts
        indices[0][0]=true;
        //if s is empty then every 2nd element in p must be *
        
            for (int i=1; i<=p.length(); i+=2)
            {
                if(p[i]!='*' || (i+1) > p.length())
                {
                    break;
                }
                else
                {
                    indices[0][i+1]=true;
                }
            }
        
        for (int sLetter=1; sLetter<=s.length();sLetter++)
        {
            for (int pLetter=1; pLetter<=p.length();pLetter++)
            {
                //since we did the empty conditions we use -1
                //for correct indices in strings
                //check if letters match or pattern has  '.' 
                if((s[sLetter-1]==p[pLetter-1]) || ((p[pLetter-1]) =='.'))
                {
                    //then we carry the previous result
                    indices[sLetter][pLetter]=indices[sLetter-1][pLetter-1];
                }
                //check if p has ''*'' even though letters dont match
                else if(p[pLetter-1]=='*')
                   {
                    //By default assume letters dont match so our result is 
                    //same sletter but before the * in pLetter
                    indices[sLetter][pLetter] =  indices[sLetter][pLetter-2];
                    
                       //now check if previos letter in p matches the current s letter
                    // or if  previous s letter is a dot
                    if  ((p[pLetter-2]==s[sLetter-1]) || (p[pLetter-2]=='.'))
                       {
                           //then either our current sLetter matches the letter before the *(if not dot)
                           // or our current sLetter matches the  pLetter after * (so zero or ignore 
                        //p letter modified by *
                        )
                           indices[sLetter][pLetter] = ( indices[sLetter][pLetter-2]) ||
                               (indices[sLetter-1][pLetter]);
                       }
                        
                   }
         
                }
            }
 
         return (indices[s.length()][p.length()]);
        }
           
    };
    
   
