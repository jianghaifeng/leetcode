#include <iostream>
#include <list>

using namespace std;
class Solution {
public:
    int getMostChar(int all[]) {
        int res = 0;
        for (int i=0; i<26; i++) {
            if (all[i] > res) {
                res = all[i];
            }
        }

        return res;
    }

    int characterReplacement(string s, int k) {
        int all[26] = {0};
        int res = 0;
        int start=0, end=0;

        while (end <= s.length()) {
            int mostChar = getMostChar(all);
            if (end-start-mostChar <= k) {
                if (res < end-start) res = end-start;
                if (end < s.length()) all[s[end]-'A']++;
                end++;
            } else {
                all[s[start]-'A']--;
                start++;
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    cout << s.characterReplacement("ABAB", 2) << endl;
    cout << s.characterReplacement("AABABBA", 1) << endl;
    return 0;
}
