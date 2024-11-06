#include "common.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> getLayers(TreeNode* root) {
        vector<vector<int>> layers;
        queue<TreeNode *> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            int size = nodes.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode *node = nodes.front();
                nodes.pop();
                if (node) {
                    vec.push_back(node->val);
                    if (node->left) {
                        nodes.push(node->left);
                    }
                    if (node->right) {
                        nodes.push(node->right);
                    }
                }
            }
            if (!vec.empty()) {
                layers.push_back(vec);
            }
        }
        return layers;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> layers = getLayers(root);
        vector<int> answer;
        for (const vector<int> &layer : layers) {
            answer.push_back(layer.back());
        }
        return answer;
    }
};