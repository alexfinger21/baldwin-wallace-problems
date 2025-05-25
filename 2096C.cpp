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

        vector<vector<ll>> h(n, vector<ll>(n));

        for (int i = 0; i<n; ++i) {
            for (int j = 0; j<n; ++j) {
                cin >> h[i][j];
            }
        }

        vector<ll> a(n), b(n);

        for (int i = 0; i<n; ++i) {
            cin >> a[i];
        }

        for (int i = 0; i<n; ++i) {
            cin >> b[i];
        }
            
        vector<vector<ll>> dp(n, vector<ll>(2));

        ll res = 0;

        dp[0][0] = 0;
        dp[0][1] = a[0];
        
        ll prev = 0;

        for (int i = 1; i<n; ++i) {
            //0
            if (h[i][0] == h[i-1][0]) {
                dp[i][0] = dp[i-1][1];
            } else if (h[i][0] - h[i-1][0] == 1) {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            }

            //1
            if (h[i][0] == h[i-1][0]) {
                dp[i][1] = dp[i-1][0] + a[i];
            } else if (h[i][0] - h[i-1][0] == -1) {
                dp[i][1] = dp[i-1][1] + a[i];
            } else {
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
            }
        }

        cout << "no change: ";
        for (auto x : dp) {
            cout << x[0] << ' ';
        }
        cout << "\nchange: ";
        for (auto x : dp) {
            cout << x[1] << ' ';
        }

        cout << "\n";

        for (int c = 1; c<n; ++c) {
            for (int i = 1; i<n; ++i) {
                //0
                prev = dp[i][0];
                if (h[i][c] == h[i-1][c]) {
                    if (h[i][c-1] - h[i-1][c-1] == 1) {
                        dp[i][0] = -1;
                    } else {
                        dp[i][0] = dp[i-1][1];
                    }
                } else if (h[i][c] - h[i-1][c] == 1) {
                    if (h[i][c-1] - h[i-1][c-1] == 0) {
                        dp[i][0] = -1;
                    } else {
                        dp[i][0] = dp[i-1][0];
                    }
                } else {
                    if (dp[i-1][0] == -1) {
                        dp[i][0] = dp[i-1][1];
                    } else if (dp[i-1][1] == -1) {
                        dp[i][0] = dp[i-1][0];
                    } else {
                        dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
                    }
                }

                if (prev != -1 && dp[i][0] != -1) {
                    dp[i][0] = max(prev, dp[i][0]);
                } else {
                    dp[i][0] = -1;
                }

                //1
                prev = dp[i][1];
                if (h[i][c] == h[i-1][c]) {
                    if (h[i][c-1] - h[i-1][c-1] == -1) {
                        dp[i][1] = -1;
                    } else {
                        dp[i][1] = dp[i-1][0] + a[i];
                    }
                } else if (h[i][c] - h[i-1][c] == -1) {
                    if (h[i][c-1] - h[i-1][c-1] == 0) {
                        dp[i][1] = -1;
                    } else {
                        dp[i][1] = dp[i-1][1] + a[i];
                    }
                } else {
                    if (dp[i-1][0] == -1) {
                        dp[i][1] = dp[i-1][1] + a[i];
                    } else if (dp[i-1][1] == -1) {
                        dp[i][1] = dp[i-1][0] + a[i];
                    } else {
                        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + a[i];
                    }
                }

                if (dp[i][1] == dp[i][0] && dp[i][1] == -1) {
                    res = -1;
                    break;
                }

                if (prev != -1 && dp[i][1] != -1) {
                    dp[i][1] = max(prev, dp[i][1]);
                } else {
                    dp[i][1] = -1;
                }

                cout << "no change: ";
                for (auto x : dp) {
                    cout << x[0] << ' ';
                }
                cout << "\nchange: ";
                for (auto x : dp) {
                    cout << x[1] << ' ';
                }

                cout << "\n";
            }
        }

        if (res != -1) {
            if (dp[n-1][0] == -1) {
                res = dp[n-1][1];
            } else if (dp[n-1][1] == -1) {
                res =  dp[n-1][0];
            } else {
                res = min(dp[n-1][0], dp[n-1][1]);
            }
        }

        cout << "COLUMNS\n";

        dp = vector<vector<ll>>(n, vector<ll>(2));

        dp[0][0] = 0;
        dp[0][1] = b[0];

        for (int i = 1; i<n; ++i) {
            //0
            if (h[0][i] == h[0][i-1]) {
                dp[i][0] = dp[i-1][1];
            } else if (h[0][i] - h[0][i-1] == 1) {
                dp[i][0] = dp[i-1][0];
            } else {
                dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
            }

            //1
            if (h[i][0] == h[i-1][0]) {
                dp[i][1] = dp[i-1][0] + b[i];
            } else if (h[i][0] - h[i-1][0] == -1) {
                dp[i][1] = dp[i-1][1] + b[i];
            } else {
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + b[i];
            }
        }

        cout << "no change: ";
        for (auto x : dp) {
            cout << x[0] << ' ';
        }
        cout << "\nchange: ";
        for (auto x : dp) {
            cout << x[1] << ' ';
        }

        cout << "\n";

        for (int r = 1; r<n; ++r) {
            for (int i = 1; i<n; ++i) {
                //0
                prev = dp[i][0];
                if (h[r][i] == h[r][i-1]) {
                    if (h[r-1][i] - h[r-1][i-1] == 1) {
                        dp[i][0] = -1;
                    } else {
                        dp[i][0] = dp[i-1][1];
                    }
                } else if (h[r][i] - h[r][i-1] == 1) {
                    if (h[r-1][i] - h[r-1][i-1] == 0) {
                        dp[i][0] = -1;
                    } else {
                        dp[i][0] = dp[i-1][0];
                    }
                } else {
                    if (dp[i-1][0] == -1) {
                        dp[i][0] = dp[i-1][1];
                    } else if (dp[i-1][1] == -1) {
                        dp[i][0] = dp[i-1][0];
                    } else {
                        dp[i][0] = min(dp[i-1][0], dp[i-1][1]);
                    }
                }

                if (prev != -1 && dp[i][0] != -1) {
                    dp[i][0] = max(prev, dp[i][0]);
                } else {
                    dp[i][0] = -1;
                }


                //1
                prev = dp[i][1];
                if (h[r][i] == h[r][i-1]) {
                    if (h[r-1][i] - h[r-1][i-1] == -1) {
                        dp[i][1] = -1;
                    } else {
                        dp[i][1] = dp[i-1][0] + b[i];
                    }
                } else if (h[r][i] - h[r][i-1] == -1) {
                    if (h[r-1][i] - h[r-1][i-1] == 0) {
                        dp[i][1] = -1;
                    } else {
                        dp[i][1] = dp[i-1][1] + b[i];
                    }
                } else {
                    if (dp[i-1][0] == -1) {
                        dp[i][1] = dp[i-1][1] + b[i];
                    } else if (dp[i-1][1] == -1) {
                        dp[i][1] = dp[i-1][0] + b[i];
                    } else {
                        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + b[i];
                    }
                }

                if (prev != -1 && dp[i][1] != -1) {
                    dp[i][1] = max(prev, dp[i][1]);
                } else {
                    dp[i][1] = -1;
                }

                if (dp[i][1] == dp[i][0] && dp[i][1] == -1) {
                    res = -1;
                    break;
                }

                cout << "no change: ";
                for (auto x : dp) {
                    cout << x[0] << ' ';
                }
                cout << "\nchange: ";
                for (auto x : dp) {
                    cout << x[1] << ' ';
                }

                cout << "\n";
            }
        }

        if (res != -1) {
            if (dp[n-1][0] == -1) {
                res += dp[n-1][1];
            } else if (dp[n-1][1] == -1) {
                res += dp[n-1][0];
            } else {
                res += min(dp[n-1][0], dp[n-1][1]);
            }
        }

        cout << res << '\n';
    }

    return 0;
}
