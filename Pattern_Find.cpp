#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> lpsCalculate(string p) {
    int n = p.length();
    vector<int> lps(n, 0);

    int i = 0, j = 1;
    while (j < n) {
        if (p[i] == p[j]) {
            lps[j] = i + 1;
            i++, j++;
        } else {
            while (i && p[i] != p[j]) {
                i = lps[i - 1];
            }
            if (p[i] == p[j]) {
                lps[j] = i + 1;
                i++;
            }
            j++;
        }
    }
    return lps;
}

void solve(string p, string t, int &count, vector<int> &ans) {
    vector<int> lps = lpsCalculate(p);
    int np = p.length(), nt = t.length();
    // i -> text
    // j -> pattern
    int i = 0, j = 0;
    while (i < nt) {
        // pattern match successful
        if (j == np) {
            count++;
            ans.push_back(i - j);
            j = lps[np - 1];
        }
        // current character doesn't match
        else if (t[i] != p[j]) {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
        // currrentt character match
        else {
            i++, j++;
        }
    }
}

int32_t main() {
    int t;
    cin >> t;
    string pattern, text;
    while (t--) {
        cin >> text >> pattern;
        int count = 0;
        vector<int> ans;
        solve(pattern, text, count, ans);
        cout << count << "\n";
        for (int i : ans) cout << i << " ";
        cout << '\n';
    }
}