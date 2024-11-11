#include "common.h"

using namespace std;

class Solution {
public:
    bool find(TreeNode *root, TreeNode *node) {
        if (!root) {
            return false;
        }

        if (root == node) {
            return true;
        }
        return find(root->left, node) || find(root->right, node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == p) {
            return p;
        }
        if (root == q) {
            return q;
        }

        if (find(p, q)) {
            return p;
        }
        if (find(q, p)) {
            return q;
        }

        bool left_p = find(root->left, p);
        bool left_q = find(root->left, q);
        bool right_p = find(root->right, p);
        bool right_q = find(root->right, q);

        if (left_p && left_q) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (right_p && right_q) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};
int main() {
    return 0;
}
