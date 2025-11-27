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
        string s;
        cin >> n;
        cin >> s;

         int cnt = 1;

         for (int i = 0; i<n-1; ++i) {
            if (s[n-1] == s[i]) {
                ++cnt;
            }
         }

        cout << n-cnt << '\n';
    }

    return 0;
}
