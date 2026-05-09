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
 
        vector<pair<int, int>> ind(n, {-1, 0});
        vector<int> a(2*n);
 
        for (int i = 0; i<2*n; ++i) {
            int p;
            cin >> p;
 
            a[i] = p;
 
            if (ind[p].first == -1) {
                ind[p].first = i;
            } else {
                ind[p].second = i;
            }
        } 
 
        int ctr = (ind[0].first + ind[0].second) / 2;
        set<int> nums;
        bool t = false;
        int r2 = -1;
 
        if ((ind[0].second - ind[0].first) % 2 == 0) {
            t = true;
 
            if (t) {
                nums.insert(a[ctr]);
            }
 
            for (int i = ctr+1; i<2*n; ++i) {
                if (!nums.count(a[i]) && ((ind[a[i]].first) + (ind[a[i]].second)) / 2 == ctr) {
                    if (t && (ind[a[i]].second - ind[a[i]].first) % 2) {
                        break;
                    }
 
                    if (!t && (ind[a[i]].second - ind[a[i]].first) % 2 == 0) {
                        break;
                    }
 
                    nums.insert(a[i]);
                } else {
                    break;
                }
            }
 
            for (auto x : nums) {
                if (x - r2 <= 1) {
                    r2 = x;
                } else {
                    break;
                }
            }
 
            ++r2;
        }
 
        if (n > 1) {
            int c = (ind[1].first + ind[1].second) / 2;                
 
            if (c != ctr) {
                if (ind[0].first == c || ind[0].second == c) {
                    if ((ind[1].second - ind[1].first) % 2 == 0) {
                        ctr = c;
                        t = true;
                    }
                } 
            }
        }
 
        nums.clear();
 
        if (t) {
            nums.insert(a[ctr]);
        }
 
        for (int i = ctr+1; i<2*n; ++i) {
            if (!nums.count(a[i]) && ((ind[a[i]].first) + (ind[a[i]].second)) / 2 == ctr) {
                if (t && (ind[a[i]].second - ind[a[i]].first) % 2) {
                    break;
                }
 
                if (!t && (ind[a[i]].second - ind[a[i]].first) % 2 == 0) {
                    break;
                }
 
                nums.insert(a[i]);
            } else {
                break;
            }
        }
 
        int res = -1;
 
        for (auto x : nums) {
            if (x - res <= 1) {
                res = x;
            } else {
                break;
            }
        }
 
        ++res;
        
        // cout << res2 << endl;
        cout << max(r2, max(1, res)) << '\n';
 
    } 
 
    return 0;
}
