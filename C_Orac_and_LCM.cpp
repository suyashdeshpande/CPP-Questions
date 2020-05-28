#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vi>
#define pqMax priority_queue<int>
#define pqMin priority_queue<int, vector<int>, greater<int>>
#define pb push_back
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie()
int n, t, i, j, k;

const int N = 200005;

vi fac[N];

void seive() {
    for (int i = 2; i < N; i++) {
        if (fac[i].size() != 0) continue;
        for (int j = i; j < N; j += i) {
            fac[j].pb(i);
        }
    }
}

int32_t main() {
    FAST;
    seive();
    cin >> n;
    vi v(n);
    for (int &i : v) cin >> i;
    vi coun[N];
    for (i = 0; i < n; i++) {
        if (v[i] == 1) continue;
        for (auto j : fac[v[i]]) {
            k = 0;
            while (v[i] % j == 0) {
                k++;
                v[i] /= j;
            }
            coun[j].pb(k);
        }
    }
    for (i = 0; i < N; i++)
        sort(coun[i].begin(), coun[i].end());
    int ans = 1;
    for (i = 2; i < N; i++) {
        if (coun[i].size() < n - 1) continue;
        if (coun[i].size() == n - 1) {
            for (j = 0; j < coun[i][0]; j++) ans *= i;
        }
        if (coun[i].size() == n) {
            for (j = 0; j < coun[i][1]; j++) ans *= i;
        }
    }
    cout << ans;
    return 0;
}