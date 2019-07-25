/*Given an n-ary tree, return the postorder traversal of its nodes' values.

For example, given a 3-ary tree:

 

 

Return its postorder traversal as: [5,6,3,2,4,1].

Solution:
Runtime: 156 ms
Memory Usage: 33 MB

*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root==nullptr) return {};
        stack<Node*> nodeStack;
        Node *prevNode= root;
        vector<int> ans;
        nodeStack.push(root);
        while (!nodeStack.empty() || root)
        {
            if(root)
            {
                for(int index= root->children.size()-1; index>=0; index--)
                {
                    nodeStack.push(root->children[index]);
                }
            }
             root=nodeStack.top();
         
            if(root->children.empty() ||prevNode==(root->children.back() ))
               {
                   ans.push_back(root->val);
                   prevNode=root;
                   nodeStack.pop();
                    root=nullptr;
               }
        }
         return ans;
        
    }
              
};
