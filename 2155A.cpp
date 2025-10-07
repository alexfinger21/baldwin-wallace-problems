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

        int res = 0;
        int win = n;
        int l = 0;

        while (win > 1) {
            res += win/2 + l/2;
            int wh = win/2;
            win -= wh;
            l-=l/2;
            l += wh;
            n = win + l;
        }
        while (l>1) {
            res += win/2 + l/2;
            l-=l/2;
        }
        ++res;
        cout << res << '\n';
    }

    return 0;
}
