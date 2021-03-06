/*
Problem:
 There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, 
 then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. 
If M[i][j] = 1, then the ith and jth students are direct friends with each other, 
otherwise not. And you have to output the total number of friend circles among all the students. 

Notes:
This is my first introduction to Union Find and understanding how to apply it was a bit tough
though its implementations were understandable.
So my strategy is to have an array of friends which is my union find structure
It will initially be of the form array[student]=student to show each studentr is friends with
themselves. After the unions of friend groups we can check the number of students who
are still friends with themselves. Unions between friend x and friend y mean
Array[y]=x
If for example all students are friends then there is one such student , 
if there are two friends groups then there are two such students

According to LeetCode on 6/23/2019

Runtime: 20 ms, faster than 91.31% of C++ online submissions for Friend Circles.
Memory Usage: 10.7 MB, less than 99.08% of C++ online submissions for Friend Circles.
*/

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int size=M.size();
        int friends[size];
        for (int s=0; s<size;s++)
        {
            friends[s]=s;
        }
        for (int row=0; row<size;row++)
        {
            for (int col=0; col<size;col++)
            {
                //If the two are friends and arent the same person
                if((M[row][col]) && (row!=col))
                {
                    if(!Connected(row,col,friends))
                    {
                        Union(row,col,friends);
                    }
                }
            }
        }
         return (FriendGroups(friends, size));
    }
    
    
    int Find(int k, int array[])
    {
        if (array[k]==k)
        {
           return k; 
        }
        return (Find(array[k],array));
    }
    
    void Union(int x, int y, int array[])
    {
        int rootOfX=Find(x,array);
        int rootOfY=Find(y,array);
        array[rootOfY]=rootOfX;
    }
    
    bool Connected(int x, int y, int array[])
    {
        return (Find(x, array)==Find(y, array));
    }
    
    int FriendGroups(int array[], int size)
    {
        int counter=0;
        for(int i=0; i<size;i++)
        {
            if(array[i]==i)
            {
                counter++;
            }
        }
        return counter;
    }
};
