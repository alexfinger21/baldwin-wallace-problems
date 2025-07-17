#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    const int B = 450;  

    while(t--){

        int n, q;
        cin >> n >> q;
        vector<int> col(n);
        for(int i = 0; i < n; ++i) cin >> col[i];
        vector<vector<pair<int,int>>> adj(n);
        vector<tuple<int,int,int>> E;
        for(int i = 0, u, v, w; i < n-1; ++i){
            cin >> u >> v >> w; --u; --v;
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
            E.emplace_back(u,v,w);
        }
        vector<bool> is_h(n);
        vector<int> hid(n, -1), hv;
        for(int i = 0; i < n; ++i) if(adj[i].size() >= B){
            hid[i] = hv.size();
            hv.push_back(i);
            is_h[i] = 1;
        }
        int H = hv.size();
        vector<unordered_map<int,ll>> hm(H);
        ll ans = 0;
        for(auto &[u,v,w]: E){
            if(col[u] != col[v]) ans += w;
            if(is_h[u]) hm[hid[u]][col[v]] += w;
            if(is_h[v]) hm[hid[v]][col[u]] += w;
        }
        vector<vector<pair<int,int>>> hh(H);
        for(int i = 0; i < H; ++i){
            int u = hv[i];
            for(auto &p: adj[u]) if(is_h[p.first])
                hh[i].push_back(p);
        }
        while(q--){
            int v, x; cin >> v >> x; --v;
            int old = col[v];
            if(old == x){
                cout << ans << '\n'; continue; 
            }
            if(is_h[v]){
                int id = hid[v];
                ans += hm[id][old] - hm[id][x];
                for(auto &p: hh[id]){
                    int u = p.first, w = p.second;
                    hm[hid[u]][old] -= w;
                    hm[hid[u]][x] += w;
                }
            } else {
                for(auto &p: adj[v]){
                    int u = p.first, w = p.second;
                    if(col[u] == old) ans += w;
                    if(col[u] == x)   ans -= w;
                    if(is_h[u]){
                        hm[hid[u]][old] -= w;
                        hm[hid[u]][x] += w;
                    }
                }
            }
            col[v] = x;
            cout << ans << '\n';
        }
    }
    return 0;
}

