#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios_base:: sync_with_stdio (0) ; cin.tie (0) ; cout.tie (0) ;

ll editDistance(string a, string b) {
    ll lenA = a.size();
    ll lenB = b.size();

    vector<vector<ll>> dp(lenB+1, vector<ll> (lenA+1,0));

    vector<ll> prev(lenA+1,0),curr(lenA+1,0);


    for(ll i = 0; i <= lenA; i++) prev[i] = i;
    //for(ll j = 0; j <= lenB; j++) dp[j][0] =j;

    for(ll i = 1; i <= lenB; i++) {
        curr[0] = i;
        for(ll j = 1; j <= lenA; j++) {
            if(b[i-1] != a[j-1]){
                //dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
                curr[j] = 1 + min({curr[j-1], prev[j], prev[j-1]});
            }
            else {
                //dp[i][j] = dp[i-1][j-1];
                curr[j] = prev[j-1];
            }
        }

        swap(curr,prev);
    } 
    return prev[lenA];
}
int main()
{
    optimize();
    string a,b;
    cin >> a >> b;

    cout << editDistance(a,b);
    return 0;
}