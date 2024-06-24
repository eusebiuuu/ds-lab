#include <iostream>
#include <unordered_set>
#include <stack>
using namespace std;

struct TreeNode {
    int value;
    TreeNode* leftChild;
    TreeNode* rightChild;

    TreeNode(int val) {
        value = val;
        leftChild = rightChild = nullptr;
    }
};

TreeNode* insertNode(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);
    if (val < root->value)
        root->leftChild = insertNode(root->leftChild, val);
    else if (val > root->value)
        root->rightChild = insertNode(root->rightChild, val);
    return root;
}

void fillSetWithTreeValues(TreeNode* root, unordered_set<int>& valuesSet) {
    stack<TreeNode*> nodeStack;
    TreeNode* currentNode = root;

    while (currentNode != nullptr || !nodeStack.empty()) {
        while (currentNode != nullptr) {
            nodeStack.push(currentNode);
            currentNode = currentNode->leftChild;
        }
        currentNode = nodeStack.top();
        nodeStack.pop();
        valuesSet.insert(currentNode->value);
        currentNode = currentNode->rightChild;
    }
}

int countPairsWithSum(TreeNode* bst1, TreeNode* bst2, int targetSum) {
    unordered_set<int> valuesSet;
    fillSetWithTreeValues(bst2, valuesSet);

    int pairCount = 0;
    stack<TreeNode*> nodeStack;
    TreeNode* currentNode = bst1;

    while (currentNode != nullptr || !nodeStack.empty()) {
        while (currentNode != nullptr) {
            nodeStack.push(currentNode);
            currentNode = currentNode->leftChild;
        }
        currentNode = nodeStack.top();
        nodeStack.pop();
        if (valuesSet.find(targetSum - currentNode->value) != valuesSet.end())
            pairCount++;
        currentNode = currentNode->rightChild;
    }

    return pairCount;
}