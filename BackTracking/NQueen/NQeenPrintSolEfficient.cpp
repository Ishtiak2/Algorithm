#include <bits/stdc++.h>
using namespace std;

const int MAXN = 14;
int n;                           // size of the board
bool col[MAXN], diag1[2*MAXN], diag2[2*MAXN]; // attack trackers
int solution[MAXN];              // store column of queen for each row
int totalSolutions = 0;

void solve(int row) {
    if (row == n) {
        // print the board
        cout << "Solution " << ++totalSolutions << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == solution[i]) cout << "Q ";
                else cout << ". ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    for (int c = 0; c < n; c++) {
        if (!col[c] && !diag1[row+c] && !diag2[row-c+n-1]) {
            col[c] = diag1[row+c] = diag2[row-c+n-1] = true;
            solution[row] = c;
            solve(row + 1);
            col[c] = diag1[row+c] = diag2[row-c+n-1] = false; // backtrack
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n; // input board size
    solve(0);

    cout << "Total solutions: " << totalSolutions << "\n";

    if (totalSolutions == 0) cout << "No solution exists\n";

    return 0;
}

/*

Time Complexity ≈ O(N!)+O(S⋅N^2)
For counting-only without printing → O(N!)
For printing all solutions → add O(S × N²)

Space Complexity=O(N)
*/