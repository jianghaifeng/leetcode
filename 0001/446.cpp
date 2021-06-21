#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_multimap<int, int>> mv;
        unordered_multimap<int, int> m;
        mv.push_back(m);
        int len = A.size();
        int total = 0;
        if (len <= 2) return 0;
        for (int i=1; i<len; i++) {
            unordered_multimap<int, int> im;
            for (int j=0; j<i; j++) {
                auto jm = mv[j];
                int arithmetic = A[i]-A[j];
                if (jm.count(arithmetic) != 0) {
                    auto range = jm.equal_range(arithmetic);
                    for (auto it = range.first; it != range.second; it++) {
                        im.insert(make_pair(it->first, it->second+1));
                        total += it->second+1;
                               
                    }
                } else im.insert(make_pair(arithmetic, 0));
            }
            mv.push_back(im);
        }
        return total;
    }
    int helper(vector<int>& A, int n) {
        int len = A.size();
        int p = A[n];
        int total = 0;
        if (n+1 >= len) return total;
        for (int i=n+1; i<len; i++) {
            int q = A[i];
            int d = q-p;
            int j = i+1;
            int prev = q;
            int num = 0;
            while (j < len) {
                if (A[j] == prev+d) {
                    num++;
                    prev = A[j];
                }
                j++;
            }
            total += num;
        }
        return total;
    }
    int numberOfArithmeticSlices_old(vector<int>& A) {

        int total = 0;
        for (int i=0; i<A.size(); i++) {
            total += helper(A, i);
        }
        return total;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {1,1,1,1};
    cout << "5=" << s.numberOfArithmeticSlices(v) << endl;
    v = {1,1,2,3};
    cout << "2=" << s.numberOfArithmeticSlices(v) << endl;
    v = {1,2,4};
    cout << "0=" << s.numberOfArithmeticSlices(v) << endl;
    v = {1,2,3};
    cout << "1=" << s.numberOfArithmeticSlices(v) << endl;
    v = {1,2,3,3};
    cout << "2=" << s.numberOfArithmeticSlices(v) << endl;
    v = {2,4,6,8,10};
    cout << "7=" << s.numberOfArithmeticSlices(v) << endl;
    v = {2,4,6,8,10,12};
    cout << "12=" << s.numberOfArithmeticSlices(v) << endl;
    return 0;
}
