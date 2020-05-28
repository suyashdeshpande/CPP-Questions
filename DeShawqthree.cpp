#include <bits/stdc++.h>
using namespace std;

long computePeriods(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> forAns(n), revAns(n);
    vector<int> fMaxAns(n, INT_MIN);
    forAns[0] = arr[0];
    fMaxAns[0] = forAns[0];
    for (int i = 1; i < n; i++) {
        forAns[i] = max(arr[i], forAns[i - 1] + arr[i]);
        fMaxAns[i] = max(fMaxAns[i - 1], forAns[i]);
    }

    revAns[n - 1] = arr[n - 1];
    int ans = revAns[n - 1] + forAns[n - 1 - k - 1];
    int rev = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        revAns[i] = max(arr[i], arr[i] + revAns[i + 1]);
        rev = max(rev, revAns[i]);
        int a = i - k - 1;
        if (a >= 0) {
            ans = max(ans, rev + fMaxAns[a]);
        } else
            break;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& i : a) cin >> i;
    int k;
    cin >> k;
    cout << computePeriods(a, k) << endl;
    return 0;
}
