#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = n / 2;
        if (n == 1)
            cout << 1 << "\n";
        else
            cout << ans << "\n";
        if (n >= 3)
            cout << "3 1 2 3"
                 << "\n";
        else
        {
            if (n == 2)
                cout << "2 1 2"
                     << "\n";
            else
                cout << "1 1"
                     << "\n";
            continue;
        }
        if (n & 1)
        {
            for (int i = 4; i < n; i += 2)
            {
                cout << 2 << " " << i << " " << i + 1 << "\n";
            }
        }

        else
        {
            for (int i = 4; i <= n - 2; i += 2)
            {
                cout << 2 << " " << i << " " << i + 1 << "\n";
            }
            cout << "1 " << n << "\n";
        }
    }
    return 0;
}