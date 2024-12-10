#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "1\n";
            continue;
        }

        ll ones = 1;
        ll res = 1;

        while (ones < n) {
            ++res;
            
            ones += (ones+1)*2-ones-1;
            ++ones;
        }
        cout << res << '\n';
    }

    return 0;
}
