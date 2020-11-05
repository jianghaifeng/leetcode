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
    void assign(TreeNode* p, TreeNode* t, TreeNode* s) {
        if (p->left == t) p->left = s;
        else p->right = s;
    }
    void helper(TreeNode *p, TreeNode* t) {
        if (t == NULL) return;
        if (t->left == NULL && t->right == NULL) {
            assign(p, t, NULL);
        }
        else if (t->left == NULL) {
            assign(p, t, t->right);
        }
        else if (t->right == NULL) {
            assign(p, t, t->left);
        }
        else {
            TreeNode* p1 = t->left;
            TreeNode* t1 = p1;
            while(t1->right != NULL) {
                p1 = t1;
                t1 = t1->right;
            }
            if (p1 != t1) {
                assign(p1, t1, t1->left);
                t1->left = t->left;
            }

            t1->right = t->right;

            assign(p, t, t1);
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;
        if (root->left == NULL && root->right == NULL) {
           return (key == root->val) ? NULL : root;
        }

        TreeNode *p = root;
        TreeNode *t = p;
        while(t != NULL && t->val != key) {
            p = t;
            t = (t->val > key) ? t->left : t->right;
        }

        TreeNode* vp = p;
        bool isRoot = false;
        if (p==t) {
            vp = new TreeNode(0);
            vp->left = t;
            isRoot = true;
        }

        helper(vp, t);

        if (isRoot) return vp->left;

        return root;
    }

    void serialize(TreeNode* root, string& s) {
        if (root == NULL) return;
        s += to_string(root->val);
        s.append(" ");
        serialize(root->left, s);
        serialize(root->right, s);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

};

int main() {
    Solution s;

    TreeNode p2(2), p3(3), p4(4), p5(5), p6(6), p7(7);
    p5.left  = &p3;
    p5.right = &p6;
    p3.left  = &p2;
    p3.right = &p4;
    p6.right = &p7;
    cout << s.serialize(&p5) << endl;

    TreeNode *p = s.deleteNode(&p5,3);
    cout << s.serialize(p) << endl;
}
