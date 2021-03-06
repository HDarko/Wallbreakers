/*
Problem:
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Notes:

I thought he best way to handle this is to use iterators to swap the pointers.
So I had a pointer to the front and end of the size to swap them as I shrunk the distance
between the two. Instead of trying to make sure to stop when both iterators point to
the same thing which would only work for an odd sized vector. I used a counter so
that when the counter reaches the half way point of vector then the swapping is done.

 According to LeetCode at the time I submitted this solution:
 
 Runtime: 48 ms, faster than 86.77% of C++ online submissions for Reverse String.
Memory Usage: 15.2 MB, less than 48.34% of C++ online submissions for Reverse String.

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()>1)
     {
        auto reverse=prev(s.end());
        int half=s.size()/2;
        int counter=0;
        for (auto iter=s.begin(); counter<half;++iter)
        {
            iter_swap(iter,reverse);
            reverse--;
            counter++;
      
        }
    }
    }
};
