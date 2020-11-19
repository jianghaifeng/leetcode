#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    pair<int, int> split(string s) {
        int o = 0, z = 0;
        for (auto c : s) {
            if (c == '0') z++;
            else if (c == '1') o++;
        }
        return  make_pair(z,o);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> vv(n+1, vector<int>(m+1, 0));

        for (auto s : strs) {
            auto p = split(s);

            for (int i=n; i>=p.second; i--) {
                for (int j=m; j>=p.first; j--) {
                    vv[i][j] = max(vv[i][j], vv[i-p.second][j-p.first]+1);
                }
            }
        }
        return vv[n][m];
    }
};


int main() {
    vector<string> v = {"10","0001","111001","1","0"};
    Solution s;
    cout << s.findMaxForm(v, 5, 3) << endl;
}
