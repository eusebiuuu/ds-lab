#include <iostream>
#include <vector>
int const ALPH = 26;

struct SimpleList {
    std::string value;
    SimpleList* next = nullptr;
};

std::vector<SimpleList*> hashTable(ALPH, nullptr);

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
        SimpleList* newNode = new SimpleList{currWord, hashTable[key]};
        hashTable[key] = newNode;
    }
    for (int i = 0; i < ALPH; ++i) {
        SimpleList* head = hashTable[i];
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
