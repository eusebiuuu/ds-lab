#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

struct Node {
  int val;
  Node* next;
  explicit Node(int val = 0): val(val), next(nullptr) {}
};

void insertNode(Node* head, Node* newNode) {
  int nodeVal = newNode->val;
  Node* currNode = head;
  while (true) {
    if (currNode->next == nullptr or currNode->next->val > nodeVal) {
        break;
    }
    currNode = currNode->next;
  }
  Node* nextNode = currNode->next;
  currNode->next = newNode;
  if (nextNode != nullptr) {
      newNode->next = nextNode;
  }
}

// !!! Removes the element from the position pos, not the element pointed by something
void deleteNode(Node* head, int pos) {
  int currPos = 1;
  Node* prevNode = head;
  Node* currNode = head->next;
  while (currPos < pos) {
    prevNode = currNode;
    currNode = currNode->next;
    currPos++;
  }
  prevNode->next = currNode->next;
}

Node* getNode(Node* &head, int k) {
  Node* currNode = head;
  while (currNode != nullptr and currNode->val != k) {
    currNode = currNode->next;
  }
  return currNode;
}

void printList(Node* head) {
  Node* currNode = head->next;
  while (currNode != nullptr) {
    cout << currNode->val << ' ';
    currNode = currNode->next;
  }
  cout << '\n';
}

void deleteList(Node *head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  Node* head = new Node();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
      int num;
      cin >> num;
      insertNode(head, new Node(num));
  }
  printList(head);
  Node* aux = getNode(head, 8);
  cout << aux->val << '\n';
  deleteNode(head, 4);
  aux = getNode(head, 8);
  if (aux == nullptr) {
      cout << "The element doesn't exist\n";
  } else {
      cout << aux->val << '\n';
  }
  deleteList(head);
  return 0;
}
