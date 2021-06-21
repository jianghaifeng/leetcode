#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool helper(vector<int>& nums, int i, vector<int>& flags) {
        unordered_set<int> s;
        int forward = (nums[i] > 0) ? 1 : -1;

        s.insert(i);
        while (true) {
            int next = nextIndex(nums, i); 
            cout << "i=" << i  << " next=" << next << endl;
            if (next == i || nums[next] * forward < 0) {
                for (auto n : s) flags[n] = -1;
                return false;
            }
            if (s.find(next) != s.end()) return true;
            s.insert(next);
            i = next;
        }
    }
    bool circularArrayLoop(vector<int>& nums) {
        int len = nums.size();
        vector<int> flags(len, 0);

        for (int i=0; i<len; i++) {
            if (flags[i] == -1) continue;
            if (helper(nums, i, flags)) return true;
        }
        return false;
    }

    int nextIndex(vector<int>& nums, int index) {
        int len = nums.size();
        int nextIndex = index + nums[index];
        if (nextIndex >= 0) return nextIndex % len;

        return (nextIndex % len) + len;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {1};
    assert(false == s.circularArrayLoop(v));
    v = {1,3};
    assert(true == s.circularArrayLoop(v));
    v = {2,-1,1,2,2};
    assert(true == s.circularArrayLoop(v));
    v = {-1,2};
    assert(false == s.circularArrayLoop(v));
    v = {-2,1,-1,-2,-2};
    assert(false == s.circularArrayLoop(v));
    return 0;
}
