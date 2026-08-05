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

const int MAXN = 1e6 + 10;
int cnt[MAXN];

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
        
    for(int i = 0; i < n; i++){
        cnt[v[i]]++;        
    }

    map<int, int> mp;
    for(int i = 1; i < MAXN; i++) if(cnt[i]) mp[cnt[i]]++;


    while(q--){
        int t;
        cin >> t;        
        if(t == 1){
            int i, y;
            cin >> i >> y;
            i--;
            int color = v[i];

            mp[cnt[color]]--;
            cnt[color]--;    
            if(cnt[color] > 0) mp[cnt[color]]++;

            if(cnt[y] > 0) mp[cnt[y]]--;            
            cnt[y]++;
            mp[cnt[y]]++;
            
            v[i] = y;            
        } else{
            int x;
            cin >> x;
            int ans = 0;
            for(auto [a, b] : mp) if(a % x == 0) ans += b;
            cout << ans << endl;
        }
    }
}