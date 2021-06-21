#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int m = 0;
        int n = 0;
        int i = 0;
        nums.push_back(0);

        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == 0) {
                if (n > m) m = n;
                n = 0;
            }
            else n++;
        }
        return m;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {1,1,0,1,1,1};
    cout << s.findMaxConsecutiveOnes(v) << "==" << 3 << endl;
    v = {1,0,1,1,0,1};
    cout << s.findMaxConsecutiveOnes(v) << "==" << 2 << endl;

    return 0;
}
