#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30;
set<int> S[MAXN + 1];

void precompute() {
    S[0].insert(0);
    for (int n = 1; n <= MAXN; n++) {
        for (int L = 1; L <= n; L++) {
            int f = L * (L - 1) / 2;
            for (int x : S[n - L]) {
                S[n].insert(x + f);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int total_segments = n * (n - 1) / 2;
        int T = total_segments - k;
        if (S[n].find(T) != S[n].end()) {
            vector<int> runs;
            int cur_n = n;
            int cur_T = T;
            while (cur_n > 0) {
                for (int L = 1; L <= cur_n; L++) {
                    int fL = L * (L - 1) / 2;
                    if (S[cur_n - L].find(cur_T - fL) != S[cur_n - L].end()) {
                        runs.push_back(L);
                        cur_n -= L;
                        cur_T -= fL;
                        break;
                    }
                }
            }
            vector<int> res;
            int prefix = 0;
            for (int L : runs) {
                int start = n - prefix - L + 1;
                for (int i = 0; i < L; i++) {
                    res.push_back(start + i);
                }
                prefix += L;
            }
            for (int i = 0; i < n; i++) {
                cout << res[i];
                if (i < n - 1) cout << " ";
            }
            cout << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}
