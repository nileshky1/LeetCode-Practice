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
    void preorder(TreeNode* root, vector<int> &nodeValue)
    {
        if(root==NULL) return;
        preorder(root->left, nodeValue);
        preorder(root->right, nodeValue);
        nodeValue.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodeValue;
        preorder(root,nodeValue);
        return nodeValue;
    }
};