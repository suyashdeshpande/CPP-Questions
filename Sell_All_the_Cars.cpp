#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9+7;

int32_t main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];
        sort(p.begin(), p.end());
        int ans = 0;
        int day = 0;
        for(int i = n-1; i >=0 ; i--) {
            ans = (ans % mod + max((int)0, p[i] - day) % mod) % mod;
            day++;
        }
        cout << ans << endl;

    }
}