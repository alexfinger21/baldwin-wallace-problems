#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;


        ll s = 0;

        if (b > a) {
            s += (b + a + max(1LL, b-a-n+1)) * (min(b - a, n))/2;
        } 

        s += max(0LL, (n - max(0LL, (b-a)))) * a;

        cout << s << '\n';
    }

    return 0;
}
