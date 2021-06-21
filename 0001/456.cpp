#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {val = x; left = NULL; right = NULL;}
};

class Solution {
public:
    bool inVp(int i, const vector<pair<int, int>>& vp) {
        for (auto p : vp) {
            if (p.first < i && p.second > i) return true;
        }
        return false;
    }

    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1]) i++;
        if (i == nums.size()) return false;

        bool inc = nums[i] > nums[i-1];
        int imin = nums[i-1];
        vector<pair<int, int>> vp;

        while (true) {
            if (++i >= nums.size()) return false;

            if (nums[i] == nums[i-1]) {
                continue;
            }
            else if (nums[i] > nums[i-1]) {
                cout << "1inc=" << inc << " num=" << nums[i] << endl;
                if(!inc) imin = nums[i-1];
                inc = true;
            } else {
                cout << "2inc=" << inc << " num=" << nums[i] << endl;
                if (inc) vp.push_back(make_pair(imin, nums[i-1]));
                inc = false;
            }
            if (inVp(nums[i], vp)) return true;
        }
        return false;
    }
};

int main() {
    vector<int> v;
    Solution s;
    v = {1,2,3,4};
    assert(false == s.find132pattern(v));
    v = {3,1,4,2};
    assert(true == s.find132pattern(v));
    v = {-1,3,2,0};
    assert(true == s.find132pattern(v));
    return 0;
}
