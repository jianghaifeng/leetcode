#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<string> splitStringByChar(const string input, const char c) {
        vector<string> vs;
        size_t pos = 0;
        while (true) {
            size_t next = input.find(c, pos);
            if (next == string::npos) {
                vs.push_back(input.substr(pos));
                break;
            }
            vs.push_back(input.substr(pos, next-pos));
            pos = next+1;
        }
        return vs;
    }


    void debug(vector<string> vs) {
        for (auto s : vs) {
            cout << "(" << startTabs(s) << ")"  <<  s << endl;
        }
    }

    int startTabs(string& s) {
        int n = 0;
        for (auto c : s) {
            if (c != '\t') break;
            n++;
        }
        s=s.substr(n);
        return n;
    }

    int lengthLongestPath(string input) {
        vector<int> vlen = {0};
        int maxlen = 0;
        vector<string> vs = splitStringByChar(input, '\n');

        for (auto s : vs) {
            int a = startTabs(s);
            int slen = s.length();
            cout << "s=" << s << " a="  << a << " slen=" << slen << endl;
            if (a == 0) vlen[a] = slen;
            else if (a > vlen.size()) return -1;
            else if (a == vlen.size()) vlen.push_back(vlen.back()+slen+1);
            else vlen[a] = vlen[a-1] + slen + 1;

            if (s.find('.') != string::npos && maxlen < vlen[a]) maxlen = vlen[a];
        }

        return maxlen;
    }
};

int main() {
    Solution s;
    cout << s.lengthLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") << endl;
    return 0;
}

