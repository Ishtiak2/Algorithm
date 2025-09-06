#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll lis(ll n, vector<ll> a) {
    vector<ll> dp(n+1, 1);

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin()+1, dp.end());
}


int main() {
    ll n;
    cin >> n;

    vector<ll> a(n+1);

    for(ll i = 1; i <= n; i++) cin >> a[i];

    cout << lis(n,a);

    return 0;
}