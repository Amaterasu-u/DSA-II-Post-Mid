#include <bits/stdc++.h>
using namespace std;

void matrixChainOrder(vector<int>& p, int n, vector<vector<int>>& m, vector<vector<int>>& s) {
    for (int i = 1; i < n; i++) {
        m[i][i] = 0; // Cost is zero when multiplying one matrix
    }

    for (int l = 2; l < n; l++) { // l is chain length

        /*
l represents the chain length of the subproblem: the number of matrices I am trying to multiply.
The loop starts from 2 (since chain length of 1 is already handled above by setting m[i][i] = 0).
It goes up to n-1 because the largest chain involves multiplying all n−1 matrices.
        */

        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

/*
if s[1][3]<-2
This means:
To optimally multiply matrices from 1 to 3, split between k=2
sub chain left of k=2 -> i=1 to k=2 -> (A1A2)
sub chain right of k=2 -> k+1=3 to j=3 -> A3 alone

*/
void printOptimalParens(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i; //khali ektai matrix ase tai oita print kore dibo
        return;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> p = {30, 35, 15, 5, 10, 20, 25};
    int n = p.size();

    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    matrixChainOrder(p, n, m, s);

    cout << "Minimum number of multiplications: " << m[1][n - 1] << endl;
    cout << "Optimal Parenthesization: ";
    printOptimalParens(s, 1, n - 1);
    cout << endl;

}
