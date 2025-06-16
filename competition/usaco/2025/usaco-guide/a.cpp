#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int st = 0;

    while(st < n && s[st] == s[0]) st++;

    if(st == n){
        cout << s[0] << endl;
        return;
    }

    st--;
    int en = n-1;

    while(en > 0 && s[en] == s[n-1]) en--;
    en ++;    

    int sz = en - st + 1;

    cout << s.substr(st, sz) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}