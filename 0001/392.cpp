#include <map>
#include <set>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    
    bool isSubsequence(string s, string t) {
        map<char, set<int>> m;
        int slen = s.length(), tlen = t.length();
        for (int i=0; i<tlen; i++) {
            m[t[i]].insert(i);
        }
        
        int lastPos = -1;
        
        for (int j=0; j<slen; j++) {
            if (m.find(s[j]) == m.end()) return false;
            auto pos = m[s[j]].upper_bound(lastPos);
            if (pos == m[s[j]].end()) return false;
            lastPos = *pos;
        }
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isSubsequence("abc", "ahbgdc") << endl;
    cout << s.isSubsequence("axc", "ahbgdc") << endl;
    return 0;
}
