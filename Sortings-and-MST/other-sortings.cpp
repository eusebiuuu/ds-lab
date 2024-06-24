#include "iostream"
#include "vector"
#include "chrono"
#include "random"
using namespace std;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void selectionSort(vector<int> &arr) {
    int sz = (int) arr.size();
    for (int i = 0; i < sz; ++i) {
        int pos = i;
        for (int j = i + 1; j < sz; ++j) {
            if (arr[j] < arr[pos]) {
                pos = j;
            }
        }
        swap(arr[i], arr[pos]);
    }
}

void insertionSort(vector<int> &arr) {
    int sz = (int) arr.size();
    for (int i = 1; i < sz; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                continue;
            }
            break;
        }
    }
}

int getRandomBetween(int a, int b) {
    return rnd() % (b - a + 1) + a;
}

void quickSort(vector<int> &arr, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivotPos = getRandomBetween(left, right), pivot = arr[pivotPos];
    swap(arr[pivotPos], arr[right]);
    int partitionIdx = left;
    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) {
            std::swap(arr[i], arr[partitionIdx]);
            partitionIdx++;
        }
    }
    std::swap(arr[partitionIdx], arr[right]);

    quickSort(arr, left, partitionIdx - 1);
    quickSort(arr, partitionIdx + 1, right);
}


void bubbleSort(std::vector<int>& vec) {
    bool swapped;
    int n = (int) vec.size();
    do {
        swapped = false;
        for (size_t i = 1; i < n; ++i) {
            if (vec[i - 1] > vec[i]) {
                std::swap(vec[i - 1], vec[i]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}

void merge(std::vector<int>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = vec[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            vec[k] = leftArr[i];
            ++i;
        } else {
            vec[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        vec[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        vec[k] = rightArr[j];
        ++j;
        ++k;
    }
}

void mergeSort(std::vector<int>& vec, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(vec, left, mid);
    mergeSort(vec, mid + 1, right);

    merge(vec, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    // call the sorting function
    //
    // above
    for (int i = 1; i <= n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
    return 0;
}