#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int>& a) { // O(n^2)
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubbleSort(a);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}