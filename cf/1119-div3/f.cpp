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
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> v2;
    int l = 0;
    while(l < n and v[l] == 0) l++;

    int r = n-1;
    while(r >= 0 and v[r] == 1) r--;

    for(int i = l; i <= r; i++) v2.push_back(v[i]);

    ll t1 = 0, t0 = 0;
    ll tot = 0;        
    vector<int> one_before(sz(v2));
    for(int i = 0; i < sz(v2); i++){
        one_before[i] = t1;
        if(v2[i] == 1) t1++;                    
        else{            
            t0++;
            tot += t1;
        }         
    } 

    vector<int> zero_after(sz(v2) + 1);
    int c0 = 0, c1 = 0;
    for(int i = sz(v2) - 1; i >= 0; i--){
        if(v2[i] == 1) c1++;                    
        else c0++;                         
        zero_after[i] = c0;
    }

    string s;
    cin >> s;

    cout << tot << " ";

    int r0 = 0,r1 = 0;
    
    int o = 0, z = sz(v2) - 1;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            if(o < sz(v2)){
                tot -= max(0, zero_after[o] - r0);
                r1++;
                o++;
            } 
            while(o < sz(v2) and v2[o] == 0) o++;

        } else{
            if(z >= 0){                
                tot -= max(0, one_before[z] - r1);            
                r0++;            
                z--;
            } 
            while(z >= 0 and v2[z] == 1) z--;
        }
        cout << tot << " ";
    }
    cout << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}