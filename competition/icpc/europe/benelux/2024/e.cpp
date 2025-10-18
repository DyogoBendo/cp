#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) (a).size())
#define ld long double

void dbg_out(string s) {  cerr << endl; }
template<typename H, typename...T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int a, b, n;

int query(int x){
    cout << "? " << x << endl;
    cin >> x;
    return x;
}


int solve(int look){
    int l = 2, r = n;
    while(l < r){
        int m = (r - l) / 2 + l;        
        
        int x = query(m);                

        if((x <= look )){
            l = m+1;
        }
        else {
            r = m;
        }
    }
    return r;
}

signed main(){
    fastio;    
    cin >> n;
    
    a = query(1);
    b = query(n);

    int m = (a+b) / 2;    
    int u = solve(m);
    int d = u - 1;

    int xu = query(u);
    int xd = query(d);

    int ans;
    if(u == n) ans = d;
    else if(d == 1) ans = u;
    else{
        if(max(xu - a, b - xu) < max(xd - a, b - xd)) ans = u;
        else ans = d;
    }    

    cout << "! 1 " << ans << " " << n << endl; 

}