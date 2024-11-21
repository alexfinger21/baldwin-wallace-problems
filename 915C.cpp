#include <bits/stdc++.h>

using ll=long long;
using namespace std;

int len = 0;
string bb;

string dfs(string str, string left) {
    for (int i = left.size() - 1; i>=0; --i) {
        if (left[i] == '0' && str.size() == 0) {
            continue;
        }
        if ((i == left.size() - 1 || left[i] != left[i+1]) && left[i] != 'a') {
            if (stoll(bb.substr(0, str.size() + 1)) >= stoll(str + left[i])) {
                string str_l = str + left[i];
                left[i] = 'a';
                if (len == str_l.size()) {
                    //cout << str_l << endl;
                    return str_l;
                } else {
                    string dfs_res = dfs(str_l, left);
                    //cout << dfs_res << endl;
                    if (dfs_res != "-1") {
                        return dfs_res;
                    } else {
                        left[i] = str_l[str_l.size()-1];
                    }
                }
            }
        }
    }
    //cout << str << ' '<< endl;

    return "-1";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin >> a >> bb;

    sort(a.begin(), a.end());

    len = bb.size();


    if (a.size() < bb.size()) {
        for (int i = a.size()-1; i>=0; --i) {
            cout << a[i];
        }
        cout << '\n';
    } else {
        cout << dfs("", a);
    }

    return 0;
}
