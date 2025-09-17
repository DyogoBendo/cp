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

int constant_op(int x){    
    int tmp = x;
    x <<= 1;
    x ^= tmp;
    x ^= 1;
    return x;
}

int no_constant_op(int x){
    x >>= 1;
    return x;
}

signed main(){
    darvem;
    int n;
    cin >> n;

    int curr = 0, x;
    for(int i = 0; i <= n; i++){
        curr <<= 1;
        cin >> x;        
        curr ^= x;
    }
    
    int ans = 0;
    while(curr != 1){
        ans++;
        if(curr%2) curr = constant_op(curr);
        else curr = no_constant_op(curr);
    }

    cout << ans << endl;
}