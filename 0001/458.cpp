#include <iostream>

using namespace std;
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int times = minutesToTest / minutesToDie;
        if (times < 1) return 0;
        if (buckets == 1) return 0;
        int pigs = 1;
        int total = times + 1;
        while (total < buckets) {
            total *= (times + 1);
            pigs++;
        }
        return pigs;
    }
};

int main() {
    Solution s;
    assert(s.poorPigs(1, 1, 1) == 0);
    assert(s.poorPigs(8, 1, 1) == 3);
    assert(s.poorPigs(3, 1, 2) == 1);
    assert(s.poorPigs(4, 1, 2) == 2);
    assert(s.poorPigs(4, 1, 1) == 2);
    assert(s.poorPigs(9, 1, 2) == 2);
}
