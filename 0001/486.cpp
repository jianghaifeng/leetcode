#include <iostream>
#include <vector>

using namespace std;


void debug(vector<vector<int>>&);

class solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> vv(len, vector<int>(len, 0));

        for (int j = 0; j<len; j++) {
            vv[j][j] = nums[j];
            for (int i=j-1; i>=0; i--) {
                vv[i][j] = max(nums[j]-vv[i][j-1], nums[i]-vv[i+1][j]);
            }
        }

        debug(vv);

        return vv[0][len-1] >= 0;
    }
};

void debug(vector<vector<int>>& vv) {
    cout << "===============" << endl;
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "===============" << endl;
}

int main() {
    solution s;
    vector<int> v = {1,2,3,4};
    s.PredictTheWinner(v);
    v = {1,5,2};
    cout << s.PredictTheWinner(v) << "==false" << endl;
    v = {1,5,233,7};
    cout << s.PredictTheWinner(v) << "==true" << endl;
    return 0;
}

