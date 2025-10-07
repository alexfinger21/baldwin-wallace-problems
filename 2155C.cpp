#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 676767677LL;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin>>n;
        vector<ll>a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        vector<ll>b(n+1), S(n+1);
        for(int i=1;i<=n;i++) {
            b[i]=a[i]-n+i-1;
        };
        S[0]=0;
        for(int i=1;i<=n;i++) {
            S[i]=b[i]-S[i-1];
        }
        ll ans=0;
        if(n%2==0){
            ll X=S[n];
            if(X<0||X>n){ 
                cout<<0<<"\n"; continue;
            }
            bool ok=true;
            vector<ll> p(n+1);
            p[0]=0;
            for(int i=1;i<=n;i++){
                if(i%2==1) p[i]=S[i]+X;
                else p[i]=S[i];
                if(p[i]<0||p[i]>i) { 
                    ok=false; break; 
                }
                ll d=p[i]-p[i-1];
                if(!(d==0||d==1)){ 
                    ok=false; break; 
                }
            }
            cout << (ok?1:0) << "\n";
        } else {
            if (S[n]!=0){ 
                cout<<0<<"\n"; continue;
            }
            ll L=0, R=n;
            bool ok = true;
            for (int i=1;i<=n;i++) {
                if(i%2==1){
                    ll l1 = -S[i];
                    ll r1 = i - S[i];
                    L = max(L, l1);
                    R = min(R, r1);
                } else {
                    if(!(0<=S[i] && S[i]<=i)){ 
                        ok=false; break; 
                    }
                }
            }
            if(!ok || L>R){ 
                cout<<0<<"\n"; continue;
            }
            for(int i=1;i<=n;i++){
                if(i%2==1){
                    ll d = S[i]-S[i-1];
                    ll l2 = -d;
                    ll r2 = 1 - d;
                    L = max(L, l2);
                    R = min(R, r2);
                } else {
                    ll d = S[i]-S[i-1];
                    ll l2 = d - 1;
                    ll r2 = d;
                    L = max(L, l2);
                    R = min(R, r2);
                }
                if(L>R){ 
                    ok=false; break; 
                }
            }
            if(!ok || L>R) { 
                cout<<0<<"\n"; continue;
            }
            ll cnt = max(0LL, R - L + 1);
            cnt %= MOD;
            cout<<cnt<<"\n";
        }
    }
    return 0;
}

