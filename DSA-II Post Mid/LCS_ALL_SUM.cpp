#include <bits/stdc++.h>
using namespace std;

void printLCS(vector<vector<int>> &p, string &a, int i, int j) {
    if (i == 0 || j == 0) return;
    if (p[i][j] == 1) {
        printLCS(p, a, i - 1, j - 1);
        cout << a[i - 1]; 
    } 
    else if (p[i][j] == 2) {
        printLCS(p, a, i - 1, j);
    } 
    else {
        printLCS(p, a, i, j - 1);
    }
}

int LCS(string a, string b) {
    int m = a.size(), n = b.size();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> p(m + 1, vector<int>(n + 1, 0));
   
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                p[i][j] = 1;
            } 
            else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                p[i][j] = 2;
            } 
            else {
                c[i][j] = c[i][j - 1];
                p[i][j] = 3;
            }
        }
    }

    printLCS(p, a, m, n);
    cout << endl;

    return c[m][n];
}

int main() {
    string a, b;
    int count=0;
    cin >> a >> b;
    int m = a.size(), n = b.size();
 for(int i=1;i<=m;i++){
    string s1=a.substr(0,i);

    for(int j=0;j<n;j++){
        for(int k=j;k<n;k++){
            string s2=b.substr(j,k-j+1);
            count+=LCS(s1,s2);
        }
    }
 }

    cout<<count<<endl;

}
