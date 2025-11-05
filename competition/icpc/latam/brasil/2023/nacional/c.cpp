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

ll ha(vector<int> &v){
    ll MOD = 1e9+7;
    ll p = 10000019;
    ll curr = 0;
    for(int i = 1; i < sz(v); i++){        
        assert(v[i] < p);
        dbg(i, v[i]);   
        curr = (curr * p + v[i]) % MOD;        
    }
    assert(curr >= 0);
    dbg(curr);
    return curr;
}

ll ha2(vector<int> &v){
    ll MOD = 1e9+9;
    ll p = 10000079;
    ll curr = 0;
    for(int i = 1; i < sz(v); i++){        
        assert(v[i] < p);
        dbg(i, v[i]);   
        curr = (curr * p + v[i]) % MOD;        
    }
    assert(curr >= 0);
    dbg(curr);
    return curr;
}

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) cin >> v[i];

    if(k*k < n){        
        vector<int> curr(k+1);
        map<pair<ll, ll>, int> ap;
        int cnt0=k;
        int ans = 0;
        ap[make_pair(ha(curr), ha2(curr))] = 1;
        for(int i = 1; i<=n; i++){
            if(!curr[v[i]]) cnt0--;
            curr[v[i]]++;

            if(cnt0 == 0){
                for(int j = 1; j<=k; j++){
                    curr[j]--;                
                    if(curr[j] == 0) cnt0++;
                } 
            }           
            ll h = ha(curr);
            ll h2 = ha2(curr);
            if(ap[{h, h2}]) ans = max(ans, i - ap[{h, h2}]+1);
            else ap[{h, h2}] = i+1;
        }
        cout << ans << endl;
    } else{
        int ans = 0;                
        for(int i=k; i <=n; i += k){           
            vector<int> cnt(k+1);             
            bool found = false;
            int s = i/k;       
            int bigger = 0;
            for(int j = 1; j <= i; j++) cnt[v[j]]++;                            
            for(int j = 1; j<= k; j++) if(cnt[j] > s) bigger++;                        
            if(!bigger) found = true;
            for(int j = i+1; j<= n and !found; j++){
                int l = v[j-i];
                if(cnt[l] == s + 1) bigger--;
                cnt[l]--;

                int r= v[j];
                if(cnt[r] == s) bigger++;
                cnt[r]++;

                if(!bigger) found = true;
            }
            if(found) ans = i;
            
        }
        cout << ans << endl;
    }
}