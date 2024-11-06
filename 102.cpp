#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            int size = nodes.size();
            vector<int> vec;
            while(size > 0) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node) {
                    vec.push_back(node->val);
                    nodes.push(node->left);
                    nodes.push(node->right);
                }
                size--;
            }
            if (!vec.empty()) {
                answer.push_back(vec);
            }
        }
        return answer;
    }
};

int main() {
    TreeNode *root = initTreeNode({3,9,20,-1,-1,15,7}, -1);
    Solution s;
    auto v = s.levelOrder(root);
    for (auto vv : v) {
        for (auto n : vv) {
            cout << n << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}