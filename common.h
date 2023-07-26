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
    for (int i = 0; i < nodeVector.size(); i++)
    {
        if (nodeVector[i])
        {
            int leftIndex = i * 2 + 1;
            int rightIndex = (i + 1) * 2;
            if (leftIndex < nodeVector.size())
                nodeVector[i]->left = nodeVector[leftIndex];
            if (rightIndex < nodeVector.size())
                nodeVector[i]->right = nodeVector[rightIndex];
        }
    }
    return nodeVector[0];
}

inline void deinitTreeNode(TreeNode *root)
{
    if (root == nullptr)
        return;
    deinitTreeNode(root->left);
    deinitTreeNode(root->right);
    delete root;
}