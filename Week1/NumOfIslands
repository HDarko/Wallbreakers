/* QUESTION TO BE SOLVED:
    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands.
    An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
    You may assume all four edges of the grid are all surrounded by water.
    
    Notes:
    This has been the hardest question for me in week one
        and the last to finish.
Mainly I tried to use the index to count the number of lands with their value in an array being the same
as their index but it caused me no end of trouble with being wrong by one value in specific maps.
but now I am also gonna follow my string function from an earlier question and just delete the islands altogether from map.

According to LeetCode, this simpler strategy was more effective. I need to be more straightforward from now on instead of
adding unnessary complexity.
624/2019
Runtime: 8 ms, faster than 99.71% of C++ online submissions for Number of Islands.
Memory Usage: 10.6 MB, less than 91.21% of C++ online submissions for Number of Islands.

    */

----------------------------------------------------------------------------------

---------------------------------------------------------------------------------
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty()){return 0;}
        
        //gridSize is number of rows in grid.
        int numRows=grid.size();
        int numberofIslands=0;
        //Number of elements in a row
        int numCols=grid[0].size();   
              for( int row=0; row<numRows; row++)
                {
                  for (int col=0;col<numCols;col++)
                  {
                       if((grid[row][col])=='1')
                       {
                           //Destroy the island and add it to the islands counter
                           numberofIslands++;
                           DFS(row,col,grid,numRows,numCols);
                       }
                  }
                 
                 }
         return numberofIslands; 
            }
                
    
   void DFS(int row, int col, vector<vector<char>>& grid, int numRows,int numCols )
   {
 
       if((row>=numRows) ||(row<0) || (col>=numCols) || (col<0))
       {
           return;
       }
        if((grid[row][col]=='0'))
        {
           return;
        }
        //if the current loc contains X or been visied before then stop 
        if((grid[row][col]=='1'))
        {
           grid[row][col]='0';
        }
        DFS(row+1,col,grid,numRows,numCols);
        DFS(row-1,col,grid,numRows,numCols);
        DFS(row,col-1,grid,numRows,numCols);
        DFS(row,col+1,grid,numRows,numCols);
        
    }
    
       
   
       
           
};
                          

