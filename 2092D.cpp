#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        map<char, int> freq;
        freq['T'] = 0;
        freq['I'] = 0;
        freq['L'] = 0;

        for (int i = 0; i<n; ++i) {
            ++freq[s[i]];
        }
        
        int freqC = 0;

        for (auto x : freq) {
            if (x.second > 0) {
                ++freqC;
            }
        }

        if (freqC < 2) {
            cout << "-1\n";
            continue;
        }

        int mxCount = 2*n;

        vector<int> ops;

        while (ops.size() < mxCount) {
            if (freq['T'] == freq['I'] && freq['I'] == freq['L']) {
                break;
            }
            bool changed = false;

            char mxL = 'T';
            char mnL = 'T';
            char othr = 'T';

            for (auto x : freq) {
                if (x.second > freq[mxL]) {
                    mxL = x.first;
                }
            }

            for (auto x : freq) {
                if (x.second < freq[mnL]) {
                    mnL = x.first;
                }
            }

            for (auto x : freq) {
                if (x.first != mnL && x.first != mxL) {
                    othr = x.first;
                }
            }

            //cout << "----------" << endl;

            for (int i = 0; i<s.size()-1; ++i) {
                if (s[i] != s[i+1]) {
                    if (s[i] == mxL || s[i+1] == mxL) {
                        if (s[i] != othr && s[i+1] != othr) {
                            if (freq[othr] < freq[mxL]) {
                                ++freq[othr];
                                s = s.substr(0, i+1) + othr + s.substr(i+1, s.size()-i);
                                ops.push_back(i);
                                //cout << mxL << ' ' << mnL << ' ' << s << endl;
                                changed = true;
                            }
                        } else {
                            if (freq[mnL] < freq[mxL]) {
                                ++freq[mnL];
                                s = s.substr(0, i+1) + mnL + s.substr(i+1, s.size()-i);
                                ops.push_back(i);
                                //cout << mxL << ' ' << mnL << ' ' << s << endl;
                                changed = true;
                            }
                        }
                    }
                }
            }
            
            if (!changed) {
                //cout << "--change---" << endl;
                for (int i = 0; i<s.size()-1; ++i) {
                    if (s[i] != s[i+1]) {
                        if (s[i] != othr && s[i+1] != othr) {
                            ++freq[othr];
                            s = s.substr(0, i+1) + othr + s.substr(i+1, s.size()-i);
                            ops.push_back(i);
                            //cout << mxL << ' ' << mnL << ' ' << s << endl;
                            changed = true;
                        } else if (s[i] != mnL && s[i+1] != mnL) {
                            ++freq[mnL];
                            s = s.substr(0, i+1) + mnL + s.substr(i+1, s.size()-i);
                            ops.push_back(i);
                            //cout << mxL << ' ' << mnL << ' ' << s << endl;
                            changed = true;
                        } else {
                            ++freq[mxL];
                            s = s.substr(0, i+1) + mxL + s.substr(i+1, s.size()-i);
                            ops.push_back(i);
                            //cout << mxL << ' ' << mnL << ' ' << s << endl;
                            changed = true;
                        }
                        break;
                    }
                }
            }

            /*
            for (auto x :freq) {
                cout << x.first << ' ' << x.second << endl;
            }
            */
            //cout << "----------" << endl;
        }

        if (ops.size() >= mxCount) {
            cout << "-1\n";
            continue;
        }

        cout << ops.size() << '\n';
        for (auto x : ops) {
            cout << x+1 << '\n';
        }
    }

    return 0;
}
