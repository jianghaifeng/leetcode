#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int total = 0;
        for (auto i : nums) {
            total += (i-nums[0]);
        }
        return total;
    }
};

void test1() {
    Solution s;
    vector<int> v = {1,2,3};
    assert(s.minMoves(v) == 3);
}

int main() {

    test1();
    return 0;
}
