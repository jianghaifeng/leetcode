#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int comparePair(const pair<char, int>& p1, const pair<char, int>& p2) {
    return p1.second > p2.second;
}

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }

        vector<pair<char,int>> vp;

        for (auto const& x : m) {
            vp.push_back(x);
        }

        sort(vp.begin(), vp.end(), comparePair);

        for (auto p : vp) {cout << p.first << "," << p.second << endl;}

        string res;
        for (auto p : vp) {
            for (int i=0; i<p.second; i++) res.push_back(p.first);
        }

        return res;
    }

};

void test1() {
    Solution s;
    cout << "aabc => " << s.frequencySort("aabc") << endl;
    cout << "abcc => " << s.frequencySort("abcc") << endl;
    cout << "ab => " << s.frequencySort("ab") << endl;
}

int main() {
    test1();
    return 0;
}
