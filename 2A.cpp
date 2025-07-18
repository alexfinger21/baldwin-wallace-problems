    #include <bits/stdc++.h>
     
    using ll=long long;
    using namespace std;
     
    int32_t main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        map<string, ll> m;
        vector<pair<string, ll>> moves; 
     
        ll n;
        cin >> n;
     
        string maxS = "";
     
        for (int i = 0; i<n; ++i) {
            string s;
            cin >> s;
     
            ll score;
            cin >> score; 
     
            moves.push_back(make_pair(s, score));
     
            if (m.count(s)) {
                m[s] += score;
            } else {
                m[s] = score;
            }
     
        }
        for (auto x : m) {
            if (maxS.size() < 1) {
                maxS = x.first;
            }
            if (x.second > m[maxS]) {
                maxS = x.first;
            }
        }
     
        ll maxScore = m[maxS];
        set<string> maxes;
     
        for (auto x : m) {
            if (x.second == maxScore) {
                maxes.insert(x.first);
            }
        }
     
        m.clear();
     
        for (auto x : moves) {
            string s = x.first;
            ll score = x.second;
            if (m.count(s)) {
                m[s] += score;
            } else {
                m[s] = score;
            }
     
            if (m[s] >= maxScore && find(maxes.begin(), maxes.end(), s) != maxes.end()) {
                maxS = s;
                break;
            }
     
        }
     
        cout << maxS << '\n';
     
        return 0;
    }
