#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;

        cin >> n;
        vector<int> f(n + 1);

        for (int i = 1; i <= n; ++i)
            cin >> f[i];
        bool check = false;
        for (int i = 1; i <= n; ++i)
            for (int j = i + 2; j <= n; ++j)
                if (f[i] == f[j])
                {
                    check = true;
                    break;
                }
        if (check)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}