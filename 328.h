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
    // O(1) space
    // O(n) time
    // 0 <= n <= 10000
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *even_head = nullptr;
        ListNode *odd = nullptr;
        ListNode *even = nullptr;
        ListNode *node = head;
        int index = 1;
        while (node != nullptr)
        {
            if (index % 2 == 0)
            {
                if (even == nullptr)
                {
                    even = node;
                    even_head = node;
                }
                else
                {
                    even->next = node;
                    even = node;
                }
            }
            else
            {
                if (odd == nullptr)
                    odd = node;
                else
                {
                    odd->next = node;
                    odd = node;
                }
            }
            index++;
            node = node->next;
        }
        if (even)
            even->next = nullptr;
        if (odd)
            odd->next = even_head;
        return head;
    }
};