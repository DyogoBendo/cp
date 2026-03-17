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

const int MOD =  998244353;

signed main(){
    darvem;

    string s;
    cin >> s;
    int n = sz(s);

    ll sum_odd = 0;
    ll sum_even = 0;

    ll dp_odd = 0;
    ll dp_even = 1;    
    for(int i = 0; i < n; i++){        
                
        if(s[i] != '0'){
            sum_even = (sum_even + dp_even) % MOD;
            sum_odd = (sum_odd + dp_odd) % MOD;
        }

        ll new_dp_odd = sum_even;
        ll new_dp_even = sum_odd;
        
        if(s[i] == '0'){
            new_dp_even = (new_dp_even + dp_odd) % MOD;
            new_dp_odd = (new_dp_odd + dp_even) % MOD;
        }
        dp_even = new_dp_even;
        dp_odd = new_dp_odd;
    }   

    cout << dp_even << endl;
}