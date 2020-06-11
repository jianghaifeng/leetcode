#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string removeOne(string num, int k) {
        if (k == 0) return num;
        if (num.size() < 1) return "0";

        int i = 0;
        for (i=0; i<num.size()-1; i++) {
            if (num[i] > num[i+1]) {
                break;
            }
        }

        string newnum;
        newnum.append(num.substr(0, i));
        newnum.append(num.substr(i+1));
        if (newnum[0] == '0' && newnum.size() > 1) newnum = newnum.substr(1);

        cout << newnum << endl;

        return removeOne(newnum, k-1);
    }

    string removeKdigits(string num, int k) {
        return removeOne(num, k);
    }
};

/*
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/

int main() {

    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    cout << s.removeKdigits("10200", 1) << endl;

    return 0;
}


