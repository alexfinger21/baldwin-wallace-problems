#include <iostream>
#include <string>

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    
    while (t--) {
        int arr['G' - 'A' + 1] = {0, 0, 0, 0, 0, 0, 0};
        int n;
        int r;
        
        string s;
        cin >> n >> r >> s;
        
        for (int i = 0; i<s.size(); ++i) {
            ++arr[s[i] - 'A'];
        }
        
        int res = 0;
        
        for (int i = 0; i<7; ++i) {
            res += max(r - arr[i], 0);
        }
        
        cout << res << '\n';
    }
    
    return 0;
    
}
