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
    int pairSum(ListNode *head)
    {
        int size = 0;
        ListNode *node = head;
        while (node)
        {
            size++;
            node = node->next;
        }

        vector<int> vec;
        int index = 0;
        node = head;
        while (index < size / 2)
        {
            vec.push_back(node->val);
            node = node->next;
            index++;
        }
        while (node)
        {
            vec[--index] += node->val;
            node = node->next;
        }
        return *max_element(vec.begin(), vec.end());
    }
};