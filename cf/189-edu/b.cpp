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

    bool found = false;
    int r = 0;
    for(int i = 0; i < sz(s) - 1; i++){
        if(s[i] == s[i+1]){
            r = i+1;
            found= true;
            break;
        }
    }

    if(!found){
        cout << "YES" << endl;
        return;
    }

    found = false;
    int r2 = 0;
    for(int i = r; i < sz(s) -1; i++){
        if(s[i] == s[i+1]){
            r2 = i+1;
            found = true;            
            break;
        }
    }    

    if(!found){
        cout << "YES" << endl;
        return;
    }

    for(int i = r2; i < sz(s)-1; i++){
        if(s[i] == s[i+1]){
            cout << "NO" << endl;
            return;
        }
    }    

    bool inver = false;
    if(s[r-1] == s[r2-1]){
        inver = true;
    }

    if((s[r] != s[r2] and inver) or (s[r] == s[r2] and !inver) ){
        cout << "NO" << endl;
    } else cout << "YES" << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}