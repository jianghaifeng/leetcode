#include <string>
#include <iostream>
#include <queue>
#include <sstream>


using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
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

    TreeNode* deserialize(queue<int>& q, int hi, int lo) {
        int val = q.front();
        TreeNode* root = NULL;
        if (val < hi && val > lo)
            root = new TreeNode(val);
        q.pop();

        root->left = deserialize(q, val, lo);
        root->right = deserialize(q, hi, val);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        queue<int> q;
        string s;
        while(iss >> s) q.push(stoi(s));
        return deserialize(q, INT_MAX, INT_MIN);
    }
};

int main() {
    TreeNode root(4);
    root.left = new TreeNode(2);
    root.left->left = new TreeNode(1);
    root.left->right = new TreeNode(3);
    root.right = new TreeNode(6);
    root.right->left = new TreeNode(5);
    root.right->right = new TreeNode(7);
    Codec codec;
    cout << codec.serialize(&root) << endl;
}
