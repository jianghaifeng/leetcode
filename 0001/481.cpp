#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        int i = 2;
        int j = 2;
        while (j < n) {
            if (s[i] == '1') {
                s += (s[j]=='1') ? "2" : "1";
                j+=1;
            }
            else {
                s += (s[j]=='1') ? "22" : "11";
                j+=2;
            }
            i++;
        }

        int total = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') total += 1;
        }

        return total;
    }
};

int main() {
    Solution s;
    s.magicalString(30);
    assert(s.magicalString( 1) == 1);
    assert(s.magicalString( 2) == 1);
    assert(s.magicalString( 3) == 1);
    assert(s.magicalString( 4) == 2);
    assert(s.magicalString( 5) == 3);
    assert(s.magicalString( 6) == 3);
    assert(s.magicalString( 7) == 4);
    assert(s.magicalString( 8) == 4);
    assert(s.magicalString( 9) == 4);
    assert(s.magicalString(10) == 5);
    assert(s.magicalString(11) == 5);
    assert(s.magicalString(12) == 5);
    assert(s.magicalString(13) == 6);
    assert(s.magicalString(14) == 7);
    assert(s.magicalString(15) == 7);


}
