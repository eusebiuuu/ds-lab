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
        } else {
            currRoot->right = insertRec(currRoot->right, val, height + 1);
            currRoot->sizeRight++;
        }
        return currRoot;
    }

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

    vector<int> getArray(TreeNode* currRoot) {
        vector<int> currAns;
        if (currRoot == nullptr) {
            return currAns;
        }
        vector<int> arr1 = getArray(currRoot->left);
        for (int x : arr1) {
            currAns.push_back(x);
        }
        currAns.push_back(currRoot->val);
        vector<int> arr2 = getArray(currRoot->right);
        for (int x : arr2) {
            currAns.push_back(x);
        }
        return currAns;
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insertRec(root, val, 0);
    }

    TreeNode* search(int val) {
        return searchRec(root, val);
    }

    vector<int> getCorrespondingArray() {
        return getArray(root);
    }
};

void buildBSTFromArr(BST *tree, int l, int r, vector<int>& arr) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    tree->insert(arr[mid]);
    buildBSTFromArr(tree, l, mid - 1, arr);
    buildBSTFromArr(tree, mid + 1, r, arr);
}

vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2) {
    vector<int> mergedArray;
    int i = 0, j = 0;

    while (i < arr1.size() and j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        mergedArray.push_back(arr2[j]);
        j++;
    }
    return mergedArray;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> sortedArr1(n), sortedArr2(m);
    for (int i = 0; i < n; ++i) {
        cin >> sortedArr1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> sortedArr2[i];
    }
    BST *tree1 = new BST(), *tree2 = new BST();
    buildBSTFromArr(tree1, 0, n - 1, sortedArr1);
    buildBSTFromArr(tree2, 0, m - 1, sortedArr2);
    BST *newTree = new BST();
    vector<int> arr1 = tree1->getCorrespondingArray();
    vector<int> arr2 = tree2->getCorrespondingArray();
    cout << arr1.size() << ' ' << arr2.size() << '\n';
    vector<int> mergedArray = mergeArrays(arr1, arr2);
    buildBSTFromArr(newTree, 0, (int) mergedArray.size() - 1, mergedArray);
    vector<int> newArray = newTree->getCorrespondingArray();
    for (int x : newArray) {
        cout << x << ' ';
    }
    cout << '\n';
    delete tree1;
    delete tree2;
    delete newTree;
    return 0;
}