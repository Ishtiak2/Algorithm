#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);

//Bottom-up DP (2D Table)	Time: O(n × m) Space: O(n × m)
ll editDistance(string& a, string& b) {
    ll lenA = a.size();
    ll lenB = b.size();

    vector<vector<ll>> dp(lenB+1, vector<ll> (lenA+1,0));

    for(ll i = 0; i <= lenA; i++) dp[0][i] = i;
    for(ll j = 0; j <= lenB; j++) dp[j][0] =j;

    for(ll i = 1; i <= lenB; i++) {
        for(ll j = 1; j <= lenA; j++) {
            if(b[i-1] != a[j-1]){
                dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
            }
            else {
                dp[i][j] = dp[i-1][j-1];
            }
        }
    } 
    return dp[lenB][lenA];
}

//Bottom-up DP (1D optimized) Time : O(n × m) Space: O(m)
//Most Efficient

ll editDistance1D(string& a, string& b) {
    ll n = a.size();
    ll m = b.size();

    vector<ll> prev(m + 1), curr(m + 1);

    for (ll j = 0; j <= m; j++)
        prev[j] = j;

    for (ll i = 1; i <= n; i++) {
        
        curr[0] = i; //very important

        for (ll j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min({prev[j], curr[j - 1], prev[j - 1]});
        }
        swap(prev, curr); //very important
    }

    return prev[m];
}

//Top-down DP (memoized) Time: O(n × m)	 Space: O(n × m) + O(n + m)
ll solve(ll i, ll j, string& a, string& b, vector<vector<ll>>& dp) {
    if (i == 0) return j;
    if (j == 0) return i;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i - 1] == b[j - 1]) {
        return dp[i][j] = solve(i - 1, j - 1, a, b, dp);
    }

    ll insertOp = solve(i, j - 1, a, b, dp);
    ll deleteOp = solve(i - 1, j, a, b, dp);
    ll replaceOp = solve(i - 1, j - 1, a, b, dp);

    return dp[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
}

ll editDistanceTopDown(string& a, string& b) {
    ll n = a.size();
    ll m = b.size();

    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));
    return solve(n, m, a, b, dp);
}


int main() {
    
    optimize();

    string a;
    string b;

    cin >> a >> b;

    // 1. Recursive DP
    // cout << editDistanceTopDown(a, b);  // Or use editDistance1D / editDistance2D

    // 2. 2D DP
    // cout << editDistance2D(a, b) << endl;

    // 3. 1D DP (space optimized)
    cout << editDistance1D(a, b);
    return 0;
}
