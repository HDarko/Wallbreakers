/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.

Solution:
Runtime: 4 ms, faster than 84.27% of C++ online submissions for Leaf-Similar Trees.
Memory Usage: 13.9 MB, less than 72.97% of C++ online submissions for Leaf-Similar Trees.
*/


class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector <int> tree1;
        vector<int> tree2;
        DFS(root1, tree1);
        DFS(root2, tree2);
        return (tree1==tree2);
        
        
    }
    
    void DFS(TreeNode* node, vector<int>& leaves)
    {
        if(node==nullptr){ return;}
        if((node->left==nullptr) && (node->right==nullptr))
        {
            leaves.push_back(node->val);
            
            
        }
        DFS(node->left, leaves);
        DFS(node->right, leaves);
    }
};
