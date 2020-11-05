#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for (auto i : nums) {
            if (nums[abs(i)-1] > 0)
                nums[abs(i)-1] = -1 * nums[abs(i)-1];
        }
        vector<int> res;
        for (int i=0; i<len; i++) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

void output(vector<int> v) {
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {4,3,2,7,8,3,2,1};
    Solution s;
    output(s.findDisappearedNumbers(v));
}
