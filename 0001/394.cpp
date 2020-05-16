/**
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 */

#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string nextOne(bool isNumber, const string& s, int& pos) {
        string res;
        int next = s.find_first_of(isNumber?"[":"123456789]", pos);
        if (next >= s.length()) {
            res = s.substr(pos);
            pos = s.length();
        } else {
            res = s.substr(pos, next-pos);
            pos = next;
        }
        return res;

    }

    void push_back(vector<string>& vs, string s, bool isNumber) {
        if (!isNumber && vs.size() > 0 && isalpha(vs.back().at(0)))
            vs.back().append(s);
        else vs.push_back(s);
    }

    string decodeString(string s) {
        int len = s.length(), pos = 0;
        vector<string> vs;

        while (pos < len) {
            if (isdigit(s[pos])) {
                push_back(vs, nextOne(true, s, pos), true);
            }
            else if (isalpha(s[pos])) {
                push_back(vs, nextOne(false, s, pos), false);
            }
            else if (s[pos] == '[') pos++;
            else if (s[pos] == ']') {
                string repeat = vs.back();
                vs.pop_back();
                int times = stoi(vs.back());
                vs.pop_back();
                string news;
                while (times > 0) {
                    news.append(repeat);
                    times--;
                }
                push_back(vs, news, false);
                pos++;
            }
        }
        return vs[0];
    }
};

int main() {
    Solution s;
    int pos = 0;
    //cout << s.nextNum("3[a]2[bc]", pos) << endl;
    //cout << s.decodeString("3[a]2[bc]") << endl;
    //cout << s.decodeString("3[a2[c]]") << endl;
    //cout << s.decodeString("3[a2[bc]]") << endl;
    //cout << s.decodeString("2[abc]3[cd]ef") << endl;
    cout << s.decodeString("2[a3[b2[c]]d]") << endl;
    return 0;
}
