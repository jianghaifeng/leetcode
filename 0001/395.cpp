#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    int helper(const string& s, int start, int end, int k) {
        cout << "start=" << start << " end=" << end << endl;
        if (end-start < k) return 0;
        vector<int> v(26,0);
        for (int i=start; i<end; i++) v[s[i]-'a']++;
        string invalidChars;
        for (int i=0; i<26; i++) {
            if (v[i] > 0 && v[i] < k) invalidChars.push_back('a'+i);
        }
        if (invalidChars.length() == 0) return end-start;

        int pos = start;
        int maxlen = 0;
        while (pos < end) {
            size_t nextpos = s.find_first_of(invalidChars, pos);
            if (nextpos == string::npos) nextpos = s.length();
            int len = helper(s, pos, nextpos, k);
            if (len > maxlen) maxlen = len;
            pos = nextpos+1;
        }
        return maxlen;
    }

    int longestSubstring(string s, int k) {
        if (k <= 1) return s.length();

        return helper(s, 0, s.length(), k);
    }
};

int main() {
    Solution s;
    cout << s.longestSubstring("aaabb", 3) << endl;
    cout << s.longestSubstring("ababbc", 2) << endl;
    return 0;
}
