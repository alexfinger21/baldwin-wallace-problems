#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    while (t--) {
        ll k;
        cin >> k;

        ll n = k;  
        
        ll left = k, right = 2 * k;  
        while (left < right) {
            ll mid = left + (right - left) / 2; 
            ll perfect_squares = sqrt(mid);
            if (mid - perfect_squares < k) {
                left = mid + 1; 
            } else {
                right = mid;            
            }
        }

        cout << left << '\n'; 
    }

    return 0;
}

