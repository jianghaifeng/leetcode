#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <set>

using namespace std;

class Solution {
public:
    void out(multiset<int>& s, int n) {
        auto it = s.find(n);
        s.erase(it);
    }

    void in(multiset<int>& s, int n) {
        s.insert(n);
    }

    vector<double> even(vector<int>& nums, int k) {
        vector<int> tmpv(nums.begin(), nums.begin() + k);
        sort(tmpv.begin(), tmpv.end());
        multiset<int> left;
        multiset<int> right;
        int i = 0;
        for (; i<k/2; i++) left.insert(tmpv[i]);
        for (; i<k; i++) right.insert(tmpv[i]);

        vector<double> res;
        i = 0;
        while (true) {
            debug(left, right);
            res.push_back(((double)(*left.rbegin()) + *right.begin())/2);
            
            if (i+k >= nums.size()) break;
            
            if (nums[i] <= *left.rbegin()) out(left, nums[i]);
            else out(right, nums[i]);

            cout << left.size() << "," << nums[i+k] << endl;

            if (left.size() > 0 && nums[i+k] <= *left.rbegin()) {
                in(left, nums[i+k]);
                if (left.size() > right.size()) {
                    int itmp = *left.rbegin();
                    out(left, itmp);
                    in(right, itmp);
                }
            } else {
                in(right, nums[i+k]);
                if (left.size() < right.size()) {
                    int itmp = *right.begin();
                    out(right, itmp);
                    in(left, itmp);
                }
            }
            i++;
        }

        return res;
    }

    vector<double> odd(vector<int>& nums, int k) {
        vector<int> tmpv(nums.begin(), nums.begin() + k);
        sort(tmpv.begin(), tmpv.end());
        multiset<int> left;
        multiset<int> right;
        int mid;
        int i = 0;
        for (; i<k/2; i++) left.insert(tmpv[i]);
        mid = tmpv[i++];
        for (; i<k; i++) right.insert(tmpv[i]);

        vector<double> res;
        i = 0;
        while (true) {
            debug(left, right);
            cout << "mid=" << mid << endl;
            res.push_back(mid);
            
            if (i+k >= nums.size()) break;
            
            if (nums[i] < mid) out(left, nums[i]);
            else if (nums[i] > mid) out(right, nums[i]);

            if (left.size() < right.size()) in(left, mid);
            else if (left.size() > right.size()) in(right, mid);

            if (left.size() > 0 && nums[i+k] <= *left.rbegin()) {
                in(left, nums[i+k]);
                mid = *left.rbegin();
                out(left, mid);
            } else if (right.size() > 0 && nums[i+k] >= *right.begin()) {
                in(right, nums[i+k]);
                mid = *right.begin();
                out(right, mid);
            } else mid = nums[i+k];
            i++;
        }

        return res;

    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if (k % 2 == 0) return even(nums, k);
        else return odd(nums, k);
    }

    void debug(multiset<int>& left, multiset<int>& right) {
        cout << "left:";
        for (auto i : left) {
            cout << i << " ";
        }
        cout << endl << "right:";
        for (auto i : right) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<int> v = {4,3,6,2,8,9,1,5,7};
    vector<double> res = s.medianSlidingWindow(v, 4);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    res = s.medianSlidingWindow(v, 5);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    v = {1,2};
    res = s.medianSlidingWindow(v, 1);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    v= {2147483647,1,2,3,4,5,6,7,2147483647};
    res = s.medianSlidingWindow(v, 2);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
