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
