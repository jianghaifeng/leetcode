#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> v;
        int x = 0, y = 0;
        int dir = 1;
        for (int i=0; i<row*col; i++) {
            v.push_back(mat[x][y]);
            auto p = getNextPoint(row-1, col-1, x, y, dir);
            x = p.first;
            y = p.second;
        }

        return v;
    }

    pair<int, int> getNextPoint(int r, int c, int x, int y, int& dir) {
        cout << "x=" << x << " y=" << y << " dir=" << dir << endl;
        if (dir == 1 && x == 0 && y < c) {
            dir = -1;
            return make_pair(x, y+1);
        }
        
        if (dir == 1 && y == c) {
            dir = -1;
            return make_pair(x+1, y);
        }

        if (dir == -1 && y == 0 && x < r) {
            dir = 1;
            return make_pair(x+1, y);
        }

        if (dir == -1 && x == r) {
            dir = 1;
            return make_pair(x, y+1);
        }

        if (dir == 1) return make_pair(x-1, y+1);
        return make_pair(x+1, y-1);
    }
};

int main() {
    vector<vector<int>> vv;
    vector<int> v;
    v = {1,2,3};
    vv.push_back(v);
    v = {4,5,6};
    vv.push_back(v);
//    v = {7,8,9};
//    vv.push_back(v);

    Solution s;
    auto res = s.findDiagonalOrder(vv);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
