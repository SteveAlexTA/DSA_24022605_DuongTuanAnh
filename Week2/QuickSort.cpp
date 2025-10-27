#include<bits/stdc++.h>
using namespace std;
//Do phuc tap: O(nlogn) (pivot deu), worst O(n^2) (pivot lech)
int partition(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p-1);
        quickSort(a, p+1, high);
    }
}

int main() {
    int n; cin >> n;
    vector<int>a(n);
    for (int i=0; i<n; i++) {
        cin>>a[i];
    }
    cout<<"Before sort: ";
    for(int i: a) cout<<i<<" ";
    cout<<endl;
    quickSort(a,0,n-1);
    cout<<"After sort: ";
    for(int i: a) cout<<i<<" ";
    cout<<endl; 
}