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


bool check_increasing(vector<int> &v, int st = 0){
    for(int i = st; i < sz(v) - 1; i++) if(v[i] > v[i+1]) return false;
    return true;
}
bool check_decreasing(vector<int> &v, int st = 0){
    for(int i = st; i < sz(v) - 1; i++) if(v[i] < v[i+1]) return false;
    return true;
}

bool check_pyramid(vector<int> &v){
    if(check_decreasing(v)) return true;
    if(check_increasing(v)) return true;

    int lst = 0;
    for(int i = 1; i < sz(v); i++){
        if(v[i] < v[i-1]) break;
        lst = i;
    }

    return check_decreasing(v, lst);    
}


signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    map<int, int> mp;
    
    for(int i = 0; i < n; i++) cin >> v[i];            
    for(int i = 0; i < n; i++) mp[v[i]] = i;            

    vector<int> v2 = v;

    ll ans = 1e9;

    sort(v2.begin(), v2.end());

    do
    {
        if(!check_pyramid(v2)) continue;

        ord_set<int> s;

        ll tot = 0;
        for(int i = 0; i < n; i++){
            int original = mp[v2[i]];        
            int add = (sz(s) - s.order_of_key(original));            
            tot += add;
            s.insert(original);            
        }
        if(tot < ans){
            cout << tot << endl;
            for(auto a : v2) cout << a << " ";
            cout << endl;
        }
        ans = min(ans, tot);

    } while (next_permutation(v2.begin(), v2.end()));
    

    cout << ans << endl;
}