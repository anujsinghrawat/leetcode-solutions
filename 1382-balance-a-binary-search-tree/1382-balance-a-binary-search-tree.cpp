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
        
        solve(root->left,in);
        in.push_back(root->val);
        solve(root->right,in);
        
    }
    
    TreeNode* inordertobst(int s,int e,vector<int > &in)
    {
        if(s>e)
            return NULL;
        int mid=(e+s)/2;
        TreeNode* root= new TreeNode(in[mid]);
        root->left=inordertobst(s,mid-1,in);
        root->right=inordertobst(mid+1,e,in);
        return root;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        solve(root,in);
        int n= in.size();
        return inordertobst(0,n-1,in);
    }
    
    
    
};