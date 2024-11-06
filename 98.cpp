#include "common.h"

using namespace std;

class Solution {
public:
    int getMax(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int max = root->val;
        if (root->left) {
            max = std::max(max, getMax(root->left));
        }
        if (root->right) {
            max = std::max(max, getMax(root->right));
        }
        return max;
    }

    int getMin(TreeNode *root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int min = root->val;
        if (root->left) {
            min = std::min(min, getMin(root->left));
        }
        if (root->right) {
            min = std::min(min, getMin(root->right));
        }
        return min;
    }

    bool isValidBST(TreeNode* root) {
        if (root->left && getMax(root->left) >= root->val) {
            return false;
        }
        if (root->right && getMin(root->right) <= root->val) {
            return false;
        }
        
        bool b1 = true;
        bool b2 = true;
        if (root->left) {
            b1 = isValidBST(root->left);
        }
        if (root->right) {
            b2 = isValidBST(root->right);
        }
        return b1 && b2;
    }
}; 