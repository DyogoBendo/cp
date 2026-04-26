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

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    vector<int> v2 = v;
    sort(v2.begin(), v2.end());

    int m = v2[n/2];

    vector<int> dp(n);

    for(int i = 0; i < n; i++){        
        int l = 0, r = 0, e = 0;
        for(int j = i; j < n; j++){            
            int tam = j - i + 1;
            if(v[j] < m) l++;
            else if(v[j] > m) r ++;
            else e ++;
            if(tam % 2 == 0)continue;                                    
            if(abs(r - l) >= e) continue;
        
            if(i == 0) dp[j] = max(dp[j], 1);
            else if(dp[i-1] > 0) dp[j] = max(dp[j], dp[i-1] + 1);                
        }
    }
    
    cout << dp[n-1] << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}