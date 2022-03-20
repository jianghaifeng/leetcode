#include <vector>
#include <map>
#include <iostream>

using namespace std;

void print(vector<int>& v) {
    for (auto i : v) {
	cout << i << ",";
    }
    cout << endl;
}

void printmap(map<int, int>& m) {
    for (auto p : m) {
        cout << "[" << p.first << "," << p.second << "], ";
    }
    cout << endl;
}

class Solution {
public:
    map<int, int> reconcile(map<int, int>& input, int num) {
        map<int, int> output;
        for (auto p : input) {
            output[p.first + num] += input[p.first];
            output[p.first - num] += input[p.first];
        }
        return output;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        map<int, int> m;
        m[0] = 1;
        for (auto i : nums) {
            m = reconcile(m, i);
        }

        return m[target];
    }
    int findTargetSumWays1(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return (target == nums[0] || -target == nums[0])?1:0;
        int a = nums.back();
        nums.pop_back();
        int b = findTargetSumWays(nums, target+a);
        nums.push_back(a);
        nums.pop_back();
        int c = findTargetSumWays(nums, target-a);
        nums.push_back(a);
        return b+c;
    }
};


int main() {
    Solution s;
    vector<int> v = {1,1,1,1,1};
    cout << "5=" << s.findTargetSumWays(v, 3);
}
