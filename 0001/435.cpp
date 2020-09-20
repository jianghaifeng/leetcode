#include <iostream>
#include <vector>

using namespace std;
bool comp(vector<int>& v1, vector<int>& v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

class Solution {
public:
    bool helper(vector<int>& cur, vector<int> v) {
        if (cur[1] <= v[0]) {
            cur = v;
            return false;
        } else if (cur[1] < v[1]) {
            return true;
        } else {
            cur = v;
            return true;
        }
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int res = 0;
        
        if (intervals.size() <=1) return res;
        
        vector<int> cur = intervals[0];
        for (int i=1; i<intervals.size(); i++) {
            if (helper(cur, intervals[i])) res++;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vv;

    vv = {{1,2},{2,3},{3,4},{1,3}};
    cout << s.eraseOverlapIntervals(vv) << " = 1" << endl;

    vv = {{1,2},{1,2},{1,2}};
    cout << s.eraseOverlapIntervals(vv) << " = 2" << endl;

    vv = {{1,2},{2,3}};
    cout << s.eraseOverlapIntervals(vv) << " = 0" << endl;
    return 0;
}
