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

int curr = 765;

int get_test(int a, int b){
    dbg(a, b, curr);
    if(a >= curr) a++;
    if(b >= curr) b++;
    dbg(a, b);
    return a*b;
}

int query(int a, int b){
    cout << "? " << a << " " << b << endl;
    int ans = get_test(a, b);
    cin >> ans;    
    if(ans == a*b) return 2; // ambos estão certos, precisamos olhar no ultimo terco
    if(ans == a*(b+1)) return 1;
    if(ans == (a+1) * (b+1)) return 0;
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    dbg(curr);
    int l = 2, r = 999;
    int sz = r - l;
    while(sz && l < r){
        sz/= 3;
        dbg(l, r, sz);
        if(l + sz > r-sz){
            l = r;
            break;
        } 
        int c = query(l + sz, r - sz);
        if(c == 0) r = l + sz;
        else if(c == 1) l += sz + 1, r -= sz;
        else l = r - sz;       
        dbg(c, l, r);
    }    
    if(r - l == 1)l++;    
    answer(l);
    //assert(l == curr);
}


signed main(){    
    int t = 1000;
    cin >> t;

    while(t--){        
        solve();
    } 
}