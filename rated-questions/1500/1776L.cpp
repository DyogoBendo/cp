#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    string s;
    cin >> s;
    int p = 0, n = 0;
    for (auto c: s)
    {
        if(c == '+') p++;
        else n++;
    }

    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);

        int total = a*(p-n);

        int operations = total > 0 ? p : n;

        if(total == 0){
            cout << "YES" << endl;
            continue;
        }
        if(a == b){
            cout << "NO" << endl;
            continue;
        }
        
        total = abs(total);

        int diff = a - b;

        if(total % diff){
            cout << "NO" << endl;
            continue;
        }
        int needed = total / diff;        
        if(needed > operations){
            cout << "NO" << endl;
        } else{
            cout << "YES" << endl;
        }
    }   
    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    solve();
}