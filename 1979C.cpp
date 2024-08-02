#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll gcd(ll a, ll b) {
    while (a != 0) {
        ll temp = b % a;
        b = a;
        a = temp;
    }

    return a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        ll fracs[n];

        ll tsum = 0;
        ll leastMul = 1;

        for (int i = 0; i<n; ++i) {
            int num;
            cin >> num;

            leastMul = lcm(leastMul, num);
            fracs[i] = num;
        }

        for (int i = 0; i<n; ++i) {
            tsum += leastMul / fracs[i];
        }

        if (tsum < leastMul) {
            for (int i = 0; i<n; ++i) {
                cout << leastMul / fracs[i] << ' ';
            }
            cout << '\n';
        } else {
            cout << "-1\n";
        }
    }

    return 0;
}
