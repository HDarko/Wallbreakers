/*
Problem:
 A self-dividing number is a number that is divisible by every digit it contains. 
 For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
  Also, a self-dividing number is not allowed to contain the digit zero. 
  Given a lower and upper number bound, output a list of every possible self dividing number, 
  including the bounds if possible. 
*/
//I had done a question like this before and remembered that using mod 10
//was a useful method so I merely implemented that, in C++ this time.
Last time it was a Python question

When I did this:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Self Dividing Numbers.
Memory Usage: 8.3 MB, less than 86.57% of C++ online submissions for Self Dividing Numbers.

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> result;
        
        for(int i=left;i<right+1;i++)
        {
            if(CanSelfDivide(i))
            {
                result.push_back(i);
            }
                
        }
        return result;
    }
    
    bool CanSelfDivide(int i)
    {
        //Initialize the temp to the number i
        int temp=i;
        
        while(temp>0)
        {
        //First find the temp mod 10
        // which should give a number 0-9 as the remainder
        // this number will be rightmost digit.
        //if this digit is 0 or cant divide i then 
        //number can't self divide
            int digit{temp % 10};
            if(digit==0 || i % digit!=0)
            {
                return false;
            }
            //dividing by 10 pushes the righbost digit to the
            //right of a . and since temp is an integer it removes it
            //so next rightmost digit is up. If temp is 0
            //then we have gone trough them all.
            temp/=10;
        }
        return true;
    }
};
