#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll buildTree(vector<ll>& tree, vector<ll>& arr, int s, int e, int idx) {
    if (s >= e) {
        tree[idx] = arr[s];
        return arr[s];
    }

    int mid = (s+e)/2;

    tree[idx] = buildTree(
            tree,
            arr,
            s,
            mid,
            idx*2 + 1
        ) + 
        buildTree(
            tree,
            arr,
            mid + 1,
            e, 
            idx*2 + 2
        );

    return tree[idx];
}

ll getRange(vector<ll>& tree, vector<ll>& arr, int rs, int re, int s, int e, int idx) {
    ll sm = 0;
    
    /*
    cout << "IDX: " << idx << endl;
    cout << ranges[idx].first << ' ' << ranges[idx].second << endl;
    cout << s << ' ' << e << endl;
    */


    if (s == rs && e == re) {
        return tree[idx];
    }

    int mid = (rs + re)/2;

    if (s <= mid) {
        sm += getRange(
            tree,
            arr,
            rs,
            mid,
            s,
            min(e, (rs + re)/2),
            idx*2 + 1
        );
    }

    if (e > (rs + re)/2) {
        sm += getRange(tree,
            arr,
            mid+1,
            re,
            max(s, mid + 1),
            e, 
            idx*2 + 2
        );
    }

    return sm;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<ll> tree(4*n);
    vector<ll> arr(n);

    for (int i = 0; i<n; ++i) {
        cin >> arr[i];
    }

    buildTree(tree, arr, 0, n-1, 0);

    for (auto x: tree) {
        cout << x << ' ';
    }

    cout << endl;

    int q;

    cin >> q;

    for (int i = 0; i<q; ++i) {
        int s;
        int e;
        cin >> s >> e;

        cout << getRange(tree, arr, 0, n-1, s, e, 0) << endl;
    }



    return 0;
}
