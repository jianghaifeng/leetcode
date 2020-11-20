#include <vector>
#include <cmath>

using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int len = houses.size();
        vector<pair<int,int>> dist(len, make_pair(0,0));

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());

        int j=0;
        for (int i=0; i<len; i++) {
            while (j < heaters.size() && heaters[j] < houses[i]) j++;

            if (j > 0) dist[i].first = houses[i] - heaters[j-1];
            else dist[i].first = INT_MAX;

            if (j < heaters.size()) dist[i].second = heaters[j] - houses[i];
            else dist[i].second = INT_MAX;
        }

        int res = 0;
        for (int i=0; i<len; i++) {
            res = max(res, min(dist[i].first, dist[i].second));
        }

        return res;
    }
};

int main() {
    vector<int> houses;
    vector<int> heaters;
    Solution s;

    houses = {1,2,3};
    heaters = {2};
    assert(1 == s.findRadius(houses,heaters));

    houses = {1,2,3,4};
    heaters = {1,4};
    assert(1 == s.findRadius(houses,heaters));
    
    houses = {1,5};
    heaters = {2};
    assert(3 == s.findRadius(houses,heaters));
}
