#include <vector>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <iostream>

using namespace std;
class Solution {
public:
    void insert(int i, int j, unordered_map<int, int>& m, const vector<int>& v, vector<unordered_set<int>>& s) {
        if (j == 0) return;
        if (m.find(v[i]+j) != m.end()) {
            s[m[v[i]+j]].insert(j);
        }
    }

    bool canCross(vector<int>& stones) {
        if (stones.size() < 2 || stones[0] != 0 || stones[1] != 1) return false;

        unordered_set<int> emptyset;
        map<int, unordered_set<int>> m;

        for (int i=1; i<stones.size(); i++) {
            m[stones[i]] = emptyset;
        }

        m[1].insert(1);

        for (auto p : m) {
            for (auto j : p.second) {
                if (j!=1 && m.count(p.first+j-1) != 0) m[p.first+j-1].insert(j-1);
                if (m.count(p.first+j) != 0) m[p.first+j].insert(j);
                if (m.count(p.first+j+1) != 0) m[p.first+j+1].insert(j+1);
            }
        }

        return (m[stones.back()].size() != 0);
    }

    bool canCross_old(vector<int>& stones) {
        if (stones.size() < 2 || stones[0] != 0 || stones[1] != 1) return false;

        vector<unordered_set<int>> vset(stones.size(), unordered_set<int>());
        unordered_map<int, int> m;

        for (int i=0; i<stones.size(); i++) {
            m[stones[i]] = i;
        }

        vset[1].insert(1);
        
        for (int i=1; i<stones.size(); i++) {
            for (auto j : vset[i]) {
                insert(i, j, m, stones, vset);
                insert(i, j-1, m, stones, vset);
                insert(i, j+1, m, stones, vset);
            }
        }

        for (int i=0; i<stones.size(); i++) {
            for (auto j : vset[i]) {
                cout << j << " ";
            }
            cout <<  endl;
        }

        return (vset[stones.size()-1].size() != 0);
    }
};


int main() {
    Solution s;
    vector<int> v;
    v = {0,1,3,5,6,8,12,17};
    cout << "true=" << s.canCross(v) << endl;
    v = {0,1,2,3,4,8,9,11};
    cout << "false=" << s.canCross(v) << endl;

    return 0;
}
