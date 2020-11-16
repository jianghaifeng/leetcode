#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    map<int, bool> cache;

    int getNums(vector<bool>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]) res |= (1 << i);
        }
        return res;
    }
    bool helper(int total, vector<bool> nums) {
        if (total <= 0) return false;

        int key = getNums(nums);

        if (cache.find(key) != cache.end()) {
            return cache[key];
        }
        
        for (int i=1; i<=nums.size(); i++) {
            if (nums[i-1]) continue;
            nums[i-1] = true;
            if (!helper(total-i, nums)) {
                cache[key] = true;
                nums[i-1] = false;
                return true;
            }
            nums[i-1] = false;
        }
        cache[key] = false;
        return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal) return true;
        if (maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;
        vector<bool> v(maxChoosableInteger, false);
        cache.clear();
        return helper(desiredTotal, v);
    }
};

int main() {
    Solution s;
    assert(s.canIWin(10, 1) == true);
    assert(s.canIWin(10, 2) == true);
    assert(s.canIWin(10, 3) == true);
    assert(s.canIWin(10, 4) == true);
    assert(s.canIWin(10, 5) == true);
    assert(s.canIWin(10, 6) == true);
    assert(s.canIWin(10, 7) == true);
    assert(s.canIWin(10, 8) == true);
    assert(s.canIWin(10, 9) == true);
    assert(s.canIWin(10, 10) == true);
    assert(s.canIWin(10, 11) == false);
    assert(s.canIWin(10, 12) == true);
    assert(s.canIWin(14, 29) == true);
    assert(s.canIWin(14, 30) == false);
}
