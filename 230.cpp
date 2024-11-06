#include "common.h"

using namespace std;

class Solution {
public:
    int count(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }

        int left = 0, right = 0;
        if (root->left) {
            left = count(root->left);
        }
        if (root->right) {
            right = count(root->right);
        }
        return left + right + 1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count_left = count(root->left);
        if (count_left == k - 1) {
            return root->val;
        } else if (count_left < k - 1) {
            return kthSmallest(root->right, k - count_left - 1);
        } else /* count_left > k - 1 */{ 
            return kthSmallest(root->left, k);
        }
    }
};

int main() {
    TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2));
    Solution s;
    cout << s.kthSmallest(root, 2);
    deinitTreeNode(root);
    return 0;
}