#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<int> facs2(1e6+1);
    facs2[0] = 0;

    for (int i = 1; i<=1e6; ++i) {
        int mx = 1;
        int tf = 0;
        int rs = 0;
        while (mx <= i) {
            if (!(i % mx)) {
                rs = tf;
            } else {
                break;
            }
            ++tf;
            mx *= 2;
        }

        facs2[i] = rs + facs2[i-1];
    }

    while (t--) { 
        int n, k;
        cin >> n >> k;
        
        string ks = to_string(k);
        string res = "";
        
        for (int i = 0; i<n; ++i) {
            if (facs2[n-1] == (facs2[i] + facs2[n-i-1])) {
                res += ks + ' ';
            } else {
                res += "0 ";
            }
        } 

        cout << res << '\n';
    }

    return 0;
}
