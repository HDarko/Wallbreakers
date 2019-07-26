/*
Given a binary tree, find the length of the longest path where each node in the path has the same value. 
This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5

Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5

Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        if(root==nullptr)
        {return 0;}
        int maxLength{0};
        SearchLongestPath(root,root->val, maxLength);
            
        return maxLength;
        
    }
    
    int SearchLongestPath(TreeNode* root, int prevValue, int& maxLength)
    {
        int leftPath= root->left?  SearchLongestPath(root->left,root->val,maxLength): 0;
        int rightPath= root->right?  SearchLongestPath(root->right,root->val,maxLength): 0;
        maxLength = max(rightPath+leftPath, maxLength);
        if (root->val==prevValue)
        {
            return (1+max(rightPath,leftPath));
        }
        else
        {
            return 0;
        }
    }
};
