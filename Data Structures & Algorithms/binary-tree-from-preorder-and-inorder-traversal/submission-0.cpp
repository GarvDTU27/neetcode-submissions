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
    unordered_map<int,int> loc ;
    TreeNode* helper(vector<int>& pre, vector<int>& in, int &preInd, int st, int end){
        if(preInd >= pre.size() || st > end) return NULL ;

        int idx = loc[pre[preInd]] ;

        TreeNode* root = new TreeNode(pre[preInd]);
        preInd++ ;
        root->left = helper(pre, in, preInd, st, idx-1);
        root->right = helper(pre, in, preInd, idx+1, end);

        return root ;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i< inorder.size(); i++){
            loc[inorder[i]] = i ;
        }
        int preInd = 0;
        return helper(preorder, inorder, preInd, 0, inorder.size()-1) ;
    }
};
