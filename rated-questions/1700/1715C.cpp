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

int n, m;
ll calc(ll x){
    ll ans = (n - x ) * (x + 1);    
    return ans;
}

ll calc2(ll x){
    ll ans = (n - x );    
    return ans;
}

void solve(){
    cin >> n >> m;

    vector<int> a(n), b(n);

    for(int i = 0; i < n; i++) cin >> a[i];

    int prev = -1;   
    ll tot = 0; 
    for(int i = 0; i < n; i++){
        if(a[i] != prev){
            prev = a[i];
            b[i] = 1;
            tot += calc(i);
        } else{
            tot += calc2(i);
        }
    }

    dbg(tot);

    while(m--){
        int i, x;
        cin >> i >> x;

        i--;
        
        prev = -1;
        a[i] = x;
        if(i > 0) prev = a[i-1];
        for(int j = i; j < i+2; j++){
            if(prev != a[j]){
                if(b[j] == 0){
                    b[j] = 1;
                    tot -= calc2(j);
                    tot += calc(j);
                }
            } else{
                if(b[j] == 1){
                    b[j] = 0;
                    tot -= calc(j);
                    tot += calc2(j);
                }
            }
            prev = a[j];
        }
        cout << tot << endl;
    }
}


signed main(){
    darvem;
    int t = 1;
    //cin >> t;

    while(t--) solve();
}