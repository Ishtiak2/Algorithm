#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define optimize() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1e5 + 5;
ll tree[4 * N], lazy[4 * N];

/// Builds the segment tree in O(n) time
void build(int node, int start, int end, vector<int> &a) {
    if(start == end) {
        tree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        build(2*node, start, mid, a);
        build(2*node+1, mid+1, end, a);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

/// Applies any pending lazy updates to the current node
void push(int node, int start, int end) {
    if(lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node]; // apply lazy
        if(start != end) { // propagate to children
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

/// Returns the sum of values in range [l, r] in O(log n)
ll query(int node, int start, int end, int l, int r) {
    push(node, start, end); // apply pending updates
    
    if(start > r || end < l) return 0; // no overlap
    if(start >= l && end <= r) return tree[node]; // total overlap

    int mid = (start + end) / 2;
    return query(2*node, start, mid, l, r) + query(2*node+1, mid+1, end, l, r);
}

/// Updates index `idx` with value `val` in O(log n)
void updatePoint(int node, int start, int end, int idx, int val) {
    push(node, start, end);
    if(start == end) {
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if(idx <= mid) updatePoint(2*node, start, mid, idx, val);
        else updatePoint(2*node+1, mid+1, end, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

/// Adds `val` to all elements in the range [l, r] in O(log n)
void updateRange(int node, int start, int end, int l, int r, int val) {
    push(node, start, end); // apply pending updates

    if(start > r || end < l) return; // no overlap

    if(start >= l && end <= r) { // total overlap
        lazy[node] += val;
        push(node, start, end);
        return;
    }

    int mid = (start + end) / 2;
    updateRange(2*node, start, mid, l, r, val);
    updateRange(2*node+1, mid+1, end, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

/// Main function to demonstrate usage
int main() {
    optimize();
    
    int n, q;
    cin >> n >> q;
    vector<int> a(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    build(1, 0, n-1, a); // build tree

    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int idx, val;
            cin >> idx >> val;
            updatePoint(1, 0, n-1, idx, val);
        } else if(type == 2) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n-1, l, r) << endl;
        } else if(type == 3) {
            int l, r, val;
            cin >> l >> r >> val;
            updateRange(1, 0, n-1, l, r, val);
        }
    }

    return 0;
}
