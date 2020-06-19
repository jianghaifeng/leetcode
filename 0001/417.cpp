#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Comp {
public:
    bool operator() (vector<int>& v1, vector<int>& v2) {
        return v1[2] > v2[2];
    }
};


void output(vector<vector<int>> vv) {
    cout << "==================" << endl;
    for (auto v: vv) {
        for (auto i: v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

class Solution {
public:
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    typedef priority_queue<vector<int>, vector<vector<int>>, Comp> pq;

    void helper(vector<vector<int>>& res, vector<vector<int>>& matrix, pq q) {
        int r = matrix.size();
        int c = matrix[0].size();

        while (q.size() > 0) {
            auto v = q.top();
            q.pop();
            for (int i=0; i<4; i++) {
                int x = v[0] + dx[i];
                int y = v[1] + dy[i];
                if (x >= 0 && x < r  && y >= 0 && y < c && res[x][y] == 0) {
                    if (matrix[x][y] < matrix[v[0]][v[1]]) res[x][y] = 1;
                    else {
                        vector<int> tmp  = {x, y, matrix[x][y]};
                        q.push(tmp);
                        res[x][y] = 3;
                    }
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> vv;
        int r = matrix.size();
        if (r == 0) return vv;
        int c = matrix[0].size();
        if (c == 0) return vv;

        pq pq1, pq2;
        vector<vector<int>> valid1(r, vector<int>(c, 0));
        for (int i=0; i<c; i++) {
            valid1[0][i] = 3;
            vector<int> tmp = {0, i, matrix[0][i]};
            pq1.push(tmp);
        }
        for (int i=1; i<r; i++) {
            valid1[i][0] = 3;
            vector<int> tmp = {i, 0, matrix[i][0]};
            pq1.push(tmp);
        }
        helper(valid1, matrix, pq1);
        output(valid1);
        vector<vector<int>> valid2(r, vector<int>(c, 0));
        for (int i=0; i<c; i++) {
            valid2[r-1][i] = 3;
            vector<int> tmp = {r-1, i, matrix[r-1][i]};
            pq2.push(tmp);
        }
        for (int i=0; i<r-1; i++) {
            valid2[i][c-1] = 3;
            vector<int> tmp = {i, c-1, matrix[i][c-1]};
            pq2.push(tmp);
        }
        helper(valid2, matrix, pq2);
        output(valid2);

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (valid1[i][j] > 1 && valid2[i][j] > 1) {
                    vector<int> tmp = {i,j};
                    vv.push_back(tmp);
                }
            }
        }

        return vv;
    }
};

int main() {
    vector<vector<int>> vv;
    vector<int> v;
    v = {1,2,2,3,5};vv.push_back(v);
    v = {3,2,3,4,4};vv.push_back(v);
    v = {2,4,5,3,1};vv.push_back(v);
    v = {6,7,1,4,5};vv.push_back(v);
    v = {5,1,1,2,4};vv.push_back(v);
    Solution s;
    output(s.pacificAtlantic(vv));
    return 0;
}
