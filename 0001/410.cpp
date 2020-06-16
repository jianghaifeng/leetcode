#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // approach 1: recurse without cache
    int helper(vector<int>& nums, int n, int m) {
        if (n + m == nums.size()) {
            return *max_element(nums.begin()+n, nums.end());
        }

        int sum = 0;
        for (int i=n; i<nums.size(); i++) sum += nums[i];
        if (m == 1) return sum;

        int i = n, k = 0, h = 0, min = sum;
        for (i=n; i<nums.size(); i++) {
            k += nums[i];
            h = helper(nums, i+1, m-1);
            if (max(k, h) < min) min = max(k, h);
            if (k > min) break;
        }

        return min;
    }


    //approach 2: dp in forward direction
    /*
     *    7,  2,  5,  10,  3,  2,  6,  4,  5,  3,  8,  8
     * 1  7,  9, 14,  24, 27, 29, 35, 39, 44, 47, 55, 63
     * 2      7,  7,  14, 14, 15, 21, 24, 24, 24, 28, 34  
     * 3          7,  10, 13, 14, 14, 14, 15, 18, 21, 24
     * 4              10, 10, 10, 11, 13, 14, 14, 15, 18 
     * 5                  10, 10, 10, 10, 11, 12, 14, 18
     */
    int helper2(vector<int>& nums, int m)  {
        vector<vector<int>> vv(m, vector<int>(nums.size(), 0));
        vv[0][0] = nums[0];
        for (int i=1; i<nums.size(); i++) vv[0][i] = vv[0][i-1] + nums[i];

        for (int i=1; i<m; i++) {
            cout << i << ":";
            for (int j=i; j<nums.size(); j++) {
                int t = nums[j], h;
                int min = max(nums[j], vv[i-1][j-1]);
                for (int k=j-1; k>=i; k--) {
                    t += nums[k];
                    if (t > min) break;
                    h = max(t, vv[i-1][k-1]);
                    if (h < min) min = h;
                }
                cout << min << " ";
                vv[i][j] = min;
            }
            cout << endl;
        }

        return vv[m-1][nums.size()-1];
    }

    
    //approach 3: recursive with cache
    int splitArray(vector<int>& nums, int m) {
        if(m > nums.size()) return 0;
        //return helper(nums, 0, m);
        return helper2(nums, m);
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {7,2,5,10,8};
    cout << s.splitArray(v,2) << endl;
    v =  {7,2,5,10,3,2,6,4,5,3,8,8};
    cout << s.splitArray(v,5) << endl;
    return 0;
}
