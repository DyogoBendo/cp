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

    int mx = 0;

    vector<int> v(n);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mx = max(x, mx);
        v[i] = x;
    }

    sort(v.rbegin(), v.rend());

    int lo = 0, hi = mx + 10;
    
    auto check = [&](int x){
        vector<int> ap(x);

        vector<int> can_use;


        for(int i = 0; i < n; i++){
            int r = (v[i] - 1 )/ 2;
            if(v[i] < x and !ap[v[i]]) ap[v[i]] = 1;
            else can_use.push_back(r);
        }

        int i = 0;
        for(int j = x-1; j >= 0; j--){
            if(!ap[j]){
                if(i < sz(can_use) and can_use[i] >= j)ap[j] = 1, i++;
                else return false;
            }
        }
        return true;
    };

    while(lo < hi){
        int m = (hi - lo) / 2 + lo;

        if(check(m)) lo = m+1;
        else hi = m; 
    }

    cout << hi-1 << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}