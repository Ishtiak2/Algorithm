#include <bits/stdc++.h>
using namespace std;

int n;
long long solutions = 0;

void solve(int row, int cols, int d1, int d2) {
    if (row == n) {
        solutions++;
        return;
    }
    int available = ((1 << n) - 1) & ~(cols | d1 | d2);
    while (available) {
        int pos = available & -available; // lowest set bit
        available -= pos;
        solve(row + 1, cols | pos, (d1 | pos) << 1, (d2 | pos) >> 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    solve(0, 0, 0, 0);
    cout << "Total solutions: " << solutions << "\n";
    return 0;
}

//To find total solutions