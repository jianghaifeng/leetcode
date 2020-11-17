#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    bool helper(unordered_map<int, unordered_set<string>>& ism, string word, bool isSelf) {
        if (!isSelf && ism[word.length()].count(word) > 0) return true;
        for (int i=1; i<word.length(); i++) {
            string first = word.substr(0, i);
            string second = word.substr(i);
            if (ism[i].size() == 0) continue;
            if (ism[i].count(first) == 0) continue;
            if (helper(ism, second, false)) return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<int, unordered_set<string>> ism;

        for (auto word : words) {
            ism[word.length()].insert(word);
        }

        //for (auto e : ism) {
        //    cout << e.first << ":";
        //    for (auto s : e.second) {
        //        cout << s << ",";
        //    }
        //    cout << endl;
        //}

        vector<string> res;
        for (auto word : words) {
            if (helper(ism, word, true)) res.push_back(word);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<string> v = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"};
    vector<string> res = s.findAllConcatenatedWordsInADict(v);
    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
