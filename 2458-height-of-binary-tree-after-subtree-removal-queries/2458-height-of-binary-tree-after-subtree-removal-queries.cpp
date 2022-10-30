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
unordered_map<int, int> l, r, ans;
int height(TreeNode* root){
    if(root == NULL) return 0;
    int left = height(root->left);
    int right = height(root->right);
    l[root->val] = left;
    r[root->val] = right;
    return max(left, right) + 1;
}

void helper(TreeNode* root, int MaxSoFar, int depth){
    if(root == NULL) return;
    ans[root->val] = MaxSoFar;
    helper(root->left, max(MaxSoFar, depth + r[root->val]), depth + 1);
    helper(root->right, max(MaxSoFar, depth + l[root->val]), depth + 1);
}


class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        height(root);
        helper(root->left, r[root->val], 1);
        helper(root->right, l[root->val], 1);
        ans[root->val] = 0;
        vector<int> temp;
        for(int i = 0; i < queries.size(); i++){
            temp.push_back(ans[queries[i]]);
        }
        return temp;
    }
};