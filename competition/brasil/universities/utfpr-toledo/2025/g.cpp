#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

#define DEBUG

void debug_out(string s, int line) { cerr << endl; }
template<typename H, typename... T>
void debug_out(string s, int line, H h, T... t){
    if (s[0] != ',') cerr << "Line(" << line << ") ";
    do{ cerr << s[0]; s = s.substr(1);
    } while (s.size() and s[0] != ',');
    cerr << " = " << h;
    debug_out(s, line, t...);
}

#ifdef DEBUG
#define dbg(...) debug_out(#__VA_ARGS__, __LINE__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int n, p, k;

ll fat[15];

ll comb(int n, int k){
    ll ans = 1;
    for (ll i = n; i > max(k, n - k); i --)
    {
        ans *= i;
    }
    return ans / fat[min(k, n - k)];
}


void calc(vector<int> &v, int st, int tot = 0){
    if(v.size() == p){                
        for(int i = 0; i < p; i++){
            cout << v[i];
            if(i < p - 1) cout << " ";
        } 
        cout << endl;        
        return;
    }

    if(st <= 0) return;    
    for(int i = p - sz(v); i <= st; i++){
        int curr = comb(i - 1, p - sz(v) - 1);
        if(tot + curr >= k){
            v.push_back(i);
            calc(v, i - 1, tot);        
            break;
        } else{
            tot += curr;
        }
         
    }
}

void solve(){
    cin >> n >> p >> k;

    vector<int> v;
    calc(v, n);         
}

signed main(){
    fat[0] = 1;
    for(ll i = 1; i < 15; i++) fat[i] = fat[i - 1] * i;
    fastio;
    int t=1;

    //cin >> t;
    for (int i=0; i<t; i++) solve();
}