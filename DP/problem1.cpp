#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll editDistance1D(vector<ll>& a, vector<ll>& b) {
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
                curr[j] = 1 + min({prev[j], curr[j - 1]});
        }
        swap(prev, curr); //very important
    }

    return prev[m];
}


int main()
{
    optimize();

    ll t;
    cin >> t;

    for(ll i = 1; i <= t; i++) {
        ll n;
        cin >> n;

        vector<ll> a(n),b(n);
        for(ll i = 0; i < n; i++) cin >> a[i];
        for(ll i = 0; i < n; i++) cin >> b[i];

        cout <<"Case " << i << ": " << editDistance1D(a,b) << endl;
    }
    return 0;
}