#include <bits/stdc++.h>

using ll=long long;
using namespace std;


ll gcd(ll a, ll b) {
    ll temp = a % b;
    a = b;

    while (temp) {
        b = temp;
        temp = a % b;
        a = b;
    }

    return b; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while (t--) {
        ll a, b, l;
        cin >> a >> b >> l;
        
        ll maxa = 0, maxb = 0;

        ll a2 = a;
        ll b2 = b;
        ll l2 = l;
        a = gcd(a, l);
        b = gcd(b, l);
        //cout << a << ' ' << b << endl;


        while (l > 0 && a != 1) {
            ++maxa;
            l /= a;
        }
        l = l2;

        while (l > 0 && b != 1) {
            ++maxb;
            l /= b;
        }
       
        /*
        for (auto x : facsl) {
            cout << x.first << ' ' << x.second << endl;
        }
        */
        //cout << maxa << endl;
        //cout << maxb << endl;

       set<int> res;

       for (int i = 0; i<=maxa; ++i) {
            for (int j = 0; j<=maxb; ++j) {
                ll mult = pow(a2, i) * pow(b2, j); 
                //cout << "ok " << mult << '\n';
                if (!(l2 % mult)) {
                    res.insert(l2/mult);
                }
            }
       }

        cout << res.size() << '\n';
    }

    return 0;
}
