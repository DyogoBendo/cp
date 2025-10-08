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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
	using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

const int MAXN = 30 + 1;
const int MAXK = MAXN*(MAXN-1)/2;

int dp[MAXN][MAXK];

int calc(int x){
    return (x)*(x-1) / 2;
}

void init(){
    dp[0][0] = 1;    
    for(int i = 0; i<MAXN; i++){                
        for(int j = 0; j < MAXK; j++){
            if(!dp[i][j]) continue;
            for(int k = 1; k + i < MAXN; k++){
                dp[i+k][j + calc(k)] = k;
            }
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    int tot = calc(n) - k;    
    dbg(n, k);

    if(!dp[n][tot]) cout << 0 << endl;
    else{
        int st = 1;
        vector<int> ans(n);
        int curr = dp[n][tot];
        int en = n;
        while(en){
            dbg(en, curr);
            for(int i = 0; i < curr; i++){
                ans[en-curr+i] = st+i;
            }
            en -= curr;
            st += curr;
            tot -= calc(curr);
            curr = dp[en][tot];
        }
        for(int i = 0; i < n; i++) cout << ans[i] << ' ';
        cout << endl; 
    }
}


signed main(){
    darvem;

    init();

    int t = 1;
    cin >> t;

    while(t--) solve();
}