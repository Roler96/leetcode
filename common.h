#pragma once

#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <list>
#include <set>
#include <queue>

#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdint>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

inline ListNode *initListNode(const std::vector<int> &vec)
{
    ListNode *head = nullptr;
    ListNode *node = nullptr;
    for (int num : vec)
    {
        if (node == nullptr)
        {
            node = new ListNode(num);
            head = node;
        }
        else
        {
            node->next = new ListNode(num);
            node = node->next;
        }
    }
    return head;
};

inline void deinitListNode(ListNode *head)
{
    ListNode *node = head;
    while (node)
    {
        ListNode *p = node;
        node = node->next;
        delete p;
    }
};

inline void printListNode(ListNode *head)
{
    std::cout << "ListNode(" << head << "):" << std::endl;
    while (head)
    {
        std::cout << head->val << " \n"[head->next == nullptr];
        head = head->next;
    }
};

inline TreeNode *initTreeNode(const std::vector<int> &vec, int invalid)
{
    if (vec.empty())
        return nullptr;

    std::vector<TreeNode *> nodeVector;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] != invalid)
            nodeVector.push_back(new TreeNode(vec[i]));
        else
            nodeVector.push_back(nullptr);
    }
    TreeNode *root = nodeVector[0];
    int pos = 1;
    std::queue<TreeNode *> que;
    que.push(root);
    while (!que.empty())
    {
        TreeNode *node = que.front();
        que.pop();

        node->left = nodeVector[pos++];
        if (pos == nodeVector.size())
            break;
        node->right = nodeVector[pos++];
        if (pos == nodeVector.size())
            break;

        if (node->left)
            que.push(node->left);
        if (node->right)
            que.push(node->right);
    }
    return root;
}

inline void deinitTreeNode(TreeNode *root)
{
    if (root == nullptr)
        return;
    deinitTreeNode(root->left);
    deinitTreeNode(root->right);
    delete root;
}