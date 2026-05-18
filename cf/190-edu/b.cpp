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
    int ans = 0, n = sz(s);
    dbg(s);
    string tmp;
    for(int i = 0; i < n; i++){
        if(s[i] == '4') ans++;
        else tmp += s[i];
    }

    vector<int> v;
    int prev = 0, cnt = 0;
    for(int i = 0; i < sz(tmp); i++){
        if(tmp[i] == '2'){
            if(prev == 0) cnt++;
            else v.push_back(cnt), cnt = 1, prev = 0;
        } else{
            if(prev != 0) cnt++;
            else v.push_back(cnt), cnt = 1, prev = 1;
        }
    }
    v.push_back(cnt);
    if(sz(v) % 2) v.push_back(0);

    vector<int> prefix;
    int bst= 1e9;
    prefix.push_back(0);
    for(int i = 1; i < sz(v)-1; i+=2){
        prefix.push_back(prefix.back() + v[i]);
    }

    vector<int> sufix;  
    sufix.push_back(0);
    for(int i = sz(v) - 2; i > 0; i-=2){
        sufix.push_back(sufix.back() + v[i]);
    }
    reverse(sufix.begin(), sufix.end());

    for(int i = 0; i < sz(prefix); i++){
        bst = min(bst, prefix[i] + sufix[i]);
    }

    cout << ans + bst << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}