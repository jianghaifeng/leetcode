#include <map>
#include <set>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    bool pointMap(const vector<int>& v, map<int, set<int>>& m) {
        for (int x=v[0]; x<v[2]; x++) {
            for (int y=v[1]; y<v[3]; y++) {
                if (m[x].find(y) != m[x].end()) return false;
                m[x].insert(y);
            }
        }
        return true;
    }
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<int, set<int>> m;
        for (auto v : rectangles) {
            if (!pointMap(v, m)) return false;
        }

        int x1 = m.begin()->first;
        int x2 = m.rbegin()->first;
        set<int> s = m.begin()->second;
        int y1 = *(s.begin());
        int y2 = *(s.rbegin());
        int cy = s.size();

        cout << x1 << ";" << x2 << ";" << y1 << ";" << y2 << ";" << cy << endl;

        if (x2-x1 != m.size()-1) return false;
        for (auto p : m) {
            if (*(p.second.begin()) != y1) return false;
            if (*(p.second.rbegin()) != y2) return false;
            if (p.second.size() != cy) return false;
        }

        return true;
    }
};

int main() {
    Solution s;

    vector<int> v;
    vector<vector<int>> vv;
    v = {1,1,3,3};
    vv.push_back(v);
    v = {3,1,4,2};
    vv.push_back(v);
    v = {3,2,4,4};
    vv.push_back(v);
    v = {1,3,2,4};
    vv.push_back(v);
    v = {2,3,3,4};
    vv.push_back(v);

    cout << s.isRectangleCover(vv) << endl;

    vv.clear();
    v={1,1,2,3};
    vv.push_back(v);
    v={1,3,2,4};
    vv.push_back(v);
    v={3,1,4,2};
    vv.push_back(v);
    v={3,2,4,4};
    vv.push_back(v);
    cout << s.isRectangleCover(vv) << endl;

    vv.clear();
    v={1,1,3,3};
    vv.push_back(v);
    v={3,1,4,2};
    vv.push_back(v);
    v={1,3,2,4};
    vv.push_back(v);
    v={3,2,4,4};
    vv.push_back(v);
    v={2,3,3,4};
    vv.push_back(v);
    cout << s.isRectangleCover(vv) << endl;

    vv.clear();
    v={1,1,3,3};
    vv.push_back(v);
    v={3,1,4,2};
    vv.push_back(v);
    v={1,3,2,4};
    vv.push_back(v);
    v={2,2,4,4};
    vv.push_back(v);
    cout << s.isRectangleCover(vv) << endl;
}
