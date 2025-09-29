#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    if (n%2 == 0) return;
    int arr[n];
    for (int i = 0; i <n; i++) {
        cin >> arr[i];
    }
    //Bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if(arr[j]>arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
    cout << arr[n/2];
}