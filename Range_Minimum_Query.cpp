#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int tree[4 * N + 1];
int lazy[4 * N + 1] = {0};

void updateRangeLazy(int node, int l, int r, int incVal, int x, int y) {
    // no overlap
    if (y < l || x > r) {
        return;
    }

    // first resolve the lazy value
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        // both child should exist
        // path the lazy value down to children
        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    //  complete overlap
    // leaf node case will be handled in this
    if (l >= x && r <= y) {
        tree[node] += incVal;
        // both child should exist
        if (l != r) {
            lazy[2 * node + 1] += incVal;
            lazy[2 * node + 2] += incVal;
        }
        return;
    }

    int m = (l + r) / 2;
    updateRangeLazy(2 * node + 1, l, m, incVal, x, y);
    updateRangeLazy(2 * node + 2, m + 1, r, incVal, x, y);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int queryLazy(int node, int l, int r, int x, int y) {
    // no overlap
    if (y < l || x > r) {
        return INT_MAX;
    }

    // first resolve the lazy value
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        // both child should exist
        // path the lazy value down to children
        if (l != r) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }

    //  complete overlap, leaf node will be handled in this
    if (l >= x && r <= y) {
        return tree[node];
    }

    int m = (l + r) / 2;
    int left = queryLazy(2 * node + 1, l, m, x, y);
    int right = queryLazy(2 * node + 2, m + 1, r, x, y);
    return min(left, right);
}

// min range sum
void buildTree(int node, vector<int>& a, int l, int r) {
    // leaf node
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildTree(2 * node + 1, a, l, m);
    buildTree(2 * node + 2, a, m + 1, r);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int query(int node, int l, int r, int ql, int qr) {
    // no overlapping
    if (qr < l || ql > r) {
        return INT_MAX;
    }

    //total overlapping
    if (ql <= l && qr >= r) {
        return tree[node];
    }

    // partial overlapping
    int m = (l + r) / 2;
    int left = query(2 * node + 1, l, m, ql, qr);
    int right = query(2 * node + 2, m + 1, r, ql, qr);
    return min(left, right);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    buildTree(0, a, 0, n - 1);

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n - 1, l, r) << "\n";
    }
}