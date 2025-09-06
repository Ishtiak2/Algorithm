#include <bits/stdc++.h>
using namespace std;

//Count of distinct elements or frequency of an element in a subarray [L, R] over multiple queries.


const int MAXN = 1e5 + 5;
int BLOCK_SIZE;

struct Query {
    int L, R, idx;
    bool operator<(const Query &other) const {
        int block_a = L / BLOCK_SIZE;
        int block_b = other.L / BLOCK_SIZE;
        if (block_a != block_b)
            return block_a < block_b;
        return R < other.R;
    }
};

int a[MAXN]; // Input array
int freq[MAXN]; // Frequency of each element
int ans[MAXN];  // Answers for each query
int currAnswer = 0;

void add(int x) {
    freq[x]++;
    if (freq[x] == 1) currAnswer++; // First occurrence
}

void remove(int x) {
    freq[x]--;
    if (freq[x] == 0) currAnswer--; // Removed take occurrence
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    BLOCK_SIZE = sqrt(n);

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].L >> queries[i].R;
        queries[i].idx = i;
    }

    sort(queries.begin(), queries.end());

    int currL = 0, currR = -1;

    for (auto query : queries) {
        int L = query.L;
        int R = query.R;

        while (currL > L) add(a[--currL]);
        while (currR < R) add(a[++currR]);
        while (currL < L) remove(a[currL++]);
        while (currR > R) remove(a[currR--]);

        ans[query.idx] = currAnswer;
    }

    for (int i = 0; i < q; ++i)
        cout << ans[i] << '\n';

    return 0;
}
