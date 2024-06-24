#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    Node* next;

    Node(int k) : key(k), next(nullptr) {}
};

class DNode {
public:
    int key;
    DNode* next;
    DNode* prev;

    DNode(int k) : key(k), next(nullptr), prev(nullptr) {}
};

class CNode {
public:
    int key;
    CNode* next;

    CNode(int k) : key(k), next(nullptr) {}
};

class SimpleLinkedList {
private:
    Node* head;

public:
    SimpleLinkedList() : head(nullptr) {}

    void insert(int key) {
        Node* new_node = new Node(key);
        new_node->next = head;
        head = new_node;
    }

    void print_keys() {
        Node* current = head;
        while (current) {
            cout << current->key << " -> ";
            current = current->next;
        }
        cout << "None" << std::endl;
    }

    bool search(int key) {
        Node* current = head;
        while (current) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool delete_node(int key) {
        Node* current = head;
        Node* previous = nullptr;

        while (current) {
            if (current->key == key) {
                if (previous) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int key) {
        DNode* new_node = new DNode(key);
        new_node->next = head;
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
    }

    void print_keys() {
        DNode* current = head;
        while (current) {
            cout << current->key << " <-> ";
            current = current->next;
        }
    }

    bool search(int key) {
        DNode* current = head;
        while (current) {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    bool delete_node(int key) {
        DNode* current = head;

        while (current) {
            if (current->key == key) {
                if (current->prev) {
                    current->prev->next = current->next;
                } else {
                    head = current->next;
                }
                if (current->next) {
                    current->next->prev = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }
};

class CircularLinkedList {
private:
    CNode* tail;

public:
    CircularLinkedList() : tail(nullptr) {}

    void insert(int key) {
        CNode* new_node = new CNode(key);
        if (!tail) {
            new_node->next = new_node;
            tail = new_node;
        } else {
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }
    }

    void print_keys() {
        if (!tail) {
            std::cout << "None" << std::endl;
            return;
        }
        CNode* current = tail->next;
        do {
            cout << current->key << " -> ";
            current = current->next;
        } while (current != tail->next);
        cout << "(back to head)" << std::endl;
    }

    bool search(int key) {
        if (!tail) return false;
        CNode* current = tail->next;
        do {
            if (current->key == key) {
                return true;
            }
            current = current->next;
        } while (current != tail->next);
        return false;
    }

    bool delete_node(int key) {
        if (!tail) return false;

        CNode* current = tail->next;
        CNode* previous = tail;
        do {
            if (current->key == key) {
                if (current == tail) {
                    if (current->next == tail) {
                        tail = nullptr;
                    } else {
                        tail = previous;
                    }
                }
                previous->next = current->next;
                delete current;
                return true;
            }
            previous = current;
            current = current->next;
        } while (current != tail->next);
        return false;
    }
};

int main() {
    //
    return 0;
}
