#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll editDistance(string& a, string& b) {
    ll n = a.size();
    ll m = b.size();

    vector<ll> curr(n+1), prev(n+1,0);

    for(ll i = 0; i <= n; i++) {
        prev[i] = i;
    }

    for(ll i = 1; i <= m; i++) {
        curr[0] = i;
        for(ll j = 1; j <= n; j++) {
            
            if(b[i-1] == a[j-1])
                curr[j] = prev[j-1];

            else{
                curr[j] = min({prev[j-1], prev[j], curr[j-1]}) + 1;
            }
        }

        swap(prev,curr);
    }

    return prev[n];
}

int main()
{
    optimize();
    string a;
    string b;

    cin >> a >> b;

    cout << editDistance(a,b);
    return 0;
}