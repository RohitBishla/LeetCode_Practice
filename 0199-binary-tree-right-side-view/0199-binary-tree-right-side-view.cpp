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
    void func(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int temp = root->val;
        while(!q.empty()){
            TreeNode* child = q.front();
            q.pop();
            if(child == NULL){
                ans.push_back(temp);
                if(q.size() != 0){
                    q.push(NULL);
                }
            }
            else{
                if(child->left != NULL){
                    q.push(child->left);
                }
                if(child->right != NULL){
                    q.push(child->right);
                }
                temp = child->val;
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }
};