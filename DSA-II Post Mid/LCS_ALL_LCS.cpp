#include <bits/stdc++.h>
using namespace std;

void findAllLCS(vector<vector<int>> &dp, string &a, string &b, int i, int j, string &current, set<string> &lcsSet) {
    if (i == 0 || j == 0) {
        reverse(current.begin(), current.end());
        lcsSet.insert(current);
        reverse(current.begin(), current.end());
        return;
    }

    if (a[i - 1] == b[j - 1]) {
        current.push_back(a[i - 1]);
        findAllLCS(dp, a, b, i - 1, j - 1, current, lcsSet);
        current.pop_back();
    } else {
        if (dp[i - 1][j] == dp[i][j]) {
            findAllLCS(dp, a, b, i - 1, j, current, lcsSet);
        }
        if (dp[i][j - 1] == dp[i][j]) {
            findAllLCS(dp, a, b, i, j - 1, current, lcsSet);
        }
    }
}

void LCS(string a, string b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int lcsLength = dp[m][n];

    set<string> lcsSet;
    string current = "";
    findAllLCS(dp, a, b, m, n, current, lcsSet);


    cout << "All LCS sequences: "<<endl;
    for (const auto &seq : lcsSet) {
        cout << seq << endl;
    }

    cout << "Length of LCS: " << lcsLength << endl;
}

int main() {
    string a, b;
    cin >> a >> b;
    LCS(a, b);

}
