#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int idx = 0;
vector<int> tree;
vector<int> res;

void dfs(int index) {
    res[idx++] = index;

    if (tree[index*2] != -1) {
        dfs(index*2);
        res[idx++] = index;
    }

    if (tree[index*2 + 1] != -1) {
        dfs(index*2 + 1);
        res[idx++] = index;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    tree = vector<int>(4*n);
    res = vector<int>(2*n - 1);

    return 0;
}
