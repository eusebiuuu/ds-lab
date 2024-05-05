#include "iostream"
#include "vector"
using namespace std;

struct TreeNode {
    int val, sizeLeft = 0, sizeRight = 0;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int x) :
        val(x), sizeLeft(0), sizeRight(0), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insertRec(TreeNode* currRoot, int val, int height) {
        if (currRoot == nullptr) {
            return new TreeNode(val);
        }
        if (val < currRoot->val) {
            currRoot->left = insertRec(currRoot->left, val, height + 1);
            currRoot->sizeLeft++;
        } else if (val > currRoot->val) {
            currRoot->right = insertRec(currRoot->right, val, height + 1);
            currRoot->sizeRight++;
        }
        return currRoot;
    }

    // Helper function to search for a value in the BST
    TreeNode* searchRec(TreeNode* currRoot, int val) {
        if (currRoot == nullptr) {
            return nullptr;
        }
        if (val == currRoot->val) {
            return currRoot;
        } else if (val < currRoot->val) {
            return searchRec(currRoot->left, val);
        } else {
            return searchRec(currRoot->right, val);
        }
    }

public:
    // Constructor
    BST() : root(nullptr) {}

    // Method to insert a value into the BST
    void insert(int val) {
        root = insertRec(root, val, 0);
    }

    // Method to search for a value in the BST
    TreeNode* search(int val) {
        return searchRec(root, val);
    }
};

BST tree;

void buildBSTFromArr(int l, int r, vector<int>& arr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    tree.insert(arr[mid]);
    buildBSTFromArr(l, mid - 1, arr);
    buildBSTFromArr(mid + 1, r, arr);
}

int main() {
    int n;
    cin >> n;
    vector<int> sortedArr(n);
    for (int i = 0; i < n; ++i) {
        cin >> sortedArr[i];
    }
    buildBSTFromArr(0, n - 1, sortedArr);
    for (int i = 0; i < n; ++i) {
        TreeNode* currNode = tree.search(sortedArr[i]);
        cout << currNode->val << ' ';
        cout << currNode->sizeLeft << ' ' << currNode->sizeRight << '\n';
    }
    return 0;
}