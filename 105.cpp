#include "common.h"

using namespace std;

class Solution {
public:
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if (preorder.size() == 1) {
    //         return new TreeNode(preorder[0]);
    //     }

    //     TreeNode *root = new TreeNode(preorder[0]);
    //     vector<int> preorder_left, inorder_left;
    //     vector<int> preorder_right, inorder_right;
    //     bool left = true;
    //     for (int i = 0; i < inorder.size(); i++) {
    //         if (inorder[i] == preorder[0]) {
    //             left = false;
    //             continue;
    //         }

    //         if (left) {
    //             inorder_left.push_back(inorder[i]);
    //         } else {
    //             inorder_right.push_back(inorder[i]);
    //         }
    //     }
    //     for (int i = 0; i < inorder_left.size(); i++) {
    //         preorder_left.push_back(preorder[i + 1]);
    //     }
    //     for (int i = 0; i < inorder_right.size(); i++) {
    //         preorder_right.push_back(preorder[i + inorder_left.size() + 1]);
    //     }
    //     if (preorder_left.size() >= 1) {
    //         root->left = buildTree(preorder_left, inorder_left);
    //     }
    //     if (preorder_right.size() >= 1) {
    //         root->right = buildTree(preorder_right, inorder_right);
    //     }
    //     return root;
    // }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeImpl(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeImpl(vector<int>& preorder, vector<int>& inorder, int i1, int j1, int i2, int j2) {
        int num = preorder[i1];
        TreeNode* root = new TreeNode(num);
        int index = i2;
        while(inorder[index] != num) {
            index++;
        }
        int size = index - i2;
        if (size >= 1) {
            root->left = buildTreeImpl(preorder, inorder, i1 + 1, i1 + size, i2, index - 1);
        }
        size = j2 - index;
        if (size >= 1) {
            root->right = buildTreeImpl(preorder, inorder, j1 - size + 1, j1 , j2 - size + 1, j2);
        }
        return root;
    }
};

int main() {
    //                   0  1   2   3  4
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder {9, 3, 15, 20, 7};
    Solution s;
    s.buildTree(preorder, inorder);
    return 0;
}