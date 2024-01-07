#include "iostream"
#include "queue"
#include "stack"
#include "vector"
#include "algorithm"
#include "cstring"
#include "cmath"
#include "set"
#include "map"
#include "numeric"
#include "unordered_set"
#include "unordered_map"
#include "array"
#include "cctype"
#include "list"

using namespace std;
using container = vector<int>;

//选择排序
auto selectSort(container &vec) -> decltype(vec) {
    if (vec.empty() || vec.size() < 2)
        return vec;
    int minIndex = 0;
    for (int i = 0; i < vec.size() - 1; ++i) {
        minIndex = i;
        for (int j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[minIndex])
                minIndex = j;
        }
        swap(vec[i], vec[minIndex]);
    }
    return vec;
}

//冒泡排序
auto bubbleSort(container &vec) -> decltype(vec) {
    if (vec.empty() || vec.size() < 2)
        return vec;
    for (int j = vec.size() - 1; j > 0; --j) {
        for (int i = 0; i < j; ++i) {
            if (vec[i] > vec[i + 1])
                swap(vec[i], vec[i + 1]);
        }
    }
    return vec;
}

//插入排序
auto insertSort(container &vec) -> decltype(vec) {
    if (vec.empty() || vec.size() < 2)
        return vec;
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; --j) {
            swap(vec[j], vec[i]);
        }
    }
    return vec;
}

//归并排序
void merge(int l, int m, int r, container &vec);

auto mergeSort(container &vec) -> decltype(vec) {
    if (vec.empty() || vec.size() < 2)
        return vec;
    int n = vec.size();
    for (int l, m, r, step = 1; step < n; step <<= 1) {
        l = 0;
        while (l < n) {
            m = l + step - 1;
            if (m + 1 >= n)
                break;
            r = min(l + (step << 1) - 1, n - 1);
            merge(l, m, r, vec);
            l = r + 1;
        }
    }
    return vec;
}

void merge(int l, int m, int r, container &vec) {
    container aux_vec{vec};
    int i = l;
    int left = l;
    int right = m + 1;
    while (left <= m && right <= r) {
        aux_vec[i++] = vec[left] <= vec[right] ? vec[left++] : vec[right++];
    }
    while (left <= m) {
        aux_vec[i++] = vec[left++];
    }
    while (right <= r) {
        aux_vec[i++] = vec[right++];
    }
    for (i = l; i <= r; ++i) {
        vec[i] = aux_vec[i];
    }
}

int main() {
    container vec{1, 8, 4, 7, 5, 2};
    //selectSort(vec);
    //bubbleSort(vec);
    //selectSort(vec);
    mergeSort(vec);
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }


    return 0;
}