// lets write a code for implementing a binary search tree
// first lets define a class for the tree node
class treeNode {
    public:
        int val_; // take the value
        // initially we set the left and right pointer to null
        treeNode* left = nullptr;
        treeNode* right = nullptr;

        treeNode(int val) {
            val_ = val;
        }
};

bool search(treeNode* root, int target) {
    // we will check if the root exists or not
    if (! root) {
        return false;
    }

    // as per the property of binary search Tree
    // if the target value is less than root node then we search in the left direction
    if (target < root -> val_) {
        return search(root -> left, target);
    }
    // if the target value is greater than the root node then we search in the right direction
    else if (target > root -> val_) {
        return search(root -> right, target);
    }
    // if the target value is the root then we return True
    else {
        return true;
    }
}