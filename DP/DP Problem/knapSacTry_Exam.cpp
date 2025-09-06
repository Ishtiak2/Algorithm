#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll knapSac(ll n, ll w, vector<ll> wt, vector<ll> val) {
    
    ll V = 0;
    for(ll i = 1; i <= n; i++) V +=val[i];

    vector<vector<ll>> dp(n+1, vector<ll> (V+1, 1e12));

    dp[0][0] = 0;
    
    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= V; j++) {
            if(val[i] <= j)
                dp[i][j] = min(dp[i-1][j], wt[i] + dp[i-1][j - val[i]]);
            else dp[i][j] = dp[i-1][j];    
        }
    }

    for(ll i = V; i >= 0; i--) {
        if(dp[n][i] <= w)
            return i;
    }
    return 0;

}

int main()
{
    optimize();
    ll n,w;
    cin >> n >> w;

    vector<ll> wt(n+1),val(n+1);

    for(ll i = 1; i <= n; i++) cin >> wt[i] >> val[i];
    cout << knapSac(n,w,wt,val);
    return 0;
}