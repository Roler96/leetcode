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
    vector<int> leftNodes(TreeNode *root)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            vector<int> vec;
            vec.push_back(root->val);
            return vec;
        }

        vector<int> left, right;
        if (root->left)
            left = leftNodes(root->left);

        if (root->right)
            right = leftNodes(root->right);

        for (int i : right)
            left.push_back(i);

        return left;
    }

    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> left1, left2;
        left1 = leftNodes(root1);
        left2 = leftNodes(root2);
        return left1 == left2;
    }
};