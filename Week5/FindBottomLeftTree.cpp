/*
 Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:

Input:

    2
   / \
  1   3

Output:
1

Example 2:

Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7

Note: You may assume the tree (i.e., the given root node) is not NULL. 

According to LeetCode:
Runtime: 12 ms, faster than 90.60% of C++ online submissions for Find Bottom Left Tree Value.
Memory Usage: 20.7 MB, less than 78.30% of C++ online submissions for Find Bottom Left Tree Value.
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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* curNode=nullptr;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty())
        {
            curNode=nodeQueue.front();
            nodeQueue.pop();
            if(curNode->right!=nullptr)
            {
                nodeQueue.push(curNode->right);
            }
             if(curNode->left!=nullptr)
            {
                nodeQueue.push(curNode->left);
            }
        }
        return curNode->val;
        
    }
};
