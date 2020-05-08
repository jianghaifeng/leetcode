#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void helper(const int& n, int cur, vector<int>& res) {
        cout << "cur=" << cur << endl;
        if (cur > n) return;
        res.push_back(cur);
        helper(n, cur*10, res);
        if (cur % 10 != 9) helper(n, cur+1, res);
    }
    vector<int> lexicalOrder(int n) {
        vector<int> v;
        helper(n, 1, v);

        return v;
    }
};

int main() {
    Solution s;
    vector<int> v = s.lexicalOrder(247);

    for (auto i : v) {
        cout << i << endl;
    }

    return 0;
}
