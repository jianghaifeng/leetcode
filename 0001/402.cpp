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
        while (newnum[0] == '0' && newnum.size() > 1) newnum = newnum.substr(1);

        cout << newnum << endl;

        return removeOne(newnum, k-1);
    }
    
    string looping(string num, int k) {
        int cur = 0;
        while (k > 0 && num.size() > 0) {
            if (cur < num.size() -1 && num[cur] > num[cur+1]) {
                cout << "remove: " << num[cur] << endl;
                num.erase(cur, 1);
                if (cur == 0) {
                    while (num[0] ==  '0') num.erase(0,1);
                } else cur--;
                k--;
            } else if (cur == num.size()) {
                num.pop_back();
                cout << "remove: " << num[cur] << endl;
                cur--;
                k--;
            } else cur++;
        }

        if (num.size() == 0) return "0";
        return num;
    }

    string loopingNew(string num, int k) {
        int cur = 0;
        string res;
        while (k > 0 || cur < num.size()) {
            cout << "res=" << res << "(" << res.length() << ")" << ";cur=" << cur << ";k=" << k << endl;
            if (res.size() == 0) {
                if (cur >= num.size()) k--;
                else if (num[cur] != '0') res.push_back(num[cur++]);
                else cur++;
            } else {
                if (k <= 0 || (cur < num.size() && res.back() <= num[cur])) res.push_back(num[cur++]);
                else {
                    if (res.length() > 0) res.pop_back(); 
                    k--;
                }
            }
        }

        cout << "result=" << res.length() << endl;

        if (res.size() == 0) return "0";
        return res;
    }

    string removeKdigits(string num, int k) {
        return loopingNew(num, k);
        //return removeOne(num, k);
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
    cout << s.removeKdigits("1432", 5) << endl;
    cout << s.removeKdigits("10200", 1) << endl;
    cout << s.removeKdigits("100200", 1) << endl;

    return 0;
}


