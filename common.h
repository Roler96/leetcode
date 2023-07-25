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
