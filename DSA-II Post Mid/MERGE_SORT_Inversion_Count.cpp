#include<bits/stdc++.h>
using namespace std;

int Merge(int arr[] , int p , int q , int r){
    int count=0;
int n1=q-p+1;
int n2=r-q;
int L[n1+1] , R[n2+1];
for(int i=0;i<n1;i++){
    L[i]=arr[p+i];  
}
L[n1]=INT_MAX;  
for(int j=0;j<n2;j++){
    R[j]=arr[q+j+1];
}
R[n2]=INT_MAX;  
int i=0, j=0;

for(int k=p;k<=r;k++){
    if(L[i]<=R[j]){
        arr[k]=L[i];
        i++;
        }
else{
    arr[k]=R[j];    
    j++;
    count+=(n1-i);
}

}
return count;
}

int MergeSort(int arr [] , int p , int r){
    int count=0;
    if(p<r){
        int q=(p+r)/2;
      count+= MergeSort(arr , p , q);
       count+= MergeSort(arr , q+1 , r);       
       count+= Merge(arr , p , q , r);
    }
    return count;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
   int c=MergeSort(arr , 0 , n-1);
   cout<<c<<endl;
    for(int i=0;i<n;i++)cout<<arr[i]<<" ";
}