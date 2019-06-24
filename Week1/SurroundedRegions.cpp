/*

Question: Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
Notes:This took me a while to do because of the backtracking aspect. 
But once I recalled DFS and BFS it was simple to do.

According to LeetCode at 6/24/2019:
Runtime: 28 ms, faster than 93.01% of C++ online submissions for Surrounded Regions.
Memory Usage: 14.6 MB, less than 28.86% of C++ online submissions for Surrounded Regions.


class Solution {
public:
    

    void solve(vector<vector<char>>& board) {
        if(board.empty()){return;}
        //number of rows in grid.
        int numRows=board.size();
        //Number of elements in a row
        int numCol=board[0].size();
        if((numRows==2) &&(numCol==2))
        {
            return;
        }
     
    vector<bool> defaultValues (numCol,false);
        //Initializing the vectors of visited
     
    vector<vector<bool>> visited(numRows,defaultValues);
    
        //For each border 0 find a DFS path 
        //Top Border
        
        for(int x=0;x<numCol;x++)
        {
            if((board[0][x])=='O')
            {
                DFS(0,x,numRows,numCol,board, visited);
            }
        }
        //Bottom Row
        for(int x=0;x<numCol;x++)
        {
            if((board[numRows-1][x])=='O')
            {
                 DFS(numRows-1,x,numRows,numCol,board, visited);
            }
        }
              
            //Left Coll
          for(int x=0;x<numRows;x++)
        {
            if((board[x][0])=='O')
            {
                 DFS(x,0,numRows,numCol,board ,visited);
            }
        }
           //Right Coll
          for(int x=0;x<numRows;x++)
        {
            if((board[x][numCol-1])=='O')
            {
                DFS(x,numCol-1,numRows,numCol,board, visited);
            }
        }
        //Go through inner Board(no borders) and flip any possoble 0s
         for (int x=1;x<numRows-1;x++)
        {
            for(int y=1;y<numCol-1;y++)
            {  
                if(((board[x][y])=='O') && (!visitedOs[x][y]))
                {
                    board[x][y]='X';
                }
            }
        }
    
       
}
void DFS(int row, int col,int numRows,
         int numCol,
         vector<vector<char>>&board,
         vector<vector<bool>> &visited)
    {
        //the the rows and collums are not legal then stop
        if(row>=numRows || (row<0) || (col>=numCol) || (col<0))
        {
            return;
        }
      
        //if the current loc contains X or been visied before then stop 
        if( (visited[row][col]) || (board[row][col]=='X'))
        {
            return;
        }
        visited[row][col]=true;
        DFS(row+1,col,numRows,numCol,board,visited);
        DFS(row-1,col,numRows,numCol,board,visited);
        DFS(row,col-1,numRows,numCol,board,visited);
        DFS(row,col+1,numRows,numCol,board,visited);
        
    }
    
    
    
};
