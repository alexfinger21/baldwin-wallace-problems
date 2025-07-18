#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll a, b;
        cin >> a >> b;

        cout << ((a+b)%2 ? "Alice" : "Bob") << '\n';
        
    }

    return 0;
}
