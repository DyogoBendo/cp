#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> v(k, -1);

    string s;
    cin >> s;
    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '?') continue;
        int x = s[i] - '0';

        if(v[i%k] == -1) v[i%k] = x;
        else if (v[i%k] != x) possible = false;
    }

    int av = 0, ss = 0;
    for (int i = 0; i < k; i++)
    {
        if(v[i] == 1) ss++;
        else if(v[i] == -1) av++;
    }
    
    if(ss > k/2) possible = false;
    if(ss + av < k/2) possible = false;
    
    cout << (possible? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}