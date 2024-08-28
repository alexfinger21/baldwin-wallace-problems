#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;

    int dp[n][m][4];
    vector<tuple<int, int, int>> centers;

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            for (int k = 0; k<4; ++k) {
                dp[i][j][k] = 0;
            }
        }
    }

    //0 - left, 1 - top, 2 - right, 3 - bottom
    vector<vector<int>> good(n);
    for (int i = 0; i<n; ++i) {
        good[i] = vector<int>(m);
    }

    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            char nm;
            cin >> nm;

            int num = nm == '*' ? 1 : 0;

            if (num) {
                good[i][j] = -1;
                dp[i][j][0] += dp[i][max(0, j-1)][0] + 1; 
                dp[i][j][1] += dp[max(0, i-1)][j][1] + 1; 
                dp[i][j][2] = 1;
                dp[i][j][3] = 1;
            }
        }
    }
    for (int i = n-1; i>=0; --i) {
        for (int j = m-1; j>=0; --j) {
            
            if (dp[i][j][2]) {
                dp[i][j][2] = 0;
                dp[i][j][3] = 0;
                dp[i][j][2] = dp[i][min(m-1, j+1)][2]+1; 
                dp[i][j][3] = dp[min(n-1, i+1)][j][3]+1; 
            }
        }
    }



    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            if (dp[i][j][0]>1 && dp[i][j][1]>1  && dp[i][j][2]>1 && dp[i][j][3]>1) {
                int minL = min(min(min(dp[i][j][0], dp[i][j][1]), dp[i][j][2]), dp[i][j][3]);
                //cout << "MIN" << endl;
                //cout << minL << endl;
                //cout << i << ' ' << j << endl;

                for (int k = 0; k<minL; ++k) {
                    good[i+k][j] = 1;
                    good[i-k][j] = 1;
                    good[i][j+k] = 1;
                    good[i][j-k] = 1;
                }

                centers.push_back(make_tuple(i, j, minL-1));
            }
        }
    }

    /*
    cout << "good" << endl;
    for (int i = 0; i<n; ++i) {
        for (int j = 0; j<m; ++j) {
            cout << good[i][j] << ' ';
        }
        cout << endl;
    }
    for (int k = 0; k<4; ++k) {

    for (int i = 0; i<n; ++i) {
    for (int j = 0; j<m; ++j) {
    cout << dp[i][j][k] << ' ';
    }
    cout << endl;
    }
    cout << endl;
    }
    */
    bool f = false;
    for (auto x : good) {
        for (auto g : x) {
            if (g == -1) {
                f = true;
                cout << "-1\n";
                break;
            }
        }
        if (f) {
            break;
        }
    }

    if (!f) {
        cout << centers.size() << '\n';
        for (auto x : centers) {
            cout << get<0>(x)+1 << ' ' << get<1>(x)+1 << ' ' << get<2>(x) << '\n';
        }
    }

    return 0;
}
