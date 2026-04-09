#include <bits/stdc++.h>

using ll=long long;
using namespace std;

ll buildTree(vector<ll>& tree, vector<ll>& arr, vector<pair<int, int>>& ranges, int s, int e, int idx) {
    ranges[idx] = {s, e};

    if (s >= e) {
        tree[idx] = arr[s];
        return arr[s];
    }

    int mid = (s+e)/2;

    tree[idx] = buildTree(
            tree,
            arr,
            ranges,
            s,
            mid,
            idx*2 + 1
        ) + 
        buildTree(
            tree,
            arr,
            ranges,
            mid,
            e, idx*2 + 2
        );

    return tree[idx];
}

ll getRange(vector<ll>& tree, vector<ll>& arr, vector<pair<int, int>>& ranges, int s, int e, int idx) {
    ll sm = 0;
    
    /*
    cout << "IDX: " << idx << endl;
    cout << ranges[idx].first << ' ' << ranges[idx].second << endl;
    cout << s << ' ' << e << endl;
    */


    if (s == ranges[idx].first && e == ranges[idx].second) {
        return tree[idx];
    }

    if (s <= (ranges[idx].first + ranges[idx].second)/2) {
        sm += getRange(
            tree,
            arr,
            ranges,
            s,
            min(e, (ranges[idx].first + ranges[idx].second)/2),
            idx*2 + 1
        );
    }

    if (e > (ranges[idx].first + ranges[idx].second)/2) {
        sm += getRange(tree,
            arr,
            ranges,
            max(s, (ranges[idx].first + ranges[idx].second)/2 + 1),
            e, idx*2 + 2
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
    vector<pair<int, int>> ranges(4*n);
    vector<ll> arr(n);

    for (int i = 0; i<n; ++i) {
        cin >> arr[i];
    }

    buildTree(tree, arr, ranges, 0, n-1, 0);

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

        cout << getRange(tree, arr, ranges, s, e, 0) << endl;
    }



    return 0;
}
