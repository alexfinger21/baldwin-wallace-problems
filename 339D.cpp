#include <bits/stdc++.h>

using ll=long long;
using namespace std;

vector<int> tree;
vector<int> a;
vector<int> b;

int build_tree(int order, int idx = 1, ll l = 0, ll r = a.size() - 1) {
    if (l == r) {
        tree[idx] = a[l];
        b[l] = idx;

        return tree[idx];
    }

    ll diff = (r - l);

    if (order % 2) {
        tree[idx] = build_tree(order ^ 1, idx*2, l, l + diff/2) ^ build_tree(order ^ 1, idx*2 + 1, l + diff/2 + 1, r);

        return tree[idx];
    } else {
        tree[idx] = build_tree(order ^ 1, idx*2, l, l + diff/2) | build_tree(order ^ 1, idx*2 + 1, l + diff/2 + 1, r);

        return tree[idx];
    }
}

void adjust_tree(int idx, int new_v) {
    idx = b[idx];
    int order = 0;
    tree[idx] = new_v;

    while (idx != 1) {
        int m = idx % 2;
        int neighbor;
        idx /= 2;

        if (m) {
            neighbor = tree[idx * 2]; 
        } else {
            neighbor = tree[idx * 2 + 1]; 
        }

        if (order) {
            tree[idx] = new_v ^ neighbor;
        } else {
            tree[idx] = new_v | neighbor;
        }

        new_v = tree[idx];
        order ^= 1;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> n >> m;

    int ord = (n + 1) % 2;
    n = pow(2, n);

    a = vector<int>(n);
    b = vector<int>(n);

    for (int i = 0; i<n; ++i) {
        cin >> a[i];
    }

    tree = vector<int>(4*n);

    build_tree(ord);

    /*
    for (auto x : tree) {
        cout << x << ' ';
    }
    cout << endl;
    cout << tree[1] << '\n';
    */

    for (int i = 0; i<m; ++i) {
        int idx, val;
        cin >> idx >> val;

        adjust_tree(idx - 1, val);

        /*
        for (auto x : tree) {
            cout << x << ' ';
        }

        cout << endl;
        */

        cout << tree[1] << '\n';
    }

    return 0;
}
