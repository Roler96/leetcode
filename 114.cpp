#include "common.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            flatten(root->left);
        }
        if (root->right) {
            flatten(root->right);
        }

        TreeNode *left = root->left;
        while(left) {
            if (!left->right) {
                break;
            }
            left = left->right;
        }
        if (left) {
            left->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
    }
};

int main() {
    vector<int> nums{1,2,5,3,4,-1,6};
    TreeNode *root = initTreeNode(nums, -1);
    Solution s;
    s.flatten(root);
    while(root) {
        cout << root->val << " ";
        root = root->right;
    }
    deinitTreeNode(root);
    return 0;
}