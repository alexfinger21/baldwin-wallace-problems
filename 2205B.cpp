#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll res = 1;
        ll num = 2;

        while (n != 1 && num <= sqrt(n)) {
            if (!(n % num)) {
                res *= num;
                while (!(n % num)) {
                    n /= num;
                }
            }
            ++num;
        }

        if (n != 1) {
            res *= n;
        }
        
        cout << res << '\n';
    }

    return 0;
}
