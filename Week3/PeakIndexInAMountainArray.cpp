/*
Problem:
Let's call an array A a mountain if the following properties hold:

    A.length >= 3
    There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]

Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

Example 1:

Input: [0,1,0]
Output: 1

Example 2:

Input: [0,2,1,0]
Output: 1


    3 <= A.length <= 10000
    0 <= A[i] <= 10^6
    A is a mountain, as defined above.

My solution according to LeetCode:
Runtime: 16 ms, faster than 77.11% of C++ online submissions for Peak Index in a Mountain Array.
Memory Usage: 9.5 MB, less than 23.62% of C++ online submissions for Peak Index in a Mountain Array.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        //Since A is definitely a mounatin then we just need to find the index where the 
        //the index + 1 has a smaller value
        for(int index=0; index<A.size();index++)
        {
            if(A[index+1]<A[index])
            {
                return index;
            }
        }
        return -1;
        
    }
};
