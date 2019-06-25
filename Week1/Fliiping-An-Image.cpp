/*
 Problem:
 
Given a binary matrix A, 
we want to flip the image horizontally, 
then invert it, and return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, inverting [0, 1, 1] results in [1, 0, 0].

Notes:
I considered predicting the reversals and only doing the inversions 
//but after going through the first half of a vector I realised that it
//made the second half complicated so instead I used std::reverse and
//did the 1-2 step
According to LeetCode on the day I did this
Runtime: 20 ms, faster than 15.45% of C++ online submissions for Flipping an Image.
Memory Usage: 9.4 MB, less than 52.50% of C++ online submissions for Flipping an Image.
*/
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for( auto &row: A)
        {
                
              //reverse row then inverse bit
               reverse(row.begin(),row.end());
                for(auto iter=row.begin(); iter!=row.end();++iter)
                {
                    if(*iter)
                    {
                        *iter=0;
                    }
                    else
                    {
                        *iter=1;
                    }
                }
        }
        
        return A;
        
    }
};
