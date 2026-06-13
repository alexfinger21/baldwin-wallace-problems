#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll n, x, s;
        string mem;

        cin >> n >> x >> s;
        cin >> mem;

        ll space = 0;
        ll intro = x;

        vector<ll> missing(n);

        bool found_a = false;
        vector<ll> ambi_miss;
        vector<int> indx;
        map<int, int> min_cnt;

        for (int i = 0; i<n; ++i) {
            if (mem[i] == 'A') {
                found_a = true;
                if (ambi_miss.size()) {
                    ++min_cnt[ambi_miss.back()];
                }

                ambi_miss.push_back(space);
                indx.push_back(i);
            } else if (mem[i] == 'I') {
                if (intro > 0) {
                    space += s - 1;
                    --intro;
                    missing[i] = space;
                    if (found_a) {
                        ambi_miss[ambi_miss.size() - 1] = min(ambi_miss[ambi_miss.size() - 1], space);
                    }
                }
            } else {
                if (found_a) {
                    --space;
                    ambi_miss[ambi_miss.size() - 1] = min(ambi_miss[ambi_miss.size() - 1], space);
                    missing[i] = space;
                } else {
                    space = max(space - 1, 0LL);
                }
            }
            // cout << missing[i] << endl;
        }

        if (ambi_miss.size()) {
            ++min_cnt[ambi_miss.back()];
        }

        /*
        cout << "---" << endl;

        for (int i = 0; i<ambi_miss.size(); ++i) {
            cout << ambi_miss[i] << endl;
        }
        */

        vector<int> pref_I(n, 0);
        int current_I_count = 0;
        for(int i = 0; i < n; ++i){
            if(mem[i] == 'I') current_I_count++;
            pref_I[i] = current_I_count;
        }

        ll added = 0;
        int converted_a = 0;  

        for (int i = 0; i < ambi_miss.size(); ++i) {
            
            int I_before = (indx[i] == 0 ? 0 : pref_I[indx[i] - 1]) + converted_a;

            if (min_cnt.begin()->first + added <= 0 && I_before < x) {
                added += s - 1;
                mem[indx[i]] = 'I';
                converted_a++;
            } else {
                --added;
                mem[indx[i]] = 'E';
            }

            --min_cnt[ambi_miss[i]];

            if (!min_cnt[ambi_miss[i]]) {
                min_cnt.erase(ambi_miss[i]);
            }
        }

        //cout << mem << endl;

        added = 0;
        space = 0;
        intro = x;

        for (int i = 0; i<n; ++i) {
            if (mem[i] == 'E') {
                if (space) {
                    ++added;
                    --space;
                }
            } else {
                if (intro) {
                    ++added;
                    --intro;
                    space += s - 1;
                }
            }
        }

        cout << added << '\n';
    }

    return 0;
}
