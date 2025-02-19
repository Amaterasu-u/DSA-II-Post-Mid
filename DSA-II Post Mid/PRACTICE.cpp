#include<bits/stdc++.h>
using namespace std;

int Merge(vector<pair<int,int>> &arr , int p , int q , int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    vector<pair<int,int>> L(n1+1), R(n2+1); 
    for(int i=0;i<n1;i++){
        L[i] = arr[p+i]; 
    }
    L[n1]={INT_MAX , INT_MAX};
    for(int j=0;j<n2;j++){
        R[j] = arr[q+1+j];
    }
    R[n2]={INT_MAX , INT_MAX};
    int i = 0 , j = 0;
    for(int k=p;k<=r;k++){
        if(L[i].first <= R[j].first){
            arr[k] = L[i];
            i++;
            }
            else{
                arr[k] = R[j];
                j++;
                }
                }
                return 0;
}

int MergeSort(vector<pair<int,int>> &arr , int p , int r){
    if(p<r){
        int q=(p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Merge(arr,p,q,r);
    }
    return 0;
}


int main(){
    int n;
    cin >> n;   
vector<int>arr(n);
for(int i = 0; i < n; i++){
    cin >> arr[i];
}
vector<pair<int,int>> index(n);
for(int i = 0; i < n; i++){
    index[i]={arr[i] , i};
}

MergeSort(index , 0 , n-1);
unordered_map<int,int> vtoc;
for(int i=0;i<n;i++){
    int val = index[i].first;
    if(vtoc.find(val)==vtoc.end()){
        vtoc[val]=i;
    }
}
vector<int>count(n);
for(int i=0;i<n;i++){
    count[i]=vtoc[arr[i]];
}

for(int i=0;i<n;i++){
    cout << count[i] << " ";
}




}