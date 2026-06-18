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
int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int sum = height(root->left) + height(root->right);
        ans = max(ans,sum);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return ans;
    }
};
