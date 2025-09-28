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
    int n, m;    
    cin >> n >> m;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    sort(b.rbegin(), b.rend());

    int i = 0, j = 0;
    while(i < n and j < m){
        if(a[i] > b[j]){
            cout << a[i] << " ";
            i++;
        } else{
            cout << b[j] << " ";
            j++;
        }
    }
    while(i < n){
        cout << a[i] << " ";
        i++;
    }
    while(j < m){
        cout << b[j] << " ";
        j++;
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}