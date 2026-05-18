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
    string s;
    cin >> s;
    int n = sz(s);
    dbg(s);
    string tmp;

    string curr = "";
    for(int i = 0; i < n; i++){
        if(s[i] == '4') continue;
        else if(s[i] == '1' or s[i] == '3') curr += s[i];
        else{
            if(sz(curr) and (curr.back() == '1' or curr.back() == '3'));
            else curr += '2';
        }
    }

    cout << sz(s) - sz(curr) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}