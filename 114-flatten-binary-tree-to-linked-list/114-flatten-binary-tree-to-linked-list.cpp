/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int > &in)
    {
        if(root==NULL)
            return;
        in.push_back(root->val);
        solve(root->left,in);
        
        solve(root->right,in);
        
    }
    
    void flatten(TreeNode* root) {
        if(root==NULL)
            return;
        vector<int > in;
        solve(root,in);
        int n= in.size();
        
        root->val= in[0];
        TreeNode* curr= root;
        
        for(int i=1;i<n;i++)
        {
            TreeNode* temp = new TreeNode(in[i]);
            curr->left = NULL;
            curr->right = temp;
            curr= temp;
            
            
        }
        curr->right=NULL;
        curr->left=NULL;
    }
};