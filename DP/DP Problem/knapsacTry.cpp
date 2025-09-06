#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll knapSac(ll n, ll w, vector<ll> wt, vector<ll> val) {
    ll V = 0;
    for(ll i = 1; i <= n; i++) V +=val[i];

    vector<ll> curr(V+1, LLONG_MAX);
    vector<ll> prev(V+1,LLONG_MAX);

    for(ll i = 1; i <= n; i++) {
        
        for(ll j = 1; j <= V; j++) {
            if(val[i] > j) curr[j] = prev[j];
            else curr[j] = min(prev[j], wt[i] + prev[j- val[i]]);
        }

        swap(curr,prev);
    }

    for(ll i = V; i >= 0; i--) {
        if(prev[i] <= w)
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