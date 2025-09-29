#include<bits/stdc++.h>
using namespace std;
//Do phuc tap: O(nlogn), worst O(n^2)
void quickSort(vector<int>&arr, int low, int high) {
    if (low>=high) return;
    int l = low;
    int r = high;
    int mid = (l+r)/2;
    int pivot = arr[mid];
    while (l<=r) {
        while (arr[l]<pivot) l++;
        while (arr[r]>pivot) r--;
        if (l<=r) {
            swap(arr[l], arr[r]);
            l++;
            r--;
        }
    }
    quickSort(arr, low, r);
    quickSort(arr, l, high);
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