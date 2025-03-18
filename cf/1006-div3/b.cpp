#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

void solve(){
    int n;
    string s;
    cin >> n >> s;  

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '_') a++;
        else b++;
    }

    int k = b/2 + b%2;
    cout << (b/2) * (k) * a << endl;    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}