#include <iostream>
#include <vector>

using namespace std;

void output(const vector<vector<int>>& vv) {
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

bool compareFunc(const vector<int>& v1, const vector<int>& v2) {
    return (v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] > v2[1]);
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), compareFunc);
        for (auto& v : people) {
            v.push_back(v.back());
        }
        vector<vector<int>> res;
        int i=0, j=0, k=0;
        bool forward = false;

        while (people.size() > 0) {
            if (!forward) {
                while (i < people.size() && people[i][2] != 0) ++i;
            } else i = k;

            if (people.size() <= i) break;

            people[i].pop_back();
            res.push_back(people[i]);
            people.erase(people.begin()+i);

            forward = false;
            j = i-1;
            while (j >= 0) {
                people[j][2]--;
                if (people[j][2] == 0) {
                    forward = true;
                    k = j;
                }
                j--;
            }
        }
        
        output(res);
        return people;
    }
};


int main() {
    Solution s;
    vector<vector<int>> vv;
    vector<int> v;
    v = {7,0}; vv.push_back(v);
    v = {4,4}; vv.push_back(v);
    v = {7,1}; vv.push_back(v);
    v = {5,0}; vv.push_back(v);
    v = {6,1}; vv.push_back(v);
    v = {5,2}; vv.push_back(v);
    s.reconstructQueue(vv);
}
