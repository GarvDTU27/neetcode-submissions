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
    int solve(TreeNode* root, int prevMax){
        if(root == NULL ) return 0;

        if(root->val >= prevMax){
            return 1 + solve(root->left, root->val) + solve(root->right, root->val);
        }

        return solve(root->left, prevMax) + solve(root->right, prevMax) ;
    }
    int goodNodes(TreeNode* root) {
        int leftGood = solve(root->left, root->val);
        int rightGood = solve(root->right, root->val);
        return leftGood + rightGood + 1;
    }
};
