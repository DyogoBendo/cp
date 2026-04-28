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

#define int ll

signed main(){
    darvem;

    ll n, t;
    cin >> n >> t;
    vector<ll> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];        

    ll steps = 0;
    int tot = 0;

    vector<ll> executed(n);

    for(ll i = 0;  steps + (1LL << i) <= t and 2*i < n; i++){
        tot ++;

        ll p2 = (1LL << i);
        
        if(v[2*i] == 0) continue; 
        
        for(int j = 0; j < i; j++) executed[j] += p2;
        steps += p2;
        
        
        ll curr_stones = 1;
        for(int j = 2*i; j < n; j++){
            if(curr_stones == 1){
                if(v[j] == 0){
                    v[j] = 1;
                    break;
                } else{
                    curr_stones += v[j];
                    v[j] = 0;                    
                }
            } else v[j]++, curr_stones--;
        }
    }    
    
    ll remaining = t - steps;
    dbg(steps);
    for(int i = 0; i < tot; i++){
        int p2 = (1LL << (i+1));
        int pos = 2*i;

        dbg(i, i+1, p2);
        if(remaining % p2 >= p2/2) v[pos] = 1;
        if(pos+1 < n) v[pos+1] += executed[i] / p2 +  remaining / p2;
    }

    for(int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}