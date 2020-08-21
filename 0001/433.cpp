#include <iostream>
#include <vector>
#include <set>

using namespace std;
class Solution {
public:
    bool isMutable(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        int diff = 0;
        for (int i=0; i<s1.length(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff == 1;
    }

    set<string> findNextMutation(set<string>& cur, set<string>& bank) {
        set<string> next;
        for (auto s : cur) {
            for (auto ms : bank) {
                if (isMutable(s, ms)) {
                    next.insert(ms);
                }
            }
        }

        for (auto s : next) bank.erase(s); 

        return next;
    }

    int minMutation(string start, string end, vector<string>& bank) {
        int res = 0;

        set<string> cur;
        set<string> next;
        set<string> bankSet(bank.begin(), bank.end());

        if (bankSet.find(end) == bankSet.end()) return -1;

        cur.insert(start);

        do {
            next = findNextMutation(cur, bankSet);
            cur = next;
            res++;
            if (next.size() == 0) return -1;
        } while (next.find(end) == next.end());

        return res;
    }
};

void test1() {
    Solution s;
    string start = "AACCGGTT";
    string end = "AACCGGTA";
    vector<string> bank = {"AACCGGTA"};

    cout << s.isMutable(start, end) << " = true" << endl;

    cout << s.minMutation(start, end, bank) << " = 1" << endl;
}

void test2() {
    Solution s;
    string start = "AACCGGTT";
    string end = "AAACGGTA";
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};

    cout << s.minMutation(start, end, bank) << " = 2" << endl;
}


void test3() {
    Solution s;
    string start = "AAAAACCC";
    string end = "AACCCCCC";
    vector<string> bank = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};

    cout << s.minMutation(start, end, bank) << " = 3" << endl;
}
int main() {
    test1();
    test2();
    test3();
    return 0;
}
