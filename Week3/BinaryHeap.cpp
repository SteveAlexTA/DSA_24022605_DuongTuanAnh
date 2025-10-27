#include<bits/stdc++.h>
using namespace std;

class MaxHeap {
private:
    int list[100];
    int n;

public:
    MaxHeap(): n(0) {}

    void heapifyDown(int i) { // O(logn)
        int left = 2*i+1;
        int right = 2*i+2;
        int max_idx = i;
        if (left < n && list[left] > list[max_idx]) {
            max_idx = left;
        }
        if (right < n && list[right] > list[max_idx]) {
            max_idx = right;
        }
        if (max_idx != i) {
            swap(list[i], list[max_idx]);
            heapifyDown(max_idx);
        }
    }

    void heapifyUp(int i) { // O(logn)
        while (i > 0) {
            int parent = (i-1)/2;
            if (list[i] > list[parent]) {
                swap(list[i], list[parent]);
                i = parent;
            } else {
                break;
            }
        }
    }

    void insert(int val) {
        if(n >= 100) return;
        list[n] = val;
        heapifyUp(n);
        n++;
    }

    void delMax() {
        if (isEmpty()) return;
        swap(list[0], list[n-1]);
        n--;
        heapifyDown(0);
    }

    bool isEmpty() {
        return n <= 0;
    }

    int getMax() {
        if (isEmpty()) return -1;
        return list[0];
    }

    int size() {
        return n;
    }
};

class MinHeap {
private:
    int list[100];
    int n;

public:
    MinHeap(): n(0) {}

    void heapifyDown(int i) { // O(logn)
        int min_idx = i;
        int left = 2*i+1; 
        int right = 2*i+2;
        if (left < n && list[left] < list[min_idx]) {
            min_idx = left;
        }
        if (right < n && list[right] < list[min_idx]) {
            min_idx = right;
        }
        if (min_idx != i) {
            swap(list[i], list[min_idx]);
            heapifyDown(min_idx);
        }
    }

    void heapifyUp(int i) { // O(logn)
        while (i > 0) {
            if (list[i] < list[(i-1)/2]) {
                swap(list[i], list[(i-1)/2]);
                i = (i-1)/2;
            } else {
                break;
            }
        }
    }

    void insert(int val) {
        if (n>=100) return;
        list[n] = val;
        heapifyUp(n);
        n++;
    }

    void delMin() {
        if(isEmpty()) return;
        swap(list[0], list[n-1]);
        n--;
        heapifyDown(0);
    }

    bool isEmpty() {
        return n <= 0;
    }

    int getMin() {
        if (isEmpty()) return -1;
        return list[0];
    }

    int size() {
        return n;
    }
};

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    MaxHeap left;
    MinHeap right;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        if (left.isEmpty() || num <= left.getMax()) {
            left.insert(num);
        } else {
            right.insert(num);
        }
        if (left.size() > right.size() + 1) {
            right.insert(left.getMax());
            left.delMax();
        } else if (right.size() > left.size()) {
            left.insert(right.getMin());
            right.delMin();
        }
        double median;
        if (left.size() == right.size()) {
            median = (left.getMax() + right.getMin()) / 2.0;
        } else {
            median = left.getMax();
        }
        cout << fixed << setprecision(1) << median << endl;
    }
}