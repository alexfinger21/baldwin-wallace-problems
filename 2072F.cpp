#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) { 
        int n, k;
        cin >> n >> k;
        
        string ks = to_string(k);
        string res = "";
        string tr = "";
        int ps = 0;
        int cnt = n/4 - 1;
        for (int i = 0; i<32; ++i) {
            cnt -= pow(2, i);
            if (cnt >= 0) {
                ++ps;
            } else {
                break;
            }
        }
        int h = !ps ? n : ((n-pow(2, ps)*4));
        if (h >= 4) {
            h %= 4;
        }
        int tc = (n-pow(2, ps)*4)/4;
        if ((int)(n-pow(2, ps)*4) % 4) {
            ++tc;
        }

        if (h == 0) {
            h = 4;
        }

        if (n == pow(2, ps)*4) {
            for (int i = 0; i<n; ++i) {
                res += ks +' ';
            }
            cout << res << '\n';
            continue;
        }

        if (h == 1) {
            tr = ks + " 0 0 0";
        } else if (h == 2) {
            tr = ks + ' ' + ks + " 0 0";
        } else if (h == 3) {
            tr = ks + " 0 " + ks + " 0";
        } else {
            tr = ks + ' ' + ks + ' ' + ks + ' ' + ks;
        }

        for (int i = 0; i<tc-1; ++i) {
            res += tr + ' ';
        } 

        if (h == 1) {
            res += ks + ' ';
        } else if (h == 2) {
            res += ks + ' ' + ks + " ";
        } else if (h == 3) {
            res += ks + " 0 " + ks + " ";
        } else {
            res += ks + ' ' + ks + ' ' + ks + ' ' + ks + ' ';
        }


        for (int i = 0; i<n-(max(0,(tc-1)*4*2) + h*2); ++i) {
            res += "0 ";
        }
        
        if (n > 4) {
            for (int i = 0; i<tc-1; ++i) {
                res += tr + ' ';
            }

            if (h == 1) {
                res += ks + ' ';
            } else if (h == 2) {
                res += ks + ' ' + ks + " ";
            } else if (h == 3) {
                res += ks + " 0 " + ks + " ";
            } else {
                res += ks + ' ' + ks + ' ' + ks + ' ' + ks + ' ';
            }
        }
        
        cout << res << '\n';
        cout << h << ' ' << tc << ' ' << ps << endl;
    }

    return 0;
}
