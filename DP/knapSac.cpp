#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);

// 1D Weight-Based Knapsack DP (Most common, Time Complexity: O(n * W), Spcae: O(W))

ll knapSac1D(ll n, ll cap, vector<ll> &w, vector<ll> &v) {
    vector<ll> dp(cap + 1, 0);
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = cap; j >= w[i]; j--) {
            dp[j] = max(dp[j], v[i] + dp[j - w[i]]);
        }
    }
    return dp[cap];
}

// 2D Weight-Based Knapsack DP (Classical DP Table, Time : O(n * W), Space: O(n * W))

ll knapSac2D(ll n, ll cap, vector<ll> &w, vector<ll> &v) {
    vector<vector<ll>> dp(n + 1, vector<ll>(cap + 1, 0));
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = 0; j <= cap; j++) {
            
            if(j < w[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], v[i] + dp[i - 1][j - w[i]]);
        }
    }
    return dp[n][cap];
}

// Value-Based Knapsack DP (When W is large, but sum of values is small), Time: O(n*sum_v)
//Value- Based Knapsack is simmilar to the Weight-Based Knapsack.

//1D Value- Based Knapsack DP  Time: O(n*sum_v)
ll knapSacValueDP(ll n, ll cap, vector<ll> &w, vector<ll> &v) {
    
    ll sumV = accumulate(v.begin(), v.end(), 0LL);

    const ll INF = 1e18;
    vector<ll> dp(sumV + 1, INF);
    dp[0] = 0;

    for(ll i = 1; i <= n; i++) {
        for(ll j = sumV; j >= v[i]; j--) {
            dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
        }
    }

    for(ll i = sumV; i >= 0; i--) {
        if(dp[i] <= cap)
            return i;
    }
    return 0;
}

// 2D Value-Based Knapsack DP 

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
    
    ll n, x;
    cin >> n >> x;

    vector<ll> w(n + 1), value(n + 1);
    for(ll i = 1; i <= n; i++) cin >> w[i];
    for(ll i = 1; i <= n; i++) cin >> value[i];

    // Choose which method to use:

    cout << knapSac1D(n, x, w, value) << endl;

    //cout << knapSac2D(n, x, w, value) << endl;
    //cout << knapSacValueDP(n, x, w, value) << endl;

    return 0;
}
