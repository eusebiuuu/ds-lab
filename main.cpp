#include <iostream>
#include <vector>
int const ALPH = 26;

struct Node {
    std::string value;
    Node* next = nullptr;
};

std::vector<Node*> hashTable(ALPH, nullptr);

int getIdx(char c) {
    return c - 'a';
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string currWord;
        std::cin >> currWord;
        int key = getIdx(currWord[0]);
        Node* newNode = new Node{currWord, hashTable[key]};
        hashTable[key] = newNode;
    }
    for (int i = 0; i < ALPH; ++i) {
        Node* head = hashTable[i];
        std::cout << "Letter " << (char) (i + 'a') << ": \n";
        if (head == nullptr) continue;
        while (head != nullptr) {
            std::cout << head->value << ' ';
            head = head->next;
        }
        std::cout << '\n';
    }
    return 0;
}
