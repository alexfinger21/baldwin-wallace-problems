#include <bits/stdc++.h>

using ll=long long;
using namespace std;

string nr = "narek";

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> dp(n, vector<int>(5, -1e9));

        for (int i = 0; i<n; ++i) {
            string s;
            cin >> s;

            for (int j = 0; j<6; ++j) {
                if (j == 5 || ((i > 0) && dp[i-1][j] != -1e9)) { 
                    int tn = 0;
                    int c = 0;
                    int current = j == 5 ? -1 : j;

                    for (int k = 0; k<m; ++k) {
                        if (nr.find(s[k]) != string::npos) {
                            if (s[k] == nr[(current + 1) % 5]) {
                                current = (current + 1) % 5;
                                if (current == 4) {
                                    ++c;
                                }
                            }
                            ++tn;
                        }
                    }
                    //cout << "C = " << c << " tn = " << tn << endl;
                    //cout << "CURRENT: " << current << endl;

                    if (current != -1) {
                        //cout << j << ' ' << current << ' ' << c << ' ' << tn << endl;
                        int lastscr = dp[max(0, i-1)][j == 5 ? 4 : j] == -1e9 ? 0 : dp[max(0, i-1)][j == 5 ? 4 : j];
                        if (j == 5) {
                            lastscr = max(lastscr, 0);
                        }

                        dp[i][current] = max(dp[i][current], max(dp[max(0, i-1)][current], lastscr + c*10 - tn));
                        //cout << "new score: " << dp[i][current] << endl;
                    }
                }
            }
            //cout << "---" << endl;
            for (int j = 0; j<5; ++j) {
                dp[i][j] = max(dp[max(0, i-1)][j], dp[i][j]); 
                //cout << dp[i][j] << ' ';
            }
            //cout << endl;
        }
        
        int mx = 0;

        for (auto x : dp[n-1]) {
            mx = max(mx, x);
        }
        cout << mx << '\n';
    }

    return 0;
}
