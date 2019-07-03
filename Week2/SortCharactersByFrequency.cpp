/*
Problem:
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.

Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.

Note:
First we need to store the occurence of each letter in a map.
Then sort them using the custom comparator function.
I dont use Lambas often but I thought it would be good practice
especially with how simple the function is.
One thing to note is that if I use the same logic but with a multiset
and .count() then for very large strings it times out but same string
is solved with a map.
According to LeetCode:
Runtime: 176 ms, faster than 10.46% of C++ online submissions for Sort Characters By Frequency.
Memory Usage: 10.3 MB, less than 86.88% of C++ online submissions for Sort Characters By Frequency.
*/

class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()){return s;}
        //unordered_multiset<char> charFreq;
        unordered_map<char, int> map;
        for (char letter: s)
        {
            //charFreq.insert(letter);
            map[letter]++;
            
        }
        /*sort(s.begin(),s.end(), 
            [&charFreq] (char& first, char& second) 
             {
                 //This must account for the frequency being higher  OR if we have 
                 //multiple letters with same frequency then we sort by ASCI order
                 if((charFreq.count(first))==(charFreq.count(second)))
                 {
                     return (first>second);
                 }
                 return ((charFreq.count(first))>(charFreq.count(second)));
                // return (((charFreq.count(first))>(charFreq.count(second))) || 
                       //  ((charFreq.count(first))==(charFreq.count(second)) && (first>second)));                    
             });*/
         sort(s.begin(),s.end(), 
            [&map] (char& first, char& second) 
             {
                 //This must account for the frequency being higher  OR if we have 
                 //multiple letters with same frequency then we sort by ASCI order
                 if((map[first])==(map[second]))
                 {
                     return (first>second);
                 }
                 return ((map[first])>(map[second]));
                // return (((charFreq.count(first))>(charFreq.count(second))) || 
                       //  ((charFreq.count(first))==(charFreq.count(second)) && (first>second)));                    
             });
        return s;
    }
    
};
