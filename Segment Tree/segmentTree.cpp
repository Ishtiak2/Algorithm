#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    vector<ll> tree;
    int n;

public:
    SegmentTree(vector<ll> &arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int node, int l, int r, vector<ll> &arr) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, arr);
        build(2 * node + 2, mid + 1, r, arr);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, ql, qr) + 
               query(2 * node + 2, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int idx, ll val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, val);
        else
            update(2 * node + 2, mid + 1, r, idx, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }

    void update(int idx, ll val) {
        update(0, 0, n - 1, idx, val);
    }
};

int main() {
    vector<ll> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree st(arr);

    cout << "Sum [1, 3] = " << st.query(1, 3) << endl; // 3 + 5 + 7 = 15
    st.update(1, 10); // arr[1] = 10
    cout << "Sum [1, 3] after update = " << st.query(1, 3) << endl; // 10 + 5 + 7 = 22
}
