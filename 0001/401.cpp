#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    static vector<vector<int>> numbers(int max) {
        vector<int> v(max, 0);
        int i=1, digit=0;

        while (i < max) {
            digit++;
            for (int j=1; j<max; j++) {
                if ((j&i) != 0) v[j]++;
            }
            i <<= 1;

            cout << i << endl;
        }

        cout << "digit=" << digit << endl;

        vector<vector<int>> vv(digit+1, vector<int>());

        for (int i=0; i<max; i++) {
            vv[v[i]].push_back(i);
        }
        return vv;
    }

    static vector<vector<int>> hours() {
        return numbers(12);
    }

    static vector<vector<int>> minutes() {
        return numbers(60);
    }

    void output(vector<vector<int>> vv) {
        cout << "================" << endl;
        for (auto v : vv) {
            for (auto i : v) {
                cout << i << ", ";
            }
            cout << endl;
        }
    }

    vector<string> readBinaryWatch(int num) {
        vector<string> v;
        vector<vector<int>> vvh = hours();
        vector<vector<int>> vvm = minutes();

        output(vvh);
        output(vvm);
        for (int h=0; h<=num; h++) {
            int m = num-h;
            if (h < vvh.size() && m < vvm.size()) {
                for (auto i : vvh[h]) {
                    for (auto j : vvm[m]) {
                        ostringstream oss;
                        oss << i << ':' << setfill('0') << setw(2) << j;
                        v.push_back(oss.str());
                    }
                }
            }
        }

        return v;
    }

};


int main() {
    Solution s;
    vector<string> v = s.readBinaryWatch(0);
    for (auto s : v) {
        cout << s << endl;
    }
    return 0;
}
