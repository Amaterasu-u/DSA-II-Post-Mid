#include<bits/stdc++.h>
using namespace std;
#define V 6

struct Item{
    double value,weight;
}

bool compare(const Item &a , const Item &b){
    return a.value/a.weight > b.value/b.weight;
}

void ks(){
vector<vector<bool>> dp(n+1 , vector<bool>(W+1 ,false));
for(int i=0 ; i<n;i++){
    dp[i][0]=true;
}
for(int i=1;i<=n;i++){
    for(int w=0;w<=W;w++){
        dp[i][w]=dp[i-1][w];
        if(weight[i-1]<=w){
            dp[i][w]=dp[i][w] || dp[i-1][w-weights[i-1]];
        }
    }
}

}


int main(){


}