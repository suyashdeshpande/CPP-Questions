#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int n;
    cin >> n;
    cout << n << " ";
    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = n * 3 + 1;
        cout << n << " ";
    }
}