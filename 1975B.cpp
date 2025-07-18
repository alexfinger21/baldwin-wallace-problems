    #include <bits/stdc++.h>
     
    using namespace std;
     
    int32_t main() {
        int t;
        cin >> t;
        
        while (t--) {
            int len;
            cin >> len;
            
            priority_queue<int, vector<int>, greater<int>> pq;
            
            while (len--) {
                int n;
                cin >> n;
                
                pq.push(n);
            }
            
            int n1, n2;
            
            n1 = pq.top();
            pq.pop();
            
            n2 = pq.top();
            pq.pop();
            
            bool found = false;
            
            while (!pq.empty()) {
                int n = pq.top();
                
                if (n1 == n2 && n2 != n || n2 % n1 == 0) {
                    n2 = n;
                }
                
                if (n % n1 == 0 || n % n2 == 0) {
                    
                } else {
                    found = true;
                    break;
                }
                
                pq.pop();
            }
            
            cout << (found ? "nO" : "YEs") << '\n';
        }
        
        return 0;
    }
