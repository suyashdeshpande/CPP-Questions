#include <bits/stdc++.h>
using namespace std;

#define int long long
// const int N = 1e5;
// int a[N];

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;

        int ans = 0;

        int nextEven = n;
        int nextFour = n;
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] % 4 == 0)
            {
                nextFour = i;
                nextEven = i;
            }
            else if (a[i] % 2 == 0)
            {
                nextFour = nextEven;
                nextEven = i;
            }
            ans += nextEven - i + n - nextFour;
        }

        cout << ans << endl;
    }
}