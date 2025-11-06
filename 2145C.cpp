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

        cin >> n >> s;
        int cnta = 0, cntb = 0;
        for (char c : s) 
            if (c == 'a') {
                ++cnta; 
            } else {
                ++cntb;
            }

        int D = cnta - cntb;
        if (D == 0) {
            cout << 0 << '\n';
            continue;
        }
        unordered_map<int,int> last;
        last.reserve(n*2+5);
        last[0] = 0;
        int pref = 0;
        int ans = n+1;
        for (int i = 1; i <= n; ++i) {
            pref += (s[i-1] == 'a') ? 1 : -1;
            int need = pref - D;
            auto it = last.find(need);
            if (it != last.end()) ans = min(ans, i - it->second);
            last[pref] = i;
        }
        if (ans == n+1 || ans == n) cout << -1 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}
