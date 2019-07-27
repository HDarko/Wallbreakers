/*
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). 
The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). 
One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

According to LeetCode:
Runtime: 80 ms, faster than 42.58% of C++ online submissions for Island Perimeter.
Memory Usage: 19.2 MB, less than 14.18% of C++ online submissions for Island Perimeter.

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int sum=0;
        vector<int> islands;
        for(int i=0; i<=grid.size()-1; i++)
        {
            for(int j=0; j<=grid[0].size()-1; j++)
            {
                if( grid[i][j]==1)
                {
                     Adjacent(grid, i,j, islands);
                }
                   
            }
        }
       for(auto land: islands)
       {
           sum+=land;
            }
        return sum;
        
        
    }
    //0,0
    
    
     void Adjacent(vector<vector<int>>&  grid, int& i, int& j,vector<int>& islands)
     {
          
         int open=0;
        if(((i+1)>grid.size()-1) || (grid[i+1][j]==0))
         {
                  open++;

         }
         if(((i-1)<0) || (( grid[i-1][j]==0)))
         {

                  open++; 
         }
      
         if(((j+1)>(grid[0].size()-1)) || ( grid[i][j+1]==0))
         {
      
                  open++; 
         }
     
         if(((j-1)<0) || ( grid[i][j-1]==0))
         {    
                  open++; 
         }
         islands.push_back(open);
        
        
     }
};


