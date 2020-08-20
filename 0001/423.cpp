#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
    char _c[10] = { 'z', 'x', 's', 'v', 'f', 'r', 'h', 'w', 'i', 'o'};
    int _n[10] = {0, 6, 7, 5, 4, 3, 8, 2, 9, 1};
    string _s[10] = {"zero", "six", "seven", "five", "four", "three", "eight", "two", "nine", "one"};

public:
    bool originalDigitsHelper(int all[], int i) {
        if (all[_c[i]-'a'] == 0) return false;
        for (auto c : _s[i]) {
            all[c-'a']--;
        }
        return true;
    }

    string originalDigits(string s) {
        int all[26] = {0};
        for (auto c : s) {
            all[c-'a']++;
        }

        string res;
        for (int i=0; i<10; i++) {
            while (originalDigitsHelper(all, i)) {
                res.append(to_string(_n[i]));
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.originalDigits("owoztneoer") << endl;
    cout << s.originalDigits("fviefuro") << endl;
    cout << s.originalDigits("zerozero") << endl;
    cout << s.originalDigits("zeroonetwothreefourfivesixseveneightnine") << endl;
    return 0;
}
