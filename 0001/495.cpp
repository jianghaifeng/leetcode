#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findEnd(vector<int>& ts, int& duration, int start) {
        while (start < ts.size() - 1 && ts[start] + duration > ts[start + 1]) {
            start++;
        }
        return start;
    }

    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int start = 0, total = 0;
        while (start < timeSeries.size()) {
            int end = findEnd(timeSeries, duration, start);
            total += (duration + timeSeries[end] - timeSeries[start]);
            start = end + 1;
        }

        return total;
    }
};

int main() {
    Solution s;
    vector<int> v;
    v = {1,4};
    cout << "4 = " << s.findPoisonedDuration(v, 2) << endl;
    v = {1,2};
    cout << "3 = " << s.findPoisonedDuration(v, 2) << endl;
    v = {1,3,5,6,8,9,10,13,18,20,22,30};
    cout << "31 = " << s.findPoisonedDuration(v, 5) << endl;
}
