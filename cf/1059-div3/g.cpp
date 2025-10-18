#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

void solve(){
    int n;
    cin >> n;

    if(n == 2) cout << -1 << endl;
    else if(n==3) cout << "1 3\n2 3\n";
    else if(n==4) cout << "1 2\n3 1\n4 1" << endl;
    else{
        cout << "1 2\n2 3\n3 4\n";
        for(int i = 5; i < n; i++) cout << "2 " << i << endl;
        cout << "1 " << n << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}