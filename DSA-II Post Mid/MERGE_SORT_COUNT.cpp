#include <bits/stdc++.h>
using namespace std;

int Merge(vector<pair<int,int>> &arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<pair<int,int>> L(n1+1), R(n2+1);
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }

    L[n1] = {INT_MAX, INT_MAX};
    
    for (int j = 0; j < n2; j++) {
        R[j] = arr[q + j + 1];
    }

    R[n2] = {INT_MAX, INT_MAX};
    
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (L[i].first <= R[j].first) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
    }
    return 0;
}

int MergeSort(vector<pair<int,int>> &arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, q + 1, r);
        Merge(arr, p, q, r);
    }
    return 0;
}
/*
Since the array is sorted in ascending order, all elements that come before a given value are smaller than it.
 Thus, the position (or index) of the first occurrence of each distinct value directly tells us how many numbers 
 are smaller than that value.
*/
int main(){
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    // (value, original_index)
    vector<pair<int,int>> indexedArr(n);
    for (int i = 0; i < n; i++){
        indexedArr[i] = {a[i], i};
    }
    
    MergeSort(indexedArr, 0, n - 1);

    unordered_map<int, int> valueToCount;
    for (int i = 0; i < n; i++){
        int val = indexedArr[i].first;
        if (valueToCount.find(val) == valueToCount.end()){
            valueToCount[val] = i;
        }
    }
    
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++){
        count[i] = valueToCount[a[i]];
    }
    

    for (int i = 0; i < n; i++){
        cout << count[i] << " ";
    }
    cout << endl;
}
