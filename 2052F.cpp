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

        string s0, s1;
        cin >> s0 >> s1;

        vector<vector<int>> dp(n+1, vector<int>(4));

        s0 += '#';
        s1 += '#';

        dp[0][0] = 1;

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<4; ++j) {
                if (!dp[i][j]) {continue;}
                
                if (j == 0 && s0[i] == '.' && s1[i] == '.') {
                    dp[i+1][j] = dp[i][j]; 
                    dp[i+1][j] = min(dp[i+1][j], 5); 
                } 

                bool stop = false;
                int cnt = 0;

                if ((j & 1) == 0 && s0[i] == '.') { //0 and 2
                    ++cnt;
                    if (s0[i+1] == '#') {
                        stop = true;
                    }
                }
                
                if ((j & 2) == 0 && s1[i] == '.') { //0 and 1
                    cnt += 2;
                    if (s1[i+1] == '#') {
                        stop = true;
                    }
                }
                
                if (!stop) {
                    dp[i+1][cnt] += dp[i][j];
                    dp[i+1][cnt] = min(5, dp[i+1][cnt]);
                }

            }
        }

        int res = dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3];

        if (res == 1) {
            cout << "Unique\n";
        } else if (res > 1) {
            cout << "Multiple\n";
        } else {
            cout << "None\n";
        }
    }

    return 0;
}
