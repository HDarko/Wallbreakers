/*
Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

LeetCode:
Runtime: 4 ms, faster than 87.00% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.4 MB, less than 73.31% of C++ online submissions for Sum of Left Leaves.
*/

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return leftSum(root, 'R');
        
        
    }
    int leftSum(TreeNode* root, char direction)
    {
         if(root==nullptr)
        {
            return 0;
        }
        if ((root->left==nullptr) && (root->right==nullptr) && (direction=='L'))
        {
            return root->val;
        }
        
            if ((root->left==nullptr) &&(root->right==nullptr) && (direction=='R'))
        {
            return 0;
        }
            return (leftSum(root->left,'L') + leftSum(root->right,'R'));
    }
};
