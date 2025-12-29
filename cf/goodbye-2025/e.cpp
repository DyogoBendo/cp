#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double
#define int long long

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

int query(int l, int r){
    int x;
    cout << "? " << l << " " << r << endl;
    cin >> x;
    return x;
}

// saber em qual posição que a e b se concatenaram, sabendo que a soma de a+b = 2*s
int get_m(int l, int r, int s){
    int a = l, b = r;

    while(a <= b){
        int m = (b - a) / 2 + a;
        int x = query(l, m);

        if(x == s) return m;
        if(x > s) b = m;
        else a = m+1;
    }

    return a+1;
}

void answer(int x){
    cout << "! " << x << endl;
}

void solve(){
    int n;
    cin >> n;

    int s = query(1, n);

    int l = 1, r = n;
    while(l < r){
        int m = get_m(l, r, s/2);

        int diff_l = m - l + 1;
        int diff_r = r - m;
        
        if(diff_l < diff_r) r = m;
        else l = m+1;
        s/=2;
    }

    answer(query(l, l));
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}