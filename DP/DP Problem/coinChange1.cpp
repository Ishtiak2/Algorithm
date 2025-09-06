#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll coinChange(ll n, vector<ll> coins, ll amount) {
    const ll INF = 1e12;
    vector<ll> dp(amount+1, INF);

    dp[0] = 0;

    for(ll i = 1; i <= amount; i++) {
        for(auto coin : coins) {
            if(i >= coin) {
                dp[i] = min (dp[i], dp[i-coin] +1);
            }
        }
    }

    if(dp[amount] == INF) return -1;
    else return dp[amount];

}

int main()
{
    optimize();
    ll n;
    cin >> n;

    ll amount;
    cin >> amount;

    vector<ll> coins(n);

    for(ll i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << coinChange(n,coins,amount);

    return 0;
}