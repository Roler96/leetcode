#include "common.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *node = head;
        int size = 0;
        while (node != nullptr)
        {
            size++;
            node = node->next;
        }

        node = head;
        ListNode *before = nullptr;
        for (int i = 0; i < size / 2; i++)
        {
            before = node;
            node = node->next;
        }

        if (before == nullptr)
        {
            delete node;
            return nullptr;
        }

        before->next = node->next;
        delete node;
        return head;
    }
};