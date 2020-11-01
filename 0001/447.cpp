#include <vector>
#include <iostream>

using namespace std;

void output(vector<vector<long long>> vv);
void output(vector<long long> v);

class Solution {
public:
    long long distance(vector<int> v1, vector<int> v2) {
        long long dist = pow(v2[0]-v1[0], 2) + pow(v2[1]-v1[1], 2);
        return dist;
    }

    int factorial(int n) {
        return n*(n-1);
    }

    int findSameNumbers(vector<long long> nums) {
        int total = 0;
        sort(nums.begin(), nums.end());
        int n = 1;
        for (int i=1; i<=nums.size(); i++) {
            if (i != nums.size() && nums[i] == nums[i-1]) n++;
            else {
                if (n > 1) 
                    total += factorial(n);
                n = 1;
            }
        }
        return total;
    }

    int numberOfBoomerangs(vector<vector<int>>& points) {
        int len = points.size();
        if (len < 3) return 0;
        int total = 0;

        vector<vector<long long>> distances(len, vector<long long>(len, 0));
        output(distances);

        for (int i=0; i<len; i++) {
            distances[i][i] = 0;
            for (int j=i+1; j<len; j++) {
                distances[i][j] = distance(points[j], points[i]);
                distances[j][i] = distances[i][j];
            }
            output(distances[i]);
            total += findSameNumbers(distances[i]);
            cout << "total=" << total << endl;
        }

        return total;
    }
};

void output(vector<long long> v) {
    for (auto i : v) {
        cout << i << "\t";
    }
    cout << endl;
}

void output(vector<vector<long long>> vv) {
    cout << "======================" << endl;
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << "\t";
        }
        cout << endl;
    }
    cout << "======================" << endl;
}

void test2() {
    Solution s;
    vector<int> v;
    vector<vector<int>> vv;
    v = {3,4};
    vv.push_back(v);
    v = {0,0};
    vv.push_back(v);
    v = {0,5};
    vv.push_back(v);
    v = {5,0};
    vv.push_back(v);
    assert(6 == s.numberOfBoomerangs(vv));
}

void test1() {
    Solution s;
    vector<int> v;
    vector<vector<int>> vv;
    v = {0,1};
    vv.push_back(v);
    v = {0,0};
    vv.push_back(v);
    v = {0,2};
    vv.push_back(v);
    assert(2 == s.numberOfBoomerangs(vv));
}

int main() { 
    test1();
    test2();
}
