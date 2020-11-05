#include <iostream>
#include <vector>

using namespace std;

int comp(const vector<int>& v1, const vector<int>& v2) {
    if (v1[0] == v2[0]) return v1[1] < v2[1];
    return v1[0] < v2[0];
}

class Solution {
public:
    int helper(vector<vector<int>>& points, int i) {
        if (i >= points.size()) return 0;
        vector<int> point = points[i];
        int start = point[0], end = point[1];
        int cover = 1;
        bool found = false;
        cout << "i=" << i << " start=" << start << " end=" << end << endl;
        while (i+cover < points.size() && points[i+cover][0] >= start && points[i+cover][0] <= end) {
            start = points[i+cover][0];
            if (points[i+cover][1] < end) end = points[i+cover][1];
            cover++;
        }
        return 1 + helper(points, i+cover);

    } 
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);

        for (auto p : points) {cout << p[0] << "," << p[1] << endl;}
        
        return helper(points, 0);
    }
};

void test2() {
    vector<int> v;
    vector<vector<int>> vv;
    v = { 1, 2}; vv.push_back(v);
    v = { 3, 4}; vv.push_back(v);
    v = { 5, 6}; vv.push_back(v);
    v = { 7, 8}; vv.push_back(v);
    Solution s;
    assert(4 == s.findMinArrowShots(vv));
}
void test3() {
    vector<int> v;
    vector<vector<int>> vv;
    v = { 1, 2}; vv.push_back(v);
    Solution s;
    assert(1 == s.findMinArrowShots(vv));
}
void test1() {
    vector<int> v;
    vector<vector<int>> vv;
    v = {10,16}; vv.push_back(v);
    v = { 2, 8}; vv.push_back(v);
    v = { 1, 6}; vv.push_back(v);
    v = { 7,12}; vv.push_back(v);
    Solution s;
    assert(2 == s.findMinArrowShots(vv));
}
void test5() {
    vector<int> v;
    vector<vector<int>> vv;
    v = { 1, 2}; vv.push_back(v);
    v = { 2, 3}; vv.push_back(v);
    v = { 3, 4}; vv.push_back(v);
    v = { 4, 5}; vv.push_back(v);
    Solution s;
    assert(2 == s.findMinArrowShots(vv));
}
void test4() {
    vector<int> v;
    vector<vector<int>> vv;
    v = { 2, 3}; vv.push_back(v);
    v = { 2, 3}; vv.push_back(v);
    Solution s;
    assert(1 == s.findMinArrowShots(vv));
}

void test6() {
    vector<int> v;
    vector<vector<int>> vv;
    v = { 2, 3}; vv.push_back(v);
    v = { 2, 3}; vv.push_back(v);
    v = { 2, 4}; vv.push_back(v);
    Solution s;
    assert(1 == s.findMinArrowShots(vv));
}

void test7() {
    vector<int> v;
    vector<vector<int>> vv;
    v = {3,9}; vv.push_back(v);
    v = {7,12}; vv.push_back(v);
    v = {3,8}; vv.push_back(v);
    v = {6,8}; vv.push_back(v);
    v = {9,10}; vv.push_back(v);
    v = {2,9}; vv.push_back(v);
    v = {0,9}; vv.push_back(v);
    v = {3,9}; vv.push_back(v);
    v = {0,6}; vv.push_back(v);
    v = {2,8}; vv.push_back(v);
    Solution s;
    assert(2 == s.findMinArrowShots(vv));
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    return 0;
}
