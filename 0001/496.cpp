#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        unordered_map<int, int> um;
        for (auto i : nums2) {
            auto pos = s.insert(i);
            for (auto it = s.begin(); it != pos.first; it++) {
                cout << "got:" << *it << "=" << i << endl;
                um[*it] = i;
                s.erase(it);
            }
        }

        vector<int> ret;
        for (auto k : nums1) {
            if (s.count(k) != 0)
                ret.push_back(-1);
            else ret.push_back(um[k]);
        }

        return ret;
    }
};

void print(vector<int>& v) {
    for (auto i : v) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {   
    Solution s;
    vector<int> nums1, nums2;
    nums1 = {4,1,2};
    nums2 = {1,3,4,2};
    auto out = s.nextGreaterElement(nums1, nums2);
    print(out);

    nums1 = {2,4};
    nums2 = {1,2,3,4};
    out = s.nextGreaterElement(nums1, nums2);
    print(out);
}
