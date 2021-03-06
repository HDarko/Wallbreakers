/*
Problem:
Given a column title as appear in an Excel sheet, return its corresponding column number.

Notes:
There are 26 numbers in the alphabet and AA= 27 =26+1
If A=1 and AA= 27 then 1 + 26*1 , then AB= 2 +26*1
AA to ZZ is 26 * 26 letters in all.
So what if we do
26 ** n + (A-letter+1)
This was a bit annoying to I realised it was like binary conversion.
I 
*/


class Solution {
public:
    int titleToNumber(string s) {
        int index =s.size()-1;
        int sum=0;
       for (auto letter:s)
        {
           //The last letter is at pos 26^0, preceding is at 26^1 then ^2 etc
           int pos= pow(26,index);
           
           //Since we want A to be 1 and not 0 we add 1       
            int num= (letter- 'A')+1;
             sum+=pos*num;
             index--;
        
        }
        return sum;
    }
};
