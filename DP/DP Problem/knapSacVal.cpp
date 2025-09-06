#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);

ll knapSacVal2D(ll n, ll cap, const vector<ll>& w, const vector<ll>& val) {
    const ll INF = 1e15;

    // Total possible value sum
    ll V = accumulate(val.begin() + 1, val.end(), 0LL);

    // dp[i][j] = min weight to achieve value j using first i items
    vector<vector<ll>> dp(n + 1, vector<ll>(V + 1, INF));
    dp[0][0] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= V; j++) {
            
            if (j < val[i]) {
                dp[i][j] = dp[i - 1][j]; // can't take item
            }
            
            else {
                dp[i][j] = min(dp[i - 1][j], w[i] + dp[i - 1][j - val[i]]);
            }
        }
    }

    // Find maximum value achievable within capacity
    for (ll j = V; j >= 0; j--) {
        if (dp[n][j] <= cap) return j;
    }
    return 0;
}

int main() {
    optimize();

    ll n, W;
    cin >> n >> W;
    vector<ll> wt(n + 1), val(n + 1);
    for (ll i = 1; i <= n; i++) cin >> wt[i] >> val[i];

    cout << knapSacVal2D(n, W, wt, val) << endl;
    return 0;
}
