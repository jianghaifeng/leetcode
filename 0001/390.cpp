#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int helper(const int& n, vector<int>& v, int interval, bool forward) {
        int start = 0;
        if (forward) {
            for (start=1; start<=n; start++) {
                if (v[start] != 0) break;
            }
            if (start+interval/2 > n) return start;
            while (start <= n) {
                cout << start << " ";
                v[start] = 0;
                start+=interval;
            }
        } else {
            for (start=n; start>0; start--) {
                if (v[start] != 0) break;
            }
            if (start-interval/2 < 1) return start;
            while (start >= 1) {
                cout << start << " ";
                v[start] = 0;
                start-=interval;
            }
        }
        cout << endl;
        return helper(n, v, interval*2, !forward);
    }
    int lastRemaining(int n) {
        vector<int> v(n+1,1);
        return helper(n, v, 2, true);
    }
};

int main() {
    Solution s;
    cout << s.lastRemaining(100) << endl;
    return 0;
}
