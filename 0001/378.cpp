#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const pair<int, pair<int, int>>& lhs, const pair<int, pair<int, int>>&rhs) const
  {
      return lhs.first > rhs.first;
  }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int len = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, mycomparison> minHeap;

        for (int i=0; i<len; i++) minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));

        while (k > 1) {
            auto pipii = minHeap.top();
            minHeap.pop();
            pipii.second.second++;
            if (pipii.second.second < len) {
                pipii.first = matrix[pipii.second.first][pipii.second.second];
                minHeap.push(pipii);
            }
            k--;
        }

        return minHeap.top().first;
    }
};

int main() {
    vector<vector<int>> vv;
    vector<int> v = {1,5,9};
    vv.push_back(v);
    v = {10,11,13};
    vv.push_back(v);
    v = {12,14,15};
    vv.push_back(v);
    Solution s;
    cout << s.kthSmallest(vv, 8) << endl;
    return 0;
}
