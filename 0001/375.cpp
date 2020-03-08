#include <cstdio>
#include <vector>

using namespace std;
void output(vector<int> v) {
    for (auto i : v) {
        printf("%3d ", i);
    }
    printf("\n");
}

/*
 
   1  2  3  4  5  6  7  8  9 10
1  0  1  2  4  6  9
2     0  2  3  6  8
3        0  3  4  8
4           0  4  5
5              0  5
6                 0  6
7                    0  7
8                       0  8
9                          0  9
10                            0
*/


class Solution {
public:
    int getMoneyAmount(int n) {
        vector<int> v(n+1, 0);
        vector<vector<int>> vv(n+1, v);
        for (int i=1; i<n; i++) {
            vv[i][i] = 0;
            vv[i][i+1] = i;
        }

        for (int i=3; i<=n; i++) {
            for (int j=i-2; j>=1; j--) {
                vv[j][i] = vv[j][i-1] + i;
                for (int k=j+1; k<i; k++) {
                    if (vv[j][i] > max(vv[j][k-1], vv[k+1][i]) + k)
                        vv[j][i] = max(vv[j][k-1], vv[k+1][i]) + k;
                }
                //printf("vv[%d][%d] = %d\n", j, i, vv[j][i]);
            }
        } 

        return vv[1][n];
    }
};

int main() {
    Solution s;
    printf("%d", s.getMoneyAmount(60));
    return 0;
}
