#include "common.h"

using namespace std;

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
class Solution
{
public:
    void dfs(TreeNode *root, long long targetSum, int &ans)
    {
        if (root->val == targetSum)
            ans++;
        if (root->left)
            dfs(root->left, targetSum - root->val, ans);
        if (root->right)
            dfs(root->right, targetSum - root->val, ans);
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
            return 0;
        int ans = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode *node = que.front();
            que.pop();
            dfs(node, targetSum, ans);
            if (node->left)
                que.push(node->left);
            if (node->right)
                que.push(node->right);
        }
        return ans;
    }
};