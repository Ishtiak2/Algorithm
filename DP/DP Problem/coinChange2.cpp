#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll coinChange(ll n, ll amount, vector<ll> &coins) {
    vector<vector<ll>> dp(n+1, vector<ll> (amount + 1, 0));

    for(ll i = 0; i <= n; i++) dp[i][0] = 1;

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <= amount; j++) {
            if(coins[i-1] > j) {
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j - coins[i-1]];
            }
        }
    }

    
    return dp[n][amount];

} 
int main() {
    int amount = 5;
    vector<ll> coins = {1, 2, 5};
    cout << coinChange(3,amount,coins);
    return 0;
}
