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

int dp[MAXN][MAXK][MAXN];
int ndp[MAXN][MAXK];

bool check_inversion(int l, int r, vector<int> &v){
    ord_set<int> os;    
    for(int i = l; i <= r; i++){
        if(os.order_of_key(v[i])) return true;        
        os.insert(v[i]);
    }    
    return false;
}

int calc_inversion_value(vector<int> &v){
    int ans = 0;
    for(int i = 0; i < sz(v); i++){
        for(int j = i + 1; j < sz(v); j++){
            ans += check_inversion(i, j, v);
        }
    }
    return ans;
}

void init(){
    for(int i = 1; i<MAXN; i++){
        dbg(i);
        vector<int> visited((i + 1)*(i) /2);
        queue<pair<int, vector<int>>> q;
        vector<int> v(i);
        iota(v.begin(), v.end(), 1);
        q.push({0, v});
        visited[0] = 1;
        while(!q.empty()){
            auto [curr, u] = q.front(); q.pop();                        
            dbg(i, curr);

            ndp[i][curr] = 1;
            for(int j = 0; j < i; j++) dp[i][curr][j] = u[j];

            for(int a = 0; a < i; a++){
                for(int b = a + 1; b < i; b++){
                    swap(v[a], v[b]);
                    int x = calc_inversion_value(v);

                    if(!visited[x]){
                        dbg(a, b, x);
                        visited[x] = 1;
                        q.push({x, v});
                    }

                    swap(v[a], v[b]);
                }
            }
        }

    }
}

void solve(){
    int n, k;
    cin >> n >> k;

    if(!ndp[n][k]) cout << -1 << endl;
    else{
        for(int i = 0; i < n; i++) cout << dp[n][k][i] << ' ';
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