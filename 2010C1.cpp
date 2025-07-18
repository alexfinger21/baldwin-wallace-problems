#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int n = s.size();
    //cout << n << endl;

    bool found = false;
    for (int i = 1; i<((n+1)/2); ++i) {
        //cout << i << endl;
        int j;
        for (j = i; j<n; ++j) {
            if (s[j-i] != s[j]) {
                //cout << "j "<< j << endl;
                break;
            }
        }

        if (j == n) {
            found = true;
            cout << "YES\n";
            cout << s.substr(i, n-i) << '\n';
            break;
        }
    }

    if (!found) {
        cout << "NO\n";
    }

    return 0;
}
