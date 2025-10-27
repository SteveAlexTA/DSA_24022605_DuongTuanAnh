#include<bits/stdc++.h>
using namespace std;

class PriorityQueue {
private:
    int a[100];
    int n;
public:
    PriorityQueue() {n = 0;};

    bool isEmpty() {
        return n == 0;
    }

    void insert(int val) {
        if (n>=100) return;
        a[n] = val;
        n++;
    }

    void delMax() {
        if (isEmpty()) return;
        int max_idx = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[max_idx]) {
                max_idx = i;
            }
        }
        swap(a[max_idx], a[n-1]);
        n--;
    }

    int getMax() {
        if (isEmpty()) return -1;
        int max_val = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > max_val) {
                max_val = a[i];
            }
        }
        return max_val;
    }

    int size() {
        return n;
    }
};