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
    void getOrder(TreeNode* cur, vector<int>& vec){
        if(cur==nullptr)    return;
        
        getOrder(cur->left,vec);
        vec.push_back(cur->val);
        getOrder(cur->right,vec);

        return;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        getOrder(root,vec);
        return vec;
    }
};