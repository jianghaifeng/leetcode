#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        int i=0, k=0;
        while (n > k) {
            n -= k;
            k += pow(10, i) * 9 * (i+1);
            i++;
        }

        int start = pow(10, i-1);
        //cout << "start = " << start << endl;
        int pos = (n - 1)/i + start;
        //cout << "num = " << pos << endl;
        int digit = i - ((n-1) % i) - 1;
        //cout << "digit = " << digit << endl;

        int res = (int)(pos / pow(10, digit)) % 10;

        return res;
    }
};

int main() {
    Solution s;
    cout << s.findNthDigit(8) << " = 8" << endl;
    cout << s.findNthDigit(9) << " = 9" << endl;
    cout << s.findNthDigit(10) << " = 1" << endl;
    cout << s.findNthDigit(11) << " = 0" << endl;
    cout << s.findNthDigit(128) << " = 6" << endl;
    cout << s.findNthDigit(500) << " = 0" << endl;
    cout << s.findNthDigit(501) << " = 3" << endl;
    cout << s.findNthDigit(502) << " = 2" << endl;
    cout << s.findNthDigit(30000) << " = 7" << endl;
    cout << s.findNthDigit(30001) << " = 7" << endl;
    cout << s.findNthDigit(30002) << " = 7" << endl;
    return 0;
}
