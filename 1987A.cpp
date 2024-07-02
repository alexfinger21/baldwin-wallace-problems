#include <iostream>

using namespace std;

int32_t main() {
    int t;
    cin >> t;
    
    while (t--) {
        int ram, k;
        cin >> ram >> k;
        
        cout << (ram-1)*k+1 << '\n';
    }
    
    return 0;
}
