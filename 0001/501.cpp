#include <vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> all;
        dfs(root, all);

        vector<int> res;
        int maxNum = 0, curNum = 1;

        for (int i=1; i<=all.size(); i++) {
            if (i < all.size() && all[i] == all[i-1]) {
                curNum++;
                continue;
            }

            if (curNum >= maxNum) {
                if (curNum != maxNum) res.clear();
                maxNum = curNum;
                res.push_back(all[i-1]);
            }
            curNum = 1;
        }

        return res;
    }

    void dfs(TreeNode* root, vector<int>& v) {
        if (root == nullptr) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
};

void printResult(vector<int>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}

void test1() {
    TreeNode* l = new TreeNode(4);
    TreeNode* r = new TreeNode(6);
    TreeNode* node = new TreeNode(5, l, r);
    Solution s;
    auto v = s.findMode(node);
    printResult(v);
}

void test2() {
    TreeNode* l = new TreeNode(4);
    TreeNode* r = new TreeNode(6);
    TreeNode* node = new TreeNode(4, l, r);
    Solution s;
    auto v = s.findMode(node);
    printResult(v);
}

void test3() {
    TreeNode* l = new TreeNode(4);
    TreeNode* r = new TreeNode(6);
    TreeNode* node = new TreeNode(6, l, r);
    Solution s;
    auto v = s.findMode(node);
    printResult(v);
}

void test4() {
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(2, n1, nullptr);
    TreeNode* node = new TreeNode(2, nullptr, n2);
    Solution s;
    auto v = s.findMode(node);
    printResult(v);
}

void test5() {
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(4, n1, n2);
    TreeNode* n4 = new TreeNode(0);
    TreeNode* n5 = new TreeNode(2, n4, n3);
    TreeNode* n6 = new TreeNode(7);
    TreeNode* n7 = new TreeNode(9);
    TreeNode* n8 = new TreeNode(8, n6, n7);
    TreeNode* node = new TreeNode(6, n5, n8);

    Solution s;
    auto v = s.findMode(node);
    printResult(v);
}
int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
}
