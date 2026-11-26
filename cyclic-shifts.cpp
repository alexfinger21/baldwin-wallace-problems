#include <bits/stdc++.h>

using ll=long long;
using namespace std;

vector<int> sort_string_cyclic_shifts(string s) {
    int n = s.size();

    vector<int> p(n);
    vector<int> c(n);

    vector<int> cnt(256);

    // count sort the first characters
   
    for (int i = 0; i<n; ++i) {
        ++cnt[s[i]];
    }

    for (int i = 1; i<cnt.size(); ++i) {
        cnt[i] += cnt[i-1];
    }

    for (int i = 0; i<n; ++i) {
        p[--cnt[s[i]]] = i;
    }

    int rank = 0;
    c[p[0]] = rank;

    for (int i = 1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]]) {
            ++rank;
        }

        c[p[i]] = rank;
    }

    // sort by cyclic shifts

    vector<int> right_p(n), new_c(n);

    for (int h = 0; (1 << h) < n; ++h) {

        for (int i = 0; i<n; ++i) {
            right_p[i] = (p[i] - (1 << h) + n) % n;
            // cout << right_p[i] << endl;
        }

        fill(cnt.begin(), cnt.begin() + rank + 1, 0);

        for (int i = 0; i<n; ++i) {
            ++cnt[c[p[i]]];
        }

        for (int i = 1; i<=rank; ++i) {
            cnt[i] += cnt[i-1];
        }

        for (int i = n-1; i>=0; --i) {
            p[--cnt[c[right_p[i]]]] = right_p[i];
        }

        rank = 0;
        new_c[p[0]] = rank;


        for (int i = 1; i<n; ++i) {
            int c0 = c[p[i - 1]], c0_second = c[(p[i - 1] + (1 << h)) % n];
            int c1 = c[p[i]], c1_second = c[(p[i] + (1 << h)) % n];

            if (c0 != c1 || c0_second != c1_second) {
                ++rank;
            }

            new_c[p[i]] = rank;

        }

        swap(new_c, c);
    }

    return p;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        string s;

        cin >> s;

        vector<int> str_shifts = sort_string_cyclic_shifts(s);

        cout << s.size() << endl;
        
        for (int x : str_shifts) {
            cout << x << ", ";
        }

        cout << endl;
    }

    return 0;
}
