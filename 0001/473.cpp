#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    bool dfs(const int& side, vector<int>& v, const vector<int>& nums, int i) {
        if (i == nums.size()) {
            return side == v[0] && side == v[1] && side == v[2] && side == v[3];
        }

        for (int n=0; n<4; n++) {
            if (v[n] + nums[i] <= side) {
                v[n] += nums[i];
                if (dfs(side, v, nums, i+1)) return true;
                v[n] -= nums[i];
            }
        }

        return false;
    }

    bool makesquare(vector<int>& nums) {
        if (nums.size() == 0) return false;
        int perimeter = 0;
        for (auto i : nums) {
            perimeter += i;
        }

        int side = perimeter / 4;

        vector<int> v(4,0);
        return dfs(side, v, nums, 0);
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {1,1,2,2,2};
    cout << s.makesquare(v) << endl;
    v = {1,1,2,2,1,1};
    cout << s.makesquare(v) << endl;
    v = {3,3,3,3,4};
    cout << s.makesquare(v) << endl;
    v = {5,5,5,5,4,4,4,4,3,3,3,3};
    cout << s.makesquare(v) << endl;
    v = {16,3,16,12,13,5,3,1,10,18,5,16,17,1,10};
    cout << s.makesquare(v) << endl;
    return 0;
}
