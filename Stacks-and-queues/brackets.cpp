#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

bool isClosingBracket(char c) {
  return c == ')' or c == ']' or c == '}';
}

char matchingBracket(char c) {
  if (c == ')') {
    return '(';
  } else if (c == ']') {
    return '[';
  }
  return '{';
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  string brackets;
  cin >> brackets;
  stack<char> bracketStack;
  int sz = (int) brackets.size();
  for (int i = 0; i < sz; ++i) {
    if (isClosingBracket(brackets[i])) {
      if (bracketStack.empty()) {
        return cout << "Invalid sequence\n", 0;
      }
      if (bracketStack.top() != matchingBracket(brackets[i])) {
        return cout << "Invalid sequence\n", 0;
      }
      bracketStack.pop();
      continue;
    }
    bracketStack.push(brackets[i]);
  }
  cout << (bracketStack.empty() ? "Correct sequence\n" : "Invalid sequence\n");
  return 0;
}
