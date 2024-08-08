# include <vector>

using std :: vector;

class TreeNode {
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val_ = val;
        }
};

bool LeafNode(TreeNode* root) {
    if (!root || root -> val_ == 0) {
        return false;
    }

    if (!root -> left && !root -> right) {
        return true;
    }

    if (LeafNode(root->left)) {
        return true;
    }

    if (LeafNode(root -> right)) {
        return true;
    }
    return false;
}

bool LeafPath(TreeNode* root, vector<int>* path) {
    if (!root || root -> val_ == 0) {
        return false;
    }
    path -> push_back(root -> val_);

    if (!root -> left && !root -> right) {
        return true;
    }

    if (LeafPath(root -> left, path)) {
        return true;
    }

    if (LeafPath(root -> right, path)) {
        return true;
    }

    path -> pop_back();
    return false;
}