#include <queue>
#include <iostream>

using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (vector<int>& lhs, vector<int>& rhs) const
  {
    if (reverse) return (lhs[2]<rhs[2]);
    else return (lhs[2]>rhs[2]);
  }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r = heightMap.size();
        if (r < 3) return 0;
        int c = heightMap[0].size();
        if (c < 3) return  0;

        vector<vector<int>> visit(r, vector<int>(c, 0));
        vector<vector<int>> inq(r, vector<int>(c, 0));
        priority_queue<vector<int>, vector<vector<int>>, mycomparison> q;
        vector<int> v;

        for (int i=0; i<c; i++) {
            v = {0, i, heightMap[0][i]};
            q.push(v);
            inq[0][i] = 1;
            v = {r-1, i, heightMap[r-1][i]};
            q.push(v);
            inq[r-1][i] = 1;
        }

        for (int j=1; j<r-1; j++) {
            v = {j, 0, heightMap[j][0]};
            q.push(v);
            inq[j][0] = 1;
            v = {j, c-1, heightMap[j][c-1]};
            q.push(v);
            inq[j][c-1] = 1;
        }

        int water = 0;

        vector<int> tmp;
        while (q.size() > 0) {
            v = q.top();
            q.pop();
            cout << "(" << v[0] << "," << v[1] << "->" << v[2] << ")" << endl;
            visit[v[0]][v[1]] = 1;
            if (v[0]-1 >= 0 && visit[v[0]-1][v[1]] == 0) {
                if (heightMap[v[0]-1][v[1]] < v[2]) {
                    water += (v[2] - heightMap[v[0]-1][v[1]]);
                    cout << "->" << v[0]-1 << "," << v[1] << "," << water << endl;
                    heightMap[v[0]-1][v[1]] = v[2];
                }
                if (inq[v[0]-1][v[1]] == 0) {
                    tmp = {v[0]-1, v[1], heightMap[v[0]-1][v[1]]};
                    q.push(tmp);
                    inq[v[0]-1][v[1]] = 1;
                }
            }
            if (v[1]-1 >= 0 && visit[v[0]][v[1]-1] == 0) {
                if (heightMap[v[0]][v[1]-1] < v[2]) {
                    water += (v[2] - heightMap[v[0]][v[1]-1]);
                    cout << "->" << v[0] << "," << v[1]-1 << "," << water << endl;
                    heightMap[v[0]][v[1]-1] = v[2];
                }
                if (inq[v[0]][v[1]-1] == 0) {
                    tmp = {v[0], v[1]-1, heightMap[v[0]][v[1]-1]};
                    q.push(tmp);
                    inq[v[0]][v[1]-1] = 1;
                }
            }
            if (v[0]+1 < r && visit[v[0]+1][v[1]] == 0) {
                if (heightMap[v[0]+1][v[1]] < v[2]) {
                    water += (v[2] - heightMap[v[0]+1][v[1]]);
                    cout << "->" << v[0]+1 << "," << v[1] << "," << water << endl;
                    heightMap[v[0]+1][v[1]] = v[2];
                }
                if (inq[v[0]+1][v[1]] == 0) {
                    tmp = {v[0]+1, v[1], heightMap[v[0]+1][v[1]]};
                    q.push(tmp);
                    inq[v[0]+1][v[1]] = 1;
                }
            }
            if (v[1]+1 < c && visit[v[0]][v[1]+1] == 0) {
                if (heightMap[v[0]][v[1]+1] < v[2]) {
                    water += (v[2] - heightMap[v[0]][v[1]+1]);
                    cout << "->" << v[0] << "," << v[1]+1 << "," << water << endl;
                    heightMap[v[0]][v[1]+1] = v[2];
                }
                if (inq[v[0]][v[1]+1] == 0) {
                    tmp = {v[0], v[1]+1, heightMap[v[0]][v[1]+1]};
                    q.push(tmp);
                    inq[v[0]][v[1]+1] = 1;
                }
            }
        }

        return water;
    }
};

int main () {
    vector<vector<int>> vv;
    vector<int> v;
    v = {1,4,3,1,3,2}; vv.push_back(v);
    v = {3,2,1,3,2,4}; vv.push_back(v);
    v = {2,3,3,2,3,1}; vv.push_back(v);
    Solution s;
    s.trapRainWater(vv);
    return 0;
}
