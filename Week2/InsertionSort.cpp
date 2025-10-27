#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int>& a) { // Average: O(n), Worst case: O(n^2) (Reversed array)
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int pivot = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > pivot) {
            a[j+1] = a[j];
            j = j - 1;
        }
        a[j+1] = pivot;
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertionSort(a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}