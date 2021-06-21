#include <string>

using namespace std;
class Solution {
public:
    bool helper(const string& s, int num) {
        string sub = s.substr(0, num);
        for (int i=num; i<s.length(); i+=num) {
            if (s.substr(i, num) != sub) return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for (int i=1; i<=len/2; i++) {
            if (len % i != 0) continue;
            if (helper(s, i)) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    assert(s.repeatedSubstringPattern("abab") == true);
    assert(s.repeatedSubstringPattern("abcabc") == true);
    assert(s.repeatedSubstringPattern("abcab") == false);
    assert(s.repeatedSubstringPattern("aa") == true);
    assert(s.repeatedSubstringPattern("a") == false);
    assert(s.repeatedSubstringPattern("") == false);
}
