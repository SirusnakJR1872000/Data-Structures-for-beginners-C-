# include <iostream>
# include <queue>

using std :: cout;
using std :: endl;
using std :: queue;

class TreeNode {
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val){
            val_ = val;
        }
};

TreeNode* insert(TreeNode* root, int val) {

    if (!root) {
        return new TreeNode(val);
    }

    if (val < root -> val_) {
        root -> left = insert(root -> left, val);
    }

    else if (val > root -> val_) {
        root -> right = insert(root -> right, val);
    }

    return root;
}

TreeNode* findMinimum(TreeNode* root) {

    TreeNode* curr = root;
    while (curr && curr -> left) {
        curr = curr -> left;
    }
    return curr;
}

TreeNode* remove(TreeNode* root, int val) {

    if (!root) {
        return nullptr;
    }

    if (val < root -> val_) {
        root -> left = remove(root -> left, val);
    }

    else if (val > root -> val_) {
        root -> right = remove(root -> right, val);
    }

    else {
        if (!root -> left){
            return root -> right;
        }

        else if (!root -> right) {
            return root -> left;
        }

        else {
            TreeNode* minNode = findMinimum(root -> right);
            root -> val_ = minNode -> val_;
            root -> right = remove(root -> right, minNode -> val_);
        }
    }
    return root;
}