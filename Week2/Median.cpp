#include<bits/stdc++.h>
using namespace std;

//Bubble sort: O(n^2)
void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
            }
        }
    }
}

//Insertion sort: O(n) / O(n^2) worst case
void insertionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}

//Selection sort: O(n^2)
void selectionSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int curr_index = i;
        for (int j = i+1; j<n; j++) {
            if (a[j] < a[curr_index]) {
                curr_index = j;
            }
        }
        swap(a[i], a[curr_index]);
    }
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i <n; i++) {
        cin >> a[i];
    }
    cout << "Original:" << endl;
    for (int i = 0; i <n; i++) {
        cout << a[i] << " ";
    }
    cout<<endl;
    bubbleSort(a);
    cout << "After bubble sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    insertionSort(a);
    cout << "After insertion sort:" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    selectionSort(a);
    cout << "After selection sort" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    double median;
    if (n % 2 == 1) median = a[n/2];
    else median = (a[n/2 - 1] + a[n/2]) / 2.0;
    cout << "Median: " << median << endl;
} 