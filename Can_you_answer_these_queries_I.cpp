#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Node {
    int maxSubarraySum;
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
};

const int N = 1e5;
Node tree[4 * N + 1];

// void update(int i, int l, int r, int node, int val) {
//     if (i < l || i > r) return;
//     if (l == r) {
//         tree[node] = val;
//         return;
//     }
//     int m = (l + r) / 2;
//     update(i, l, m, 2 * node + 1, val);
//     update(i, m + 1, r, 2 * node + 2, val);
//     tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
// }

// min range sum
void buildTree(int node, vector<int>& a, int l, int r) {
    // leaf node
    if (l == r) {
        tree[node].maxPrefixSum = tree[node].maxSubarraySum = tree[node].maxSuffixSum = tree[node].totalSum = a[l];
        return;
    }
    int m = (l + r) / 2;
    buildTree(2 * node + 1, a, l, m);
    buildTree(2 * node + 2, a, m + 1, r);
    int left = 2 * node + 1, right = 2 * node + 2;

    tree[node].totalSum = tree[left].totalSum + tree[right].totalSum;
    tree[node].maxPrefixSum = max(tree[left].maxPrefixSum, tree[left].totalSum + tree[right].maxPrefixSum);
    tree[node].maxSuffixSum = max(tree[right].maxSuffixSum, tree[right].totalSum + tree[left].maxSuffixSum);
    tree[node].maxSubarraySum = max({tree[node].maxPrefixSum,
                                     tree[node].maxSuffixSum,
                                     tree[left].maxSubarraySum,
                                     tree[right].maxSubarraySum,
                                     tree[left].maxSuffixSum + tree[right].maxPrefixSum});
}

Node query(int node, int l, int r, int ql, int qr) {
    Node result;
    result.maxPrefixSum = result.maxSubarraySum = result.maxSuffixSum = result.totalSum = -600000;

    //total overlapping
    if (ql <= l && qr >= r) {
        return tree[node];
    }

    // no overlapping
    if (qr < l || ql > r) {
        return result;
    }

    // partial overlapping
    int m = (l + r) / 2;
    Node left = query(2 * node + 1, l, m, ql, qr);
    Node right = query(2 * node + 2, m + 1, r, ql, qr);
    result.totalSum = left.totalSum + right.totalSum;
    result.maxPrefixSum = max(left.maxPrefixSum, left.totalSum + right.maxPrefixSum);
    result.maxSuffixSum = max(right.maxSuffixSum, right.totalSum + left.maxSuffixSum);
    result.maxSubarraySum = max({result.maxPrefixSum,
                                 result.maxSuffixSum,
                                 left.maxSubarraySum,
                                 right.maxSubarraySum,
                                 left.maxSuffixSum + right.maxPrefixSum});
    return result;
}

int32_t main() {
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
        cout << query(0, 0, n - 1, l - 1, r - 1).maxSubarraySum << "\n";
    }
}