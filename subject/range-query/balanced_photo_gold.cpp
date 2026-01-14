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

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
	darvem;
    setIO("bphoto");

    int n;
    cin >> n;

    vector<int> v(n), l(n);
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> v[i];

    ord_set<int> s;    
    for(int i = 0; i < n; i++){
        int b = i - s.order_of_key(v[i]);
        s.insert(v[i]);
        l[i] = b;
    }

    ord_set<int> s2;
    for(int i = n-1; i>=0; i--){
        int e = n - i - 1;
        int b = e - s2.order_of_key(v[i]);

        int x = min(l[i], b);
        int y = max(l[i], b);
        
        if(y > 2*x) ans++;        
        s2.insert(v[i]);
    }
    cout << ans << endl;
}