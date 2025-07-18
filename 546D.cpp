#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    vector<int> prime_factors(5000000);
    vector<int> prime_divisor(5000000);
    vector<int> pref_sum(5000000);
   
    prime_divisor[0] = 1;
    prime_factors[0] = 1;
    pref_sum[0] = 0;

    for (int i = 2; i<=5000000; ++i) {
        if (!(prime_divisor[i-1])) {
            prime_divisor[i-1] = 1;
            prime_factors[i-1] = 1;
            for (int j = i*2; j<=5000000; j+=i) {
                prime_divisor[j-1] = i;
            }  
        }
        if (!prime_factors[i-1]) {
            prime_factors[i-1] = prime_factors[i/prime_divisor[i-1]-1] + 1;
        }
        pref_sum[i-1] = pref_sum[i-2] + prime_factors[i-1]; 
    }
    
    while (t--) {
        int a, b;
        cin >> a >> b;

        ll res = pref_sum[a-1]-pref_sum[b-1];

        cout << res << '\n';
    }

    return 0;
}
