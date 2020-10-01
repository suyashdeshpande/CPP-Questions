#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int tree[4 * N + 1];


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
    int right = query(2 * node + 1, m + 1, r, ql, qr);
    return min(left, right);
}
void update(int i, int l, int r, int node, int val) {
    if (i < l || i > r) return;
    if (l == r) {
        tree[node] = val;
        return;
    }
    int m = (l + r) / 2;
    update(i, l, m, 2 * node + 1, val);
    update(i, m + 1, r, 2 * node + 2, val);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    buildTree(1, a, 0, n - 1);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 0, n - 1, l, r) << "\n";
    }
}
