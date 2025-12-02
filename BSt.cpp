#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// ---------- INSERT ----------
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == NULL) return new TreeNode(val);

    TreeNode *cur = root;
    while (true) {
        if (cur->val <= val) {
            if (cur->right != NULL) cur = cur->right;
            else {
                cur->right = new TreeNode(val);
                break;
            }
        } else {
            if (cur->left != NULL) cur = cur->left;
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// ---------- DELETE (same terminology: deleteNode, helper, findLastRight) ----------
TreeNode* findLastRight(TreeNode* root) {
    if (root->right == NULL) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root) {
    if (root->left == NULL) {
        TreeNode* rightChild = root->right;
        delete root;
        return rightChild;
    } else if (root->right == NULL) {
        TreeNode* leftChild = root->left;
        delete root;
        return leftChild;
    }

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    TreeNode* newRoot = root->left;
    delete root;
    return newRoot;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == NULL) return NULL;
    if (root->val == key) return helper(root);

    TreeNode* dummy = root;
    while (root != NULL) {
        if (key < root->val) {
            if (root->left != NULL && root->left->val == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right != NULL && root->right->val == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

// ---------- SEARCH ----------
bool searchBST(TreeNode* root, int key) {
    while (root != NULL) {
        if (root->val == key) return true;
        else if (key < root->val) root = root->left;
        else root = root->right;
    }
    return false;
}

// ---------- MIN & MAX ----------
int findMinBST(TreeNode* root) {
    if (root == NULL) throw runtime_error("Empty tree");
    while (root->left != NULL) root = root->left;
    return root->val;
}

int findMaxBST(TreeNode* root) {
    if (root == NULL) throw runtime_error("Empty tree");
    while (root->right != NULL) root = root->right;
    return root->val;
}

// ---------- K-th SMALLEST (using inorder on BST) ----------
void kthSmallestUtil(TreeNode* root, int k, int &cnt, int &ans, bool &found) {
    if (root == NULL || found) return;
    kthSmallestUtil(root->left, k, cnt, ans, found);
    if (found) return;
    cnt++;
    if (cnt == k) {
        ans = root->val;
        found = true;
        return;
    }
    kthSmallestUtil(root->right, k, cnt, ans, found);
}

int kthSmallest(TreeNode* root, int k) {
    int cnt = 0, ans = -1;
    bool found = false;
    kthSmallestUtil(root, k, cnt, ans, found);
    return ans;          // if k is invalid, this returns -1
}

// ---------- INORDER (for checking tree) ----------
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// ---------- MAIN: build BST from array and use all operations ----------
int main() {
    // example array
    vector<int> arr = {5, 3, 7, 2, 4, 6, 8};

    TreeNode* root = NULL;
    for (int x : arr) {
        root = insertIntoBST(root, x);
    }

    cout << "Inorder (sorted): ";
    inorder(root);
    cout << "\n";

    // search
    int keySearch = 4;
    cout << "Search " << keySearch << ": "
         << (searchBST(root, keySearch) ? "Found\n" : "Not Found\n");

    // min & max
    cout << "Minimum: " << findMinBST(root) << "\n";
    cout << "Maximum: " << findMaxBST(root) << "\n";

    // K-th smallest
    int k = 3;
    cout << k << "-th smallest: " << kthSmallest(root, k) << "\n";

    // delete
    int keyDelete = 5;
    root = deleteNode(root, keyDelete);
    cout << "After deleting " << keyDelete << ", inorder: ";
    inorder(root);
    cout << "\n";

    return 0;
}
