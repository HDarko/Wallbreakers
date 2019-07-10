/*
Problem:
Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000

Example 2:

Input: 2.10000, 3
Output: 9.26100

Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25

Note:

    -100.0 < x < 100.0
    n is a 32-bit signed integer, within the range [−231, 231 − 1]

According to LeetCode for my solution:
Runtime: 4 ms, faster than 74.30% of C++ online submissions for Pow(x, n).
Memory Usage: 8.7 MB, less than 5.09% of C++ online submissions for Pow(x, n).

*/

class Solution {
public:
    double myPow(double x, int n) {
        
        //x^n =   have n (x)'s multiplied together' 2^2 = 2 (2) multiplied= 4
        //if x ^ n with n<0 then how many (x)'s should we use to divide 1'
        
        //if n is 0 then we return 1
        if(n==(0))
        {
            return 1;
        }
        //if n==1 then we return x
        if(n==1)
        {
            return x;
        }
        
        if(n<0)
            // this is 1/( x^n )
        {
            //not sure why by returning 1/(x * x^-(n+1)) prevents overflow isues
            return (1/( x*  myPow(x,-(n+1))));
        }
        // if n>1 and is odd
        if(n%2==1)
        {
            double multiplyiers= pow(x,(n-1)/2);
            return multiplyiers * multiplyiers * x;
        }
        else
        {
            //n is even
            double multiplyiers= pow(x,n/2);
            return multiplyiers * multiplyiers;
        }
        
    }
};
