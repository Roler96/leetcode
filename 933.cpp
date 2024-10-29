#include "common.h"

using namespace std;

class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        m_queue.push(t);
        while (t - m_queue.front() > 3000)
            m_queue.pop();
        return m_queue.size();
    }

private:
    queue<int> m_queue;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */