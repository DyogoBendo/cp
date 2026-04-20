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

signed main(){
    darvem;

    string s;
    cin >> s;

    ld ans = 0;
    ld curr = 1;
    ld tot = 0;
    for(int i = 0; i < sz(s); i++){
        tot *= 10;
        tot += s[i] - '0';        
        ans += 0.9*curr*(tot);
        curr *= 0.1;        
    }
    ans += (tot * curr);
    cout << setprecision(15) <<  ans << endl;
}