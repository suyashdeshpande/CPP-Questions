#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie()
int n, t, i, j, k;

bool valid(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

void computeSum(int A, int B, int C, vi& v) {
    for (i = A; i <= B; i++) {
        for (j = B; j <= C; j++) {
            v.push_back(i + j);
        }
    }
}
void computeSum(int A, int B, int C, int D, vi& v) {
    for (i = A; i <= B; i++) {
        for (j = C; j <= D; j++) {
            v.push_back(i + j);
        }
    }
}

void mySort(vi& v) {
    sort(v.begin(), v.end());
}

int count() {
}

void solve(int A, int B, int) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    int ans = 0;
    vi yzSum, xySum, xzSum;
    computeSum(A, B, C, xySum);
    computeSum(B, C, D, yzSum);
    computeSum(A, B, C, D, xzSum);
    mySort(xySum);
    mySort(yzSum);
    mySort(xzSum);

    for (int x = A; x <= B; x++) {
        int l = yzSum[0], r = yzSum.back();
        while (l < r) {
            int m = (l + r) / 2;
            if (yzSum[m] < x) {
                r = m;
            } else
                l = m + 1;
        }
        // yzSum.size() - r
    }
}

int32_t main() {
    FAST;
    solve();
}