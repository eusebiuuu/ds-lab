#include "iostream"
#include "vector"
using namespace std;

void heapify(vector<int> &tree, int pos, int len) {
    int left = 2 * pos <= len ? tree[2 * pos] : -1;
    int right = 2 * pos + 1 <= len ? tree[2 * pos + 1] : -1;
    if (tree[pos] > max(left, right)) {
        return;
    }
    if (left > right) {
        swap(tree[pos], tree[2 * pos]);
        return heapify(tree, 2 * pos, len);
    }
    swap(tree[pos], tree[2 * pos + 1]);
    return heapify(tree, 2 * pos + 1, len);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    for (int i = n / 2; i > 0; --i) {
        heapify(arr, i, n);
    }
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}