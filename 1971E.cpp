#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int binS(int b, int t, long long goal, vector<long>& pos) {
    if (t == b) {
        return t;
    } else if (pos[(b+t)/2] < goal) {
        return binS((b+t)/2+1, t, goal, pos);
    } else {
        return binS(b, (b+t)/2, goal, pos);
    }
}
 
int main() {
    int cc;
    cin >> cc;
 
    for (int c = 0; c<cc; ++c) {
        int n, k, q;
        cin >> n >> k >> q;
 
        vector<long> pos;
        vector<long> times;
 
        pos.push_back(0);
        times.push_back(0);
        
        for (int i = 0; i<k; ++i) {
            long v;
            cin >> v;
 
            pos.push_back(v);
        }
        
        //pos.push_back(n);
 
        for (int i = 1; i<=k; ++i) {
            long v;
            cin >> v;
 
            times.push_back(v);
        }
 
        for (int i = 0; i<q; ++i) {
            long long g;
            cin >> g;
            
 
            int r = binS(0, pos.size() - 1, g, pos) - 1;
            
            if (pos[r+1] == g) {
                cout << times[r+1] << ' ';
                continue;
            }
            //cout << endl << pos[upper] << " - UPPER ";
            //cout << endl << "thing - " << (times[pos[upper-1]] + (double)(times[pos[upper]]-times[pos[upper-1]]) 
            //        * ((g-pos[upper-1] + (upper>=2 ? pos[upper-2] : 0))/((double)(pos[upper]) - pos[upper-1]))) << endl;
            //cout << (g) << " - GOAL" << endl;
            //cout << (g-pos[r]) << "- GOAL THING: " << (g-pos[r]) * ((times[r+1]-times[r])/(double)(pos[r+1]-pos[r])) << endl;
            long long answer = times[r] + (g-pos[r])*(times[r+1]-times[r])/(pos[r+1]-pos[r]);
            //b[r] + (c-a[r])*(b[r+1]-b[r])/(a[r+1]-a[r])
            cout << answer << ' ';
 
        }
        
        cout << '\n';
    }
 
    return 0;
}
