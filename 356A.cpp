#include <bits/stdc++.h>

using ll=long long;
using namespace std;

vector<int> tree;
vector<int> winners;

void update(int l, int h, int w, int idx, int lw, int up) {
    if (lw == l && up == h) {
        if (!tree[idx]) {
            for (int i = l; i<=h; ++i) {
                if (i != (w-1) && !winners[i]) {
                    winners[i] = w;
                }
            }

            tree[idx] = w;
        } else {
            if (!winners[tree[idx] - 1] && tree[idx] != w) {
                winners[tree[idx] - 1] = w; 
            }
        }

        return;
    }

    if (l <= (lw + up) / 2) {
        update(l, min(h, (lw+up) / 2), w, idx*2, lw, (lw+up) / 2);
    }

    if (h > (lw + up) / 2) {
        update(max((lw + up)/2 + 1, l), h, w, idx*2 + 1, (lw+up) / 2 + 1, up);
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    tree = vector<int>(4*n);
    winners = vector<int>(n);

    for (int i = 0; i<m; ++i) {
        int l, r, w;
        cin >> l >> r >> w;

        --l; --r;

        update(l, r, w, 1, 0, n-1);
    }

    for (int i = 0; i<n; ++i) {
        cout << winners[i] << ' ';
    }

    cout << '\n';

    return 0;
}
