#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ------------------ Memoization (Top-Down DP) ------------------

ll f(ll n, vector<ll> &a, vector<ll> &dp) {
    if (dp[n] != -1) return dp[n];

    ll ans = 1;
    for (ll i = 1; i < n; i++) {
        if (a[i] < a[n]) {
            ans = max(ans, f(i, a, dp) + 1);
        }
    }

    return dp[n] = ans;
}

ll lis_memoization(ll n, vector<ll> &a) {
    vector<ll> dp(n + 1, -1);
    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans = max(ans, f(i, a, dp));
    }
    return ans;
}

// ------------------ Tabulation (Bottom-Up DP) ------------------

ll lis_tabulation(ll n, vector<ll> &a) {
    vector<ll> dp(n + 1, 1);

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    return *max_element(dp.begin() + 1, dp.end());
}

// ------------------ Best Approach (Binary Search + Greedy) ------------------

ll lis_best(ll n, vector<ll>& a) {
    vector<ll> temp;
    temp.push_back(a[1]); // temp[1] = a[1] will not work because temp is an empty vector

    for (ll i = 2; i <= n; i++) {
        
        if (a[i] > temp.back()) {
            temp.push_back(a[i]);
        }
        
        else {
            ll idx = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[idx] = a[i];
        }
    }

    return temp.size();
}

// ------------------ Main Function ------------------

int main() {
    optimize();

    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for (ll i = 1; i <= n; i++) cin >> a[i];

    cout << "Memoization: " << lis_memoization(n, a) << endl;
    cout << "Tabulation: " << lis_tabulation(n,a) << endl;
    cout << "Best O(n log n): " << lis_best(n, a) << endl;

    return 0;
}
