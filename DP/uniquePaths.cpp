#include <bits/stdc++.h>
using namespace std;

#define ll long long

// 1. Top-Down DP (Memoization)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n) for memo table + O(m + n) for recursion stack

int f(int m, int n, vector<vector<int>>& dp) {
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;

    if (dp[m][n] != -1) return dp[m][n];

    int up = f(m - 1, n, dp);
    int left = f(m, n - 1, dp);
    return dp[m][n] = up + left;
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return f(m, n, dp);
}

// 2. Bottom-Up DP (Tabulation)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

int tabulation(int m, int n) {
    
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[1][1] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m][n];
}

// 3. Combinatorics (Mathematical Formula) -> Most Efficient
// Time Complexity: O(min(m, n))
// Space Complexity: O(1)

ll combinatorics(int m, int n) {
    ll ans = 1;
    int N = m + n - 2;
    int r = min(m - 1, n - 1);
    for (int i = 1; i <= r; ++i) {
        ans = ans * (N - r + i) / i;
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    cout << "Top-Down DP (memo): " << uniquePaths(m, n) << endl;
    cout << "Bottom-Up DP (tabulation): " << tabulation(m, n) << endl;
    cout << "Combinatorics: " << combinatorics(m, n) << endl;

    return 0;
}
