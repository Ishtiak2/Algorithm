#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

// ------------------ O(n^2) LIS with subsequence recovery ------------------

vector<ll> lis(vector<ll> &a, ll n) {
    
    vector<ll> dp(n+1, 1);
    vector<ll> prev(n+1,0);

    ll maxLength = -1;
    ll maxIndex = -1;

    for(ll i = 1; i <= n; i++) {
        ll temp = 0;
        ll ind = 0;

        for(ll j = 1; j < i; j++) {
            if(a[i] > a[j]) {
                temp = max(temp,dp[j]);
                if(temp == dp[j]) ind = j;
            }    
        }
        
        prev[i] = ind;
        dp[i] = temp + 1;

        if(dp[i] >= maxLength) {
            maxLength = dp[i];
            maxIndex = i;
        }
    }


    vector<ll> subs;
    ll i = maxIndex;

    while(i != 0) {
        subs.push_back(a[i]);
        i = prev[i];
    }

    reverse(subs.begin(),subs.end());

    return subs;

}

// ------------------ O(n log n) LIS with subsequence recovery ------------------

vector<ll> lis_best_with_seq(ll n, vector<ll>& a) {
    vector<ll> temp;        // smallest tail for each LIS length
    vector<ll> pos(n+1);    // pos[len] = index of last element of LIS length len
    vector<ll> prev(n+1, -1); // prev[i] = previous index in LIS ending at i

    ll length = 0;          // length of LIS
    for (ll i = 1; i <= n; i++) {
        auto it = lower_bound(temp.begin(), temp.end(), a[i]);
        ll idx = it - temp.begin(); // position in temp

        if (it == temp.end()) {
            temp.push_back(a[i]);
            length++;
        } else {
            *it = a[i];
        }

        pos[idx] = i;
        if (idx > 0) {
            prev[i] = pos[idx - 1];
        }
    }

    // Backtrack to find LIS
    vector<ll> lis;
    ll cur = pos[length - 1];
    while (cur != -1) {
        lis.push_back(a[cur]);
        cur = prev[cur];
    }
    reverse(lis.begin(), lis.end());

    return lis;
}

// ------------------ Main Function ------------------

int main()
{
    optimize();
    ll n;
    cin >> n;

    vector<ll> a(n+1);

    for(ll i = 1; i <= n; i++) cin >> a[i];

    vector<ll> subs =  lis(a,n);

    
    //for(auto it: subs) cout << it <<" ";

    vector<ll> longSubs = lis_best_with_seq(n,a);

    for(auto it : longSubs) cout << it <<" ";


    return 0;
}