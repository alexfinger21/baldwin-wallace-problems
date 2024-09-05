#include <bits/stdc++.h>
 
using ll=long long;
using namespace std;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
 
    while (t--) {
        int n, q;
 
        cin >> n >> q;
 
        string s1, s2;

        cin >> s1 >> s2;
        
        vector<vector<int>> cn1(26, vector<int>(s1.size()));
        vector<vector<int>> cn2(26, vector<int>(s1.size()));

        for (int i = 0; i<s1.size(); ++i) {
            for (int j = 0; j<26; ++j) {
                cn1[j][i] = 0;
                if (j == (s1[i] - 'a')) {
                    cn1[j][i] = cn1[j][max(i-1, 0)] + 1;
                } else {
                    cn1[j][i] = cn1[j][max(i-1, 0)];
                }
            }
        }

        for (int i = 0; i<s1.size(); ++i) {
            for (int j = 0; j<26; ++j) {
                cn2[j][i] = 0;
                if (j == (s2[i] - 'a')) {
                    cn2[j][i] = cn2[j][max(i-1, 0)] + 1;
                } else {
                    cn2[j][i] = cn2[j][max(i-1, 0)];
                }
            }
        }

        for (int i = 0; i<q; ++i) {
            int l, r;
            cin >> l >> r;

            int c = 0;

            for (int j = 0; j<26; ++j) {
                if (l <= 1) {
                    int sum1 = cn1[j][r-1];
                    int sum2 = cn2[j][r-1];
                    c += abs(sum1 - sum2);
                } else {
                    int sum1 = cn1[j][r-1] - cn1[j][l-2];
                    int sum2 = cn2[j][r-1] - cn2[j][l-2];
                    c += abs(sum1 - sum2);
                }

            }

            cout << c/2 << '\n'; //divide by 2 b/c if 1 character occurs in the strring that doesnt occur in the other, the same will happen for that other character (double counting)
        }
 
    }
 
    return 0;
}
