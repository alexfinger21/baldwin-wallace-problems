    #include <iostream>
     
    using namespace std;
     
    int32_t main() {
        int t;
        cin >> t;
        
        while(t--) {
            int x, y;
            cin >> x >> y;
            
            if (y < -1) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
        
        return 0;
    }
