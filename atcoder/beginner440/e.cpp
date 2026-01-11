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
    int n, k, x;
    cin >> n >> k >> x;
    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());

    priority_queue<pair<ll, vector<int>>> pq;

    set<vector<int>> s;

    vector<int> b(n);
    b[0] = k;
    ll tot = v[0]*k;    
    pq.push({tot, b});
    s.insert(b);

    int cnt = 0;
    while(!pq.empty() && cnt < x){        
        auto [sum, y] = pq.top(); pq.pop();
        cnt++;

        cout << sum << endl;

        for(int i = 0; i < n-1; i++) if(y[i]){
            y[i]--;
            y[i+1]++;

            if(s.find(y) == s.end()){
                pq.push({sum - v[i] + v[i+1], y});
                s.insert(y);
            }
            y[i]++;
            y[i+1]--;            
        }
    }
}


signed main(){
    darvem;
    int t = 1;

    while(t--) solve();
}