#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        ll res = 0;

        for (int a = 1; a<=min(n, x); ++a) {
            for (int b = 1; b<=min((x-a), n/a); ++b) {
                int c = min((n-a*b)/(a+b), x-a-b);
                res += c;
            }
        }

        cout << res << '\n';
    }

    return 0;
}
