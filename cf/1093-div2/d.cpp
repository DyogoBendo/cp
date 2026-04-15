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

int n;
int query(vector<int> &v){
    cout << "? " << sz(v);
    for(auto x : v) cout << " " << x;
    cout << endl;

    int ans;
    cin >> ans;
    return ans;
}
void ans(int x, int y, int z){
    cout << "! " << x << " " << y << " " << z << endl;
}

int has3(int k, int ans){
    int rep = k - ans;

    dbg(rep);

    return rep % 2;
}

int find_r(){
    int lo = 1, hi = n;    

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;
        
        vector<int> v(m);
        iota(v.begin(), v.end(), 1);

        if(has3(m, query(v))){
            hi = m;
        } else{
            lo = m + 1;
        }
    }
    return hi;
}

int find_l(){
    int lo = 1, hi = n;

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;
        int tam = n - m + 1;        

        vector<int> v(tam);
        iota(v.begin(), v.end(), m);

        if(has3(tam, query(v))){
            lo = m + 1;
        } else{
            hi = m;
        }
    }
    return hi - 1;
}

int find_mid(int l, int r){
    int lo = l+1, hi = r-1;

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;
        int tam = m - l + 2;

        vector<int> v(tam);
        iota(v.begin(), v.end(), l);
        v[tam-1] = r;

        if(has3(tam, query(v))){
            hi = m;
        } else{
            lo = m + 1;
        }
    }
    return hi;
}

void solve(){
    cin >> n;    
    n <<= 1;
    n++;    

    int l = find_l();
    int r = find_r();
    dbg(l, r);
    int mid = find_mid(l, r);

    ans(l, mid, r);
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}