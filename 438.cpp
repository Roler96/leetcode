#include "common.h"

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.size() < p.size()) {
            return ans;
        }

        auto isSame = [](const map<char, int> &m, const map<char, int> &m2) -> bool {
            if (m.size() != m2.size()) {
                return false;
            }

            for (auto it = m.begin(); it != m.end(); ++it) {
                char key = it->first;
                auto it2 = m2.find(key);
                if (it2 == m2.end()) {
                    return false;
                }

                if (it2->second != it->second) {
                    return false;
                }
            }
            return true;
        };

        map<char, int> m;
        for (int i = 0; i < p.size(); i++) {
            char c = p[i];
            auto it = m.find(c);
            if (it == m.end()) {
                m[c] = 1;
            } else {
                m[c]++;
            }
        }

        map<char, int> m2;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int front = i - p.size();
            char c = s[i];
            auto it = m2.find(c);
            if (count < p.size()) {
                if (it == m2.end()) {
                    m2[c] = 1;
                } else {
                    m2[c]++;
                }
                count++;
            } else {
                if (it == m2.end()) {
                    m2[c] = 1;
                } else {
                    m2[c]++;
                }
                char c2 = s[front];
                auto it2 = m2.find(c2);
                if (it2 != m2.end()) {
                    if(it2->second == 1) {
                        m2.erase(it2);
                    } else {
                        m2[c2]--;
                    }
                }
            }

            if (isSame(m, m2)) {
                ans.push_back(front + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "baa";
    string p = "aa";
    auto vec = sol.findAnagrams(s, p);
    for (auto num : vec) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}