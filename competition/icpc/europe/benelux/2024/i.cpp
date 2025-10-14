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

const ll INF = 1e18;

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> travel(n);
    for(int i = 0; i < n; i++) cin >> travel[i].first >> travel[i].second;
    vector<int> diff(n-1);    

    vector<tuple<int, int, int>> interrail(k);
    vector<vector<int>> go(k, vector<int>(n));
    for(int i = 0; i < k; i++){
        int p, d, c;
        cin >> p >> d >> c;

        interrail[i] = {p, d, c};

        int l = 0, r = 1;
        while(l < n){
            int dst = travel[r].first - travel[l].first;
            dbg(l, r, dst, p);

            if(dst < p){
                if(r < n-1) r++;
                else{
                    go[i][l] = min(n, l + d);
                    l++;
                } 
            } 
            else{
                go[i][l] = min(r, l + d);
                l++;
            }
        }   
    }

    vector<ll> dp(n+1, INF);
    dp[0] = 0;

    for(int i = 0; i < n; i++){
        dbg(i, dp[i]);
        dp[i+1] = min(dp[i+1], dp[i] + travel[i].second);
        for(int j = 0; j < k; j++){
            dbg(j);
            dp[go[j][i]] = min(dp[go[j][i]], (ll) dp[i] + get<2>(interrail[j]));
        }
    }

    cout << dp[n] << endl;

}