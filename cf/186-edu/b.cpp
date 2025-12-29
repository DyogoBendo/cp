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

int check(int a, int b){
    int curr = 0;
    int x = 1;

    int ans=0;
    while(1){
        if(curr == 0){
            a -= x;
            if(a  < 0) break;
        } else{
            b -= x;
            if(b < 0) break;
        }
        x *= 2;
        ans++;
        curr ^= 1;
    }
    return ans;
}

void solve(){
    int a, b;
    cin >> a >> b;

    cout << max(check(a, b), check(b, a)) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}