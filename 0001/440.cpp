#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int prefixCount(int p, int n) {
        if (p > n) return 0;
        int res = 1;
        for (int i=0; i<10; i++) res+=prefixCount(10*p+i, n);
        return res;
    }


    int findKthNumber(int n, int k) {
        int p = 1;
        k--;
        while (k > 0) {
            int c = prefixCount(p, n);
            if (k < c) {
                p *= 10;
                k--;
            } else {
                k -= c;
                p++;
            }
        }

        return p;
    }
};


int main() {
    Solution s;

    //[1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9]
    cout << s.findKthNumber(13, 2) << " = 10" << endl;
    return 0;
}
