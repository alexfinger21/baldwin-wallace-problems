#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int m(vector<int>& h) {
    pair<int, int> mx{0, 0};

    for (int i = 10; i>=1; --i) {
        int p = -1;

        for (int j = 0; j<h.size(); ++j) {
            if (h[j] >= i) {
                p = j;
                break;
            }
        }

        if (p != -1) {
            int score = -1;

            for (int j = p+1; j<h.size(); ++j) {
                if ((i - h[j]) > 1) {
                    score = (h[p] - i + 1) * (i - h[j] - 1);
                    break;
                } else if (h[j] >= i) {
                    p = j;
                }
            }

            if (score == -1) {
                score = h[p] - i + 1;
            }

            if (mx.first < score || (mx.first == score && mx.second > i)) {
                mx.first = score;
                mx.second = i;
            }
        }
    }

    cout << mx.first << ' ' << mx.second << endl;

    if (mx.first) {
        int idx = mx.second;
        int p = 0;

        for (int j = 0; j<h.size(); ++j) {
            if (h[j] >= idx) {
                p = j;
                break;
            }
        }

        cout << p << endl;

        int drop = -1;
        vector<int> heights;
        heights.push_back(h[p]);

        for (int i = p+1; i<h.size(); ++i) {
            if (h[i] < idx - 1) {
                drop = i;
                break;
            } else if (h[i] >= idx) {
                heights.push_back(h[i]);
            }
        }

        if (drop == -1) {
            drop = h.size();
        }

        int ctr = 2;
        int n = heights.size();

        for (int i = drop - 1; i>drop - n; --i) {
            cout << n - ctr << ' ' << i << endl;
            h[i] = heights[n - ctr]; 
            ++ctr;
        }


        for (int i = p; i<=drop - n; ++i) {
            h[i] = idx - 1;
        }

        cout << "hello" << endl;

        if (drop != h.size()) {
            h[drop] += heights[n - 1] - idx + 1;
        }
    }

    return mx.first;
}


int theo(vector<int>& h) {
    pair<int, int> mx{0, 0};

    for (int i = 10; i>=1; --i) {
        int p = -1;

        for (int j = h.size() - 1; j>=0; --j) {
            if (h[j] >= i) {
                p = j;
                break;
            }
        }

        if (p != -1) {
            int score = -1;

            for (int j = p-1; j>=0; --j) {
                if ((i - h[j]) > 1) {
                    score = (h[p] - i + 1) * (i - h[j] - 1);
                    break;
                } else if (h[j] >= i) {
                    p = j;
                }
            }

            if (score == -1) {
                score = h[p] - i + 1;
            }

            if (mx.first < score || (mx.first == score && mx.second > i)) {
                mx.first = score;
                mx.second = i;
            }
        }
    }

    if (mx.first) {
        int idx = mx.second;
        int p = 0;

        for (int j = h.size() - 1; j>=0; --j) {
            if (h[j] >= idx) {
                p = j;
                break;
            }
        }

        int drop = -1;
        vector<int> heights;
        heights.push_back(h[p]);


        for (int i = p-1; i>=0; --i) {
            if (h[i] < idx - 1) {
                drop = i;
                break;
            } else if (h[i] >= idx) {
                heights.push_back(h[i]);
            }
        }

        int n = heights.size();

        int ctr = 2;
        for (int i = drop + 1; i<drop + n; ++i) {
            h[i] = heights[n - ctr]; 
            ++ctr;
        }

        for (int i = p; i>=drop + n; --i) {
            h[i] = idx - 1;
        }

        if (drop != -1) {
            h[drop] += heights[n - 1] - idx + 1;
        }

        cout << "THEO TEST" << endl;
    }

    cout << mx.first << ' ' << mx.second << endl;

    return mx.first;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);

        for (int i = 0; i<n; ++i) {
            cin >> h[i]; 
        }
        for (auto x : h) {
            for (int i = 0; i<x; ++i) {
                cout << "#";
            }
            cout << endl;
        }

        cout << "---" << endl;


        int r = m(h);
            for (auto x : h) {
                for (int i = 0; i<x; ++i) {
                    cout << "#";
                }
                cout << endl;
            }
        int l = theo(h);
        cout << "boi" << endl;

        int res1 = r;
        int res2 = l;

        while (l != 0 && r != 0) {
            cout << "Theo" << endl;
            for (auto x : h) {
                for (int i = 0; i<x; ++i) {
                    cout << "#";
                }
                cout << endl;
            }

            r = m(h);

            cout << "Madeline" << endl;
            for (auto x : h) {
                for (int i = 0; i<x; ++i) {
                    cout << "#";
                }
                cout << endl;
            }

            l = theo(h);

            res1 += r;
            res2 += l;
        }

        cout << res1 << ' ' << res2 << endl;

    }

    return 0;
}
