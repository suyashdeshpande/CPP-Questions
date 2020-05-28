#include <bits/stdc++.h>
using namespace std;

#define ll long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;
        int ans = 0;
        bool flag = false;
        while (x % 2 == 0)
        {
            x /= 2;
            ans++;
        }
        for (int i = 3; i * i <= x; i += 2)
        {
            while (x % i == 0)
            {
                x /= i;
                ans++;
            }
            if (ans >= k)
            {
                flag = true;
                break;
            }
        }
        if (x > 2)
        {
            ans++;
        }
        if (ans >= k)
        {
            flag = true;
        }
        if (flag)
        {
            cout << 1 << endl;
        }
        else
            cout << 0 << endl;
    }
}