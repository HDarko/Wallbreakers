/*
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

    Each row must contain the digits 1-9 without repetition.
    Each column must contain the digits 1-9 without repetition.
    Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.


A partially filled sudoku which is valid.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

Example 1:

Input:
[
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: true

Example 2:

Input:
[
  ["8","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being 
    modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


    A Sudoku board (partially filled) could be valid but is not necessarily solvable.
    Only the filled cells need to be validated according to the mentioned rules.
    The given board contain only digits 1-9 and the character '.'.
    The given board size is always 9x9.

Note: So my solution is soldi but need to look at other problems to see how they optimized their solutions.

According to leetCode on 6/30/2019
Runtime: 20 ms, faster than 45.80% of C++ online submissions for Valid Sudoku.
Memory Usage: 11.1 MB, less than 25.94% of C++ online submissions for Valid Sudoku.


*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return ((AllValid3x3s(board)) && (AllValidColl(board))
                                        && (AllValidRows(board)));
        
    }
    
    bool AllValidColl(vector<vector<char>>& board)
    {
        for(int col=0; col<board[0].size();col++)
        {
             unordered_set<int> seenDigits;
            for(int row=0; row<board.size();row++)
            {
                 if((board[row][col])!='.')
                {
                     if(seenDigits.find((board[row][col]))!=seenDigits.end())
                        {
                            return false;
                        }
                        else
                        {
                            seenDigits.insert((board[row][col]));
                        }
                }
            }
        }
        return true;
    }
    
    bool AllValidRows(vector<vector<char>>& board)
    {
        for(int row=0; row<board.size();row++)
        {
           unordered_set<int> seenDigits;
            for(int col=0; col<board[0].size();col++)
            {
                if((board[row][col])!='.')
                {
                     if(seenDigits.find((board[row][col]))!=seenDigits.end())
                        {
                            return false;
                        }
                        else
                        {
                            seenDigits.insert((board[row][col]));
                        }
                }
                    
                
            }
        }
        return true;
    }
    
    bool AllValid3x3s(vector<vector<char>>& board)
    {
        //Since the boards are always 9*9 we can hard code the starting points
        set<pair<int, int>> topLeft={ pair<int,int >{0,0},pair<int,int >{0,3},pair<int,int >{0,6},
                                     pair<int,int >(3,0),pair<int,int >{3,3},pair<int,int >{3,6},
                                     pair<int,int >{6,0}, pair<int,int >{6,3}, pair<int,int >{6,6}};
        for(auto start:topLeft)
        {
            unordered_set<int> seenDigits;
            
            for(int row=start.first;row<((start.first)+3); row++)
            {
                for(int col=start.second; col<((start.second)+3);col++)
                {
                    if((board[row][col])!='.')
                    {
                        if(seenDigits.find((board[row][col]))!=seenDigits.end())
                        {
                            return false;
                        }
                        else
                        {
                            seenDigits.insert((board[row][col]));
                        }
                    }
                }
            }
        }
        return true;
    }
};
