/*
Problem:
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: 
Starting with any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay),
or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Notes: Used some code/ concept mentioned in my self dividing numb question from week 1

According to Leet Code my solution:
Runtime: 4 ms, faster than 81.81% of C++ online submissions for Happy Number.
Memory Usage: 8.5 MB, less than 38.91% of C++ online submissions for Happy Number.
*/

class Solution {
public:
    bool isHappy(int n) {
        if(n==0){return false;}
        if(n==1){return true;}
        unordered_set<int> numbersinLoop; 
        int curNum{n};
        while(true)
        {
            curNum=SumofSqrDigits(curNum);
            if(curNum==1)
            {
                return true;
            }
            else
            {
                //The number already exist in set so we are looping
                if(numbersinLoop.find(curNum)!=numbersinLoop.end())
                {
                    return false;
                }
                numbersinLoop.insert(curNum);
            }
        }
    }
    
    int SumofSqrDigits(int& n)
    {
        int result=0;
        while(n>0)
        {
            int digit{n % 10};
        
            result+=(digit*digit);
            
             n/=10;   
        }
      
        return result;
    }
};
