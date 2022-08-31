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
    void inorder(TreeNode* root,vector<int> &in)
    {
        if(root==NULL)
        {
            return ;
            
        }
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root,arr);
        int l=0,r= arr.size()-1;
        while(l<r)
        {
            if(arr[l]+arr[r]==k)
            {
                return true;
            }
            else if(arr[l]+arr[r]<k)
            {
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }
};