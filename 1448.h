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
    void dfs(TreeNode *root, int max, int &ans)
    {
        if (max <= root->val)
            ans++;

        if (root->left)
            dfs(root->left, std::max(max, root->val), ans);
        if (root->right)
            dfs(root->right, std::max(max, root->val), ans);
    }

    int goodNodes(TreeNode *root)
    {
        int ans = 0;
        int max = root->val;
        dfs(root, max, ans);
        return ans;
    }
};