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

        c[p[i]] = i;
    }

    // sort by cyclic shifts
    for (int h = 0; (2 << h) < n; ++h) {

    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {

    }

    return 0;
}
