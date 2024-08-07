# include <iostream>

using std :: cout;
using std :: endl;

class TreeNode {
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val_ = val;
        }
};

void inOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    inOrder(root -> left);
    cout << root -> val_ << endl;
    inOrder(root -> right);
}

void preOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    cout << root -> val_ << endl;
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(TreeNode* root) {
    if (!root) {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> val_ << endl;
}