#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e7;
int tree[4 * N + 1];
int root[4 * N + 1];

void squareRoot() {
    for (int i = 1; i < 4 * N + 1; i++) {
        root[i] = sqrt(i);
    }
}


void updateRange(int node, int l, int r, int x, int y, int val = 0) {
    // no overlap
    if (y < l || x > r) {
        return;
    }
    if (l == r) {
        tree[node] = (int)root[tree[node]];
        return;
    }

    int left = 2 * node + 1, right = 2 * node + 2;
    int m = (l + r) / 2;
    updateRange(left, l, m, x, y);
    updateRange(right, m + 1, r, x, y);
    tree[node] = tree[left] + tree[right];
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
    int left = 2 * node + 1, right = 2 * node + 2;

    tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int ql, int qr) {
    //total overlapping
    if (ql <= l && qr >= r) {
        return tree[node];
    }

    // no overlapping
    if (qr < l || ql > r) {
        return 0;
    }

    // partial overlapping
    int m = (l + r) / 2;
    int left = query(2 * node + 1, l, m, ql, qr);
    int right = query(2 * node + 2, m + 1, r, ql, qr);

    return left + right;
}

int32_t main() {
    int test = 1;
    int n;
    squareRoot();
    while (scanf("%lld", &n) != EOF) {
        cout << "Case #" << test << ":\n";
        vector<int> a(n);
        for (int& i : a) cin >> i;
        buildTree(0, a, 0, n - 1);
        int t;
        cin >> t;
        while (t--) {
            int q, l, r;
            cin >> q >> l >> r;
            if (q == 0) {
                updateRange(0, 0, n - 1, l - 1, r - 1);
            } else {
                cout << query(0, 0, n - 1, l - 1, r - 1) << '\n';
            }
        }
        test++;
        cout << '\n';
    }
}
