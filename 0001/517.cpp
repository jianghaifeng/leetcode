#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        vector<int> l(machines.size()+1);
        vector<int> r(machines.size()+1);
        int sum = 0, avg = 0;
        for (auto i : machines) {
            sum += i;
        }
        if (sum % machines.size() != 0) return -1;
        avg = sum / machines.size();

        int tmpSum = 0, tmpExp = 0;
        for (int i=0; i<machines.size(); i++) {
            tmpExp += avg;
            tmpSum += machines[i];

            if (tmpSum < tmpExp) l[i+1] = tmpExp - tmpSum;
            else r[i+1] = tmpSum - tmpExp;
        }

        int outMax = 0, inMax = 0;
        for (int i=0; i<machines.size(); i++) {
            if (l[i]+r[i+1] > outMax) outMax = l[i]+r[i+1];
            if (max(r[i], l[i+1]) > inMax) inMax = max(r[i], l[i+1]);
        }
        return max(outMax, inMax);
    }
};

int main() {
    Solution s;
    vector<int> v = {1,0,5};
    assert(3 == s.findMinMoves(v));

    v = {0,3,0};
    assert(2 == s.findMinMoves(v));

    v = {4,0,4,0};
    assert(2 == s.findMinMoves(v));

    v = {1,2,5,10,7,0,3};
    assert(6 == s.findMinMoves(v));

    v = {34,4,18,25,47,93,53,26,7,23};
    assert(60 == s.findMinMoves(v));
}

