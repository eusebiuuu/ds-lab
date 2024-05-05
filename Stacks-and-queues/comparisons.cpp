#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

struct Node {
    int val, pos;
    Node* next;
    explicit Node(int val, int pos) : val(val), pos(pos), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val, int pos) {
        Node* newNode = new Node(val, pos);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    ii peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return {-1, -1};
        }
        return {top->val, top->pos};
    }
};

struct QueueNode {
    int data;
    QueueNode* next;
    explicit QueueNode(int val) : data(val), next(nullptr) {}
};


class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int val) {
        auto *newNode = new QueueNode(val);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot dequeue from an empty queue." << endl;
            return;
        }
        QueueNode* temp = front;
        front = front->next;
        delete temp;
        if (front == nullptr) {
            rear = nullptr;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1; // Assuming -1 as invalid value
        }
        return front->data;
    }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> closestBigger(n + 1, -1);
  auto *nums = new Stack();
  queue<int> ans;
  for (int i = n; i > 0; --i) {
    while (!nums->isEmpty() and nums->peek().first <= a[i]) {
      nums->pop();
    }
    if (!nums->isEmpty()) {
      closestBigger[i] = nums->peek().second;
    }
    nums->push(a[i], i);
  }
  auto *ansQueue = new Queue();
  for (int i = 1; i <= n; ++i) {
    ansQueue->enqueue(closestBigger[i]);
  }
  while (!ansQueue->isEmpty()) {
      cout << ansQueue->peek() << ' ';
      ansQueue->dequeue();
  }
  cout << '\n';
  delete nums;
  delete ansQueue;
  return 0;
}
