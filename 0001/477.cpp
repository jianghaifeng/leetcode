#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total = 0;
        int num = 1;
        int bit0 = 0;
        int bit1 = 0;

        if (nums.size() < 2) return 0;

        int max = *max_element(nums.begin(), nums.end());
        
        while (num <= max) {
            bit0 = 0;
            bit1 = 0;
            for (auto n : nums) {
                if ((n & num) == 0) bit0++;
                else bit1++;
            }
            total += (bit0 * bit1);
            num = num << 1;
        }

        return total;
        
    }
};

int main() {
    Solution s;
    vector<int> v = {4,14,2};
    cout << s.totalHammingDistance(v) << endl;
}
