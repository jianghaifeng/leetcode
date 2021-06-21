#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string res = "";
        int l = s.length() - 1;
        int w = k;
        while (l >= 0) {
            if (s[l] != '-') {
                if (w == 0) {
                    res += '-';
                    w = k;
                }
                w--;
                res += (char)toupper(s[l]);
            }
            l--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.licenseKeyFormatting("5F3Z-2e-9-w", 4) << "==" << "5F3Z-2E9W" << endl;
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << "==" << "2-5G-3J" << endl;
    cout << s.licenseKeyFormatting("2-5g-3-J", 2) << "==" << "2-5G-3J" << endl;
    cout << s.licenseKeyFormatting("2-5g-3-J", 5) << "==" << "25G3J" << endl;
    cout << s.licenseKeyFormatting("2-5g-3-J", 6) << "==" << "25G3J" << endl;
    cout << s.licenseKeyFormatting("-a-a-a-a", 2) << "==" << "AA-AA" << endl;
    return 0;
}
