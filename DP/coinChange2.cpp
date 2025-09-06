#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

/*
    2D DP (Tabulation)
    Time: O(n * amount)
    Space: O(n * amount)
*/

ll change2D(int amount, vector<int>& coins) {
    int n = coins.size();
    
    // For large results, use:
    // vector<vector<unsigned long long>> dp(n, vector<unsigned long long>(amount + 1, 0));

    vector<vector<ll>> dp(n, vector<ll>(amount + 1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= amount; j++) {
            
            if (i == 0) {
                if (j == 0)
                    dp[i][j] = 1;
                
                else if (j % coins[i] == 0)
                    dp[i][j] = 1;
                
                else
                    dp[i][j] = 0;
            }
            
            else {
                if (coins[i] > j)
                    dp[i][j] = dp[i - 1][j];
                
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
            }
        }
    }

    return dp[n - 1][amount];
}

/*
    Optimal 1D DP
    Time: O(n * amount)
    Space: O(amount)
*/

ll change1D(int amount, vector<int>& coins) {
    vector<ll> dp(amount + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make amount 0

    for (int coin : coins) {
        for (int j = coin; j <= amount; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[amount];
}


/*
Recursive function with memoization
Time: O(n * amount)
Space: O(n * amount + stack)
*/

ll f(int i, int amount, vector<int>& coins, vector<vector<ll>>& dp) {
    // Base case
    if (i == 0) {
        if (amount % coins[0] == 0) return 1;
        else return 0;
    }

    if (dp[i][amount] != -1) return dp[i][amount];

    // Not take the coin
    ll notTake = f(i - 1, amount, coins, dp);

    // Take the coin if it fits
    ll take = 0;
    if (coins[i] <= amount) {
        take = f(i, amount - coins[i], coins, dp);
    }

    return dp[i][amount] = take + notTake;
}

ll changeRecursive(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<ll>> dp(n, vector<ll>(amount + 1, -1));
    return f(n - 1, amount, coins, dp);
}


int main() {
    int amount = 11;
    vector<int> coins = {1, 2, 5};

    cout << "2D DP: Number of combinations = " << change2D(amount, coins) << endl;
    cout << "1D Optimized DP: Number of combinations = " << change1D(amount, coins) << endl;
    cout << "Recursive DP (Memoization): Number of combinations = " << changeRecursive(amount, coins) << endl;

    return 0;
}
